/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "rse_asn1_encoding.h"
#include "crypto.h"
#include "cc3xx_drv.h"

/* ASN1 definitions */
#define ASN1_INTEGER_POSITIVE           (0x00)
#define ASN1_BOOLEAN                    (0x01)
#define ASN1_INTEGER                    (0x02)
#define ASN1_BIT_STRING                 (0x03)
#define ASN1_OCTET_STRING               (0x04)
#define ASN1_NULL                       (0x05)
#define ASN1_OBJECT_IDENTIFIER          (0x06)
#define ASN1_UTF8_STRING                (0x0C)
#define ASN1_PRINTABLE_STRING           (0x13)
#define ASN1_TELETEX_STRING             (0x14)
#define ASN1_IA5_STRING                 (0x16)
#define ASN1_UTC_TIME                   (0x17)
#define ASN1_GENERALIZED_TIME           (0x18)
#define ASN1_SEQUENCE                   (0x30)
#define ASN1_SET                        (0x31)
#define ASN1_CONTEXT_IMPLICIT_0         (0x80)
#define ASN1_CONTEXT_0                  (0xA0)
#define ASN1_CONTEXT_3                  (0xA3)

/* Object identifier definitions */
/* From ANSI X9.62 / SEC 2: Recommended Elliptic Curve Domain Parameters */
#define OID_SECP256R1                   \
    { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 }  /* 1.2.840.10045.3.1.7 (P-256) */
#define OID_SECP384R1                   \
    { 0x2B, 0x81, 0x04, 0x00, 0x22 }                    /* 1.3.132.0.34 (P-384) */

/* From ANSI X9.62: Public Key and Signature OIDs */
#define OID_ID_EC_PUBLIC_KEY            \
    { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 }        /* 1.2.840.10045.2.1 (id-ecPublicKey) */
#define OID_ECDSA_WITH_SHA384           \
    { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x03 }  /* 1.2.840.10045.4.3.3 */

/* From X.500 / LDAP / ITU-T X.520 Attribute Type Definitions */
#define OID_COMMON_NAME                 { 0x55, 0x04, 0x03 } /* 2.5.4.3 (commonName) */
#define OID_SERIAL_NUMBER               { 0x55, 0x04, 0x05 } /* 2.5.4.5 (serialNumber) */
#define OID_ORGANISATION                { 0x55, 0x04, 0x0A } /* 2.5.4.10 (organizationName) */

/* From RFC 5280 (PKIX) Certificate Extensions */
#define OID_KEY_USAGE                   { 0x55, 0x1D, 0x0F } /* 2.5.29.15 (keyUsage) */
#define OID_AUTHORITY_KEY               { 0x55, 0x1D, 0x23 } /* 2.5.29.35 (authorityKeyIdentifier) */
#define OID_BASIC_CONSTRAINTS           { 0x55, 0x1D, 0x13 } /* 2.5.29.19 (basicConstraints) */

/* Boolean values */
#define BOOLEAN_TRUE                    (0xFF)
#define BOOLEAN_FALSE                   (0x00)

/* ECDSA-384 definitions */
#define ECDSA_384_SIGNATURE_R_PART_SIZE     (48)
#define ECDSA_384_SIGNATURE_S_PART_SIZE     (48)
#define ECDSA_384_PUBLIC_KEY_X_SIZE         (48)
#define ECDSA_384_PUBLIC_KEY_Y_SIZE         (48)

/* SHA_384 definitions */
#define SHA_384_HASH_SIZE                   (48)

/* ECDSA-256 definitions */
#define ECDSA_256_PUBLIC_KEY_X_SIZE         (32)
#define ECDSA_256_PUBLIC_KEY_Y_SIZE         (32)

/* IAK certificate definitions - can be safely tweaked if required */
#define ISSUER_ORGANISATION_NAME                        "Arm"
#define ISSUER_COMMON_NAME                              "Arm Endorsement Sub CA"

#define VALIDITY_VALUE_NOT_BEFORE                       "700101000000Z"
#define VALIDITY_VALUE_NOT_AFTER                        "99991231235959Z"

#define SUBJECT_COMMON_NAME                             "Root Attestation Key"

#define EXTENSION_VALUE_DIGITAL_SIGNATURE_UNUSED_BITS   (0x07)
#define EXTENSION_VALUE_DIGITAL_SIGNATURE_VALUE         (0x80)

/* Serial number field is encoded as
 * 0x01 | SOC_INFO_REG (4 bytes) | SoC UID (12 bytes) */
#define SERIAL_NUMBER_LENGTH                            (17)

/* Hex encoded serial number drops the 0x01 */
#define SERIAL_NUMBER_HEX_ENCODED_LENGTH                ((SERIAL_NUMBER_LENGTH - 1) * 2)

#define ENDORSEMENT_CERT_SKI_HEX_ENCODED_LENGTH \
    (ENDORSEMENT_CERT_SKI_LENGTH * 2)

/* Helper macros to generate definitions */
#define STRING_LITERAL_SIZE(_str) sizeof(_str) - 1

#define SIZEOF_STRUCT_EXCLUDING_TL(_struct_name, _tl_name, _tl_struct_name) \
    (sizeof(_struct_name) - offsetof(_struct_name, _tl_name) - sizeof(_tl_struct_name))

#define TL_SMALL_INITIALISER_SIZE(_tag, _size) { .tag = (_tag), .len = (_size) }

#define TL_SMALL_INITIALISER(_tag, _struct_name, _field_name)                             \
    TL_SMALL_INITIALISER_SIZE(_tag, SIZEOF_STRUCT_EXCLUDING_TL(_struct_name, _field_name, \
                                                               struct tl_small_s))

#define TL_SMALL_DEFINE(_tag, _struct_name, _field_name) \
    ._field_name = TL_SMALL_INITIALISER(_tag, _struct_name, _field_name)

#define TL_MID_INITIALISER_SIZE(_tag, _size) { .tag = (_tag), .__ind_char = 0x81, .len = (_size) }

#define TL_MID_INITIALISER(_tag, _struct_name, _field_name)                             \
    TL_MID_INITIALISER_SIZE(_tag, SIZEOF_STRUCT_EXCLUDING_TL(_struct_name, _field_name, \
                                                             struct tl_small_s))

#define TL_MID_DEFINE(_tag, _struct_name, _field_name) \
    ._field_name = TL_MID_INITIALISER(_tag, _struct_name, _field_name)

#define TL_LARGE_INITIALISER_SIZE(_tag, _size) \
    { .tag = (_tag),                           \
      .__ind_char = 0x82,                      \
      .len_high = (((_size) >> 8) & 0xFF),     \
      .len_low = ((_size) & 0xFF) }

#define TL_LARGE_INITIALISER(_tag, _struct_name, _field_name)                             \
    TL_LARGE_INITIALISER_SIZE(_tag, SIZEOF_STRUCT_EXCLUDING_TL(_struct_name, _field_name, \
                                                               struct tl_large_s))

#define TL_LARGE_DEFINE(_tag, _struct_name, _field_name) \
    ._field_name = TL_LARGE_INITIALISER(_tag, _struct_name, _field_name)

/* Tag-length for lengths <= 0x7F */
struct tl_small_s {
    uint8_t tag;
    uint8_t len;
};

/* Tag-length for lengths > 127 and < 256 - __ind_char = 0x81 */
struct tl_mid_s {
    uint8_t tag;
    uint8_t __ind_char;
    uint8_t len;
};

/* Tag-length for lengths >= 256 - __ind_char = 0x82 */
struct tl_large_s {
    uint8_t tag;
    uint8_t __ind_char;
    uint8_t len_high;
    uint8_t len_low;
};

struct version_int_s {
    struct tl_small_s tag_length;
    uint8_t data;
};

struct explicit_version_s {
    struct tl_small_s tag_length;
    struct version_int_s version_int;
};

struct serial_number_s {
    struct tl_small_s tag_length;
    uint8_t data[SERIAL_NUMBER_LENGTH];
};

struct hex_encoded_serial_number_s {
    struct tl_small_s tag_length;
    uint8_t data[SERIAL_NUMBER_HEX_ENCODED_LENGTH];
};

struct oid_8_bytes_s {
    struct tl_small_s tag_length;
    uint8_t data[8];
};

struct oid_7_bytes_s {
    struct tl_small_s tag_length;
    uint8_t data[7];
};

struct oid_5_bytes_s {
    struct tl_small_s tag_length;
    uint8_t data[5];
};

struct oid_3_bytes_s {
    struct tl_small_s tag_length;
    uint8_t data[3];
};

struct null_s {
    struct tl_small_s tag_length;
};

struct signature_algorithm_identifier_s {
    struct tl_small_s tag_length;
    struct oid_8_bytes_s algorithm_oid;
};

struct cn_endorsement_ca_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s cn_oid;
    struct tl_small_s str_length;
    uint8_t data[STRING_LITERAL_SIZE(ISSUER_COMMON_NAME)];
};

struct organisation_arm_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s organisation_oid;
    struct tl_small_s str_length;
    uint8_t data[STRING_LITERAL_SIZE(ISSUER_ORGANISATION_NAME)];
};

struct serial_number_set_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s subject_serial_oid;
    struct serial_number_s serial_number;
};

struct hex_encoded_serial_number_set_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s subject_serial_oid;
    struct hex_encoded_serial_number_s hex_encoded_serial_number;
};

struct hex_encoded_endorsement_ski_s {
    struct tl_small_s tag_length;
    uint8_t data[ENDORSEMENT_CERT_SKI_HEX_ENCODED_LENGTH];
};

struct hex_encoded_endorsement_ski_set_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s subject_serial_oid;
    struct hex_encoded_endorsement_ski_s hex_encoded_endorsement_ski;
};

struct issuer_name_s {
    struct tl_small_s tag_length;
    struct organisation_arm_s organisation_arm;
    struct hex_encoded_endorsement_ski_set_s endorsement_ski;
    struct cn_endorsement_ca_s cn_endorsement;
};

struct utc_time_s {
    struct tl_small_s tag_length;
    uint8_t data[0xD];
};

struct generalised_time_s {
    struct tl_small_s tag_length;
    uint8_t data[0xF];
};

struct validity_s {
    struct tl_small_s tag_length;
    struct utc_time_s not_valid_before;
    struct generalised_time_s not_valid_after;
};

struct root_attestation_cert_s {
    struct tl_small_s set_length;
    struct tl_small_s sequence_length;
    struct oid_3_bytes_s organisation_oid;
    struct tl_small_s str_length;
    uint8_t data[STRING_LITERAL_SIZE(SUBJECT_COMMON_NAME)];
};

struct subject_s {
    struct tl_small_s tag_length;
    struct hex_encoded_serial_number_set_s hex_encoded_serial_number;
    struct root_attestation_cert_s root_attestation_cert;
};

struct subject_ecdsa384_public_key_info_alg_s {
    struct tl_small_s tag_length;
    struct oid_7_bytes_s algorithm;
    struct oid_5_bytes_s parameters;
};

struct subject_ecdsa256_public_key_info_alg_s {
    struct tl_small_s tag_length;
    struct oid_7_bytes_s algorithm;
    struct oid_8_bytes_s parameters;
};

struct subject_ecdsa384_public_key_info_s {
    struct tl_small_s tag_length;
    struct subject_ecdsa384_public_key_info_alg_s key_info;
    struct tl_small_s key_tag_length;
    uint8_t bit_string_unused_bits;
    /* 0x04 | X | Y */
    uint8_t key[1 + ECDSA_384_PUBLIC_KEY_X_SIZE + ECDSA_384_PUBLIC_KEY_Y_SIZE];
};

struct subject_ecdsa256_public_key_info_s {
    struct tl_small_s tag_length;
    struct subject_ecdsa256_public_key_info_alg_s key_info;
    struct tl_small_s key_tag_length;
    uint8_t bit_string_unused_bits;
    /* 0x04 | X | Y */
    uint8_t key[1 + ECDSA_256_PUBLIC_KEY_X_SIZE + ECDSA_256_PUBLIC_KEY_Y_SIZE];
};

struct extension_data_bool_s {
    struct tl_small_s tag_length;
    uint8_t data;
};

struct key_usage_extension_s {
    struct tl_small_s tag_length;
    struct oid_3_bytes_s key_usage;
    struct extension_data_bool_s critical;
    struct tl_small_s digital_sig_octet_string;
    struct tl_small_s digital_sig_bit_string;
    uint8_t digital_sig_unused_bits;
    uint8_t digital_sig_value;
};

struct authority_key_identifier_s {
    struct tl_small_s tag_length;
    struct oid_3_bytes_s authority_key;
    struct tl_small_s octet_string;
    struct tl_small_s sequence;
    struct tl_small_s context_0;
    uint8_t authority_key_bytes[ENDORSEMENT_CERT_SKI_LENGTH];
};

struct basic_constraints_extension_s {
    struct tl_small_s tag_length;
    struct oid_3_bytes_s basic_constraints;
    struct tl_small_s octet_string;
    struct tl_small_s empty_sequence;
};

struct extensions_s {
    struct tl_small_s tag_length;
    struct tl_small_s sequence;
    struct key_usage_extension_s key_usage;
    struct basic_constraints_extension_s basic_constraints;
    struct authority_key_identifier_s authority_key;
};

struct tbs_certificate_s {
    struct tl_large_s tag_length;
    struct explicit_version_s explicit_version;
    struct serial_number_s serial_number;
    struct signature_algorithm_identifier_s algorithm_identifier;
    struct issuer_name_s issuer_name;
    struct validity_s validity;
    struct subject_s subject;
    struct subject_ecdsa384_public_key_info_s key_info;
    struct extensions_s extensions;
};

struct signature_value_s {
    struct tl_small_s tag_length;
    uint8_t bit_string_unused_bits;
    /* Max size is SEQUENCE + INTEGER + 0x00 + r_part +
     * INTEGER + 0x00 + s_part. Note that the 0x00
     * are only present if the first byte of the integer
     * is >= 0x80 (top bit set) to indicate positive */
    uint8_t signature[2 + 2 + 1 + ECDSA_384_SIGNATURE_R_PART_SIZE + 2 + 1 +
                      ECDSA_384_SIGNATURE_S_PART_SIZE];
};

struct x509_v3_cert_s {
    struct tl_large_s sequence_certificate_tag;
    struct tbs_certificate_s tbs_certificate;
    struct signature_algorithm_identifier_s algorithm_identifier;
    struct signature_value_s signature;
};

/*
 * X.509 Key Endorsement Certificate (KEC) Format
 *
 * This structure defines an X.509 Version 3 certificate used to endorse an Initial Attestation Key (IAK).
 * It conforms to the following specifications:
 *   - RFC 5280: Internet X.509 Public Key Infrastructure Certificate and CRL Profile
 *   - RFC 5480: Elliptic Curve Cryptography Subject Public Key Information
 *   - SEC 2: Recommended Elliptic Curve Domain Parameters
 *   - Arm-specific extensions for endorsement metadata
 *
 * Structure layout:
 *
 * Certificate  ::=  SEQUENCE  {
 *     tbsCertificate       TBSCertificate,
 *     signatureAlgorithm   AlgorithmIdentifier,
 *     signatureValue       BIT STRING
 * }
 *
 * TBSCertificate  ::=  SEQUENCE  {
 *     version               [0] EXPLICIT Version DEFAULT v1,
 *     serialNumber          INTEGER,
 *     signature             AlgorithmIdentifier,
 *     issuer                Name,
 *     validity              Validity,
 *     subject               Name,
 *     subjectPublicKeyInfo SubjectPublicKeyInfo,
 *     extensions            [3] EXPLICIT Extensions OPTIONAL
 * }
 *
 * Name  ::=  SEQUENCE OF RelativeDistinguishedName
 * RDN   ::=  SET OF AttributeTypeAndValue
 *
 * SubjectPublicKeyInfo ::= SEQUENCE  {
 *     algorithm         AlgorithmIdentifier,
 *     subjectPublicKey  BIT STRING
 * }
 *
 * Extensions include:
 *   - keyUsage (2.5.29.15): Indicates allowed key usages (e.g. digitalSignature)
 *   - basicConstraints (2.5.29.19): Marks the certificate as a non-CA
 *   - authorityKeyIdentifier (2.5.29.35): Identifies the signing authority key
 *
 * Arm-specific use:
 *   - issuer includes:
 *       - O (Organization): Fixed to Arm Ltd
 *       - CN: Issuer Common Name (e.g., "Arm Endorsement CA")
 *       - serialNumber: Hex-encoded SKI of the IAK
 *   - subject includes:
 *       - serialNumber: Hex-encoded serial of the device
 *       - CN: Name of the root attestation certificate
 *
 * Public Key:
 *   - Algorithm: id-ecPublicKey (1.2.840.10045.2.1)
 *   - Curve: secp384r1 (1.3.132.0.34)
 *
 * Signature Algorithm:
 *   - ecdsa-with-SHA384 (1.2.840.10045.4.3.3)
 *
 * Notes:
 * - The field in the TBSCertificate has a DEFAULT of v1, but we explictly set it to v3 in the structure.
 * - The structure uses TL_SMALL_DEFINE and TL_LARGE_DEFINE macros to embed ASN.1 tag/length metadata.
 * - Several fields (e.g., serial number, SKI, key, signature) are dynamically populated.
 * - This certificate structure is typically encoded using DER for transmission or embedding in firmware.
 */

static struct x509_v3_cert_s iak_endorsement_certificate = {
    /* Overall tag length is dynamic */
    .tbs_certificate = {
        TL_LARGE_DEFINE(ASN1_SEQUENCE, struct tbs_certificate_s, tag_length),

        .explicit_version = {
            TL_SMALL_DEFINE(ASN1_CONTEXT_0, struct explicit_version_s, tag_length),
            .version_int = {
                TL_SMALL_DEFINE(ASN1_INTEGER, struct version_int_s, tag_length),
                .data = 0x02,
            },
        },

        .serial_number = {
            TL_SMALL_DEFINE(ASN1_INTEGER, struct serial_number_s, tag_length),
            /* Data field is dynamic */
        },

        .algorithm_identifier = {
            TL_SMALL_DEFINE(ASN1_SEQUENCE, struct signature_algorithm_identifier_s, tag_length),
            .algorithm_oid = {
                TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_8_bytes_s, tag_length),
                .data = OID_ECDSA_WITH_SHA384,
            },
        },

        .issuer_name = {
            TL_SMALL_DEFINE(ASN1_SEQUENCE, struct issuer_name_s, tag_length),

            .organisation_arm = {
                TL_SMALL_DEFINE(ASN1_SET, struct organisation_arm_s, set_length),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct organisation_arm_s, sequence_length),
                .organisation_oid = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER,  struct oid_3_bytes_s, tag_length),
                    .data = OID_ORGANISATION
                },
                TL_SMALL_DEFINE(ASN1_UTF8_STRING, struct organisation_arm_s, str_length),
                .data = ISSUER_ORGANISATION_NAME
            },

            .endorsement_ski = {
                TL_SMALL_DEFINE(ASN1_SET, struct hex_encoded_endorsement_ski_set_s, set_length),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct hex_encoded_endorsement_ski_set_s, sequence_length),
                .subject_serial_oid = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER,  struct oid_3_bytes_s, tag_length),
                    .data = OID_SERIAL_NUMBER,
                },
                .hex_encoded_endorsement_ski = {
                    TL_SMALL_DEFINE(ASN1_PRINTABLE_STRING, struct hex_encoded_endorsement_ski_s, tag_length),
                    /* Data field is dynamic */
                }
            },

            .cn_endorsement = {
                TL_SMALL_DEFINE(ASN1_SET, struct cn_endorsement_ca_s, set_length),
                TL_SMALL_DEFINE(ASN1_SEQUENCE,  struct cn_endorsement_ca_s, sequence_length),
                .cn_oid = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER,  struct oid_3_bytes_s, tag_length),
                    .data = OID_COMMON_NAME,
                },
                TL_SMALL_DEFINE(ASN1_UTF8_STRING, struct cn_endorsement_ca_s, str_length),
                .data = ISSUER_COMMON_NAME,
            },
        },

        .validity = {
            TL_SMALL_DEFINE(ASN1_SEQUENCE, struct validity_s, tag_length),
            .not_valid_before = {
                TL_SMALL_DEFINE(ASN1_UTC_TIME, struct utc_time_s, tag_length),
                .data = VALIDITY_VALUE_NOT_BEFORE
            },
            .not_valid_after = {
                TL_SMALL_DEFINE(ASN1_GENERALIZED_TIME, struct generalised_time_s, tag_length),
                .data = VALIDITY_VALUE_NOT_AFTER
            },
        },

        .subject = {
            TL_SMALL_DEFINE(ASN1_SEQUENCE, struct subject_s, tag_length),

            .hex_encoded_serial_number = {
                TL_SMALL_DEFINE(ASN1_SET, struct hex_encoded_serial_number_set_s, set_length),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct hex_encoded_serial_number_set_s, sequence_length),
                .subject_serial_oid = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER,  struct oid_3_bytes_s, tag_length),
                    .data = OID_SERIAL_NUMBER
                },
                .hex_encoded_serial_number = {
                    TL_SMALL_DEFINE(ASN1_PRINTABLE_STRING, struct hex_encoded_serial_number_s, tag_length),
                    /* Data is dynamic field */
                }
            },

             .root_attestation_cert = {
                TL_SMALL_DEFINE(ASN1_SET, struct root_attestation_cert_s, set_length),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct root_attestation_cert_s, sequence_length),
                .organisation_oid = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER,  struct oid_3_bytes_s, tag_length),
                    .data = OID_COMMON_NAME
                },
                TL_SMALL_DEFINE(ASN1_UTF8_STRING, struct root_attestation_cert_s, str_length),
                .data = SUBJECT_COMMON_NAME
            },
        },

        .key_info = {
            TL_SMALL_DEFINE(ASN1_SEQUENCE, struct subject_ecdsa384_public_key_info_s, tag_length),
            .key_info = {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct subject_ecdsa384_public_key_info_alg_s, tag_length),
                .algorithm = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_7_bytes_s, tag_length),
                    .data = OID_ID_EC_PUBLIC_KEY,
                },
                .parameters = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_5_bytes_s, tag_length),
                    .data = OID_SECP384R1,
                }
            },
            TL_SMALL_DEFINE(ASN1_BIT_STRING, struct subject_ecdsa384_public_key_info_s, key_tag_length),
            .bit_string_unused_bits = 0x00,
            /* Key is dynamic field */
        },

        .extensions = {
            TL_SMALL_DEFINE(ASN1_CONTEXT_3, struct extensions_s, tag_length),
            TL_SMALL_DEFINE(ASN1_SEQUENCE,  struct extensions_s, sequence),
            .key_usage = {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct key_usage_extension_s, tag_length),
                .key_usage = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_3_bytes_s, tag_length),
                    .data = OID_KEY_USAGE
                },
                .critical = {
                    TL_SMALL_DEFINE(ASN1_BOOLEAN, struct extension_data_bool_s, tag_length),
                    .data = BOOLEAN_TRUE
                },
                TL_SMALL_DEFINE(ASN1_OCTET_STRING, struct key_usage_extension_s, digital_sig_octet_string),
                TL_SMALL_DEFINE(ASN1_BIT_STRING, struct key_usage_extension_s, digital_sig_bit_string),
                .digital_sig_unused_bits = EXTENSION_VALUE_DIGITAL_SIGNATURE_UNUSED_BITS,
                .digital_sig_value = EXTENSION_VALUE_DIGITAL_SIGNATURE_VALUE
            },

            .basic_constraints  = {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct basic_constraints_extension_s, tag_length),
                .basic_constraints = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_3_bytes_s, tag_length),
                    .data = OID_BASIC_CONSTRAINTS
                },
                TL_SMALL_DEFINE(ASN1_OCTET_STRING, struct basic_constraints_extension_s, octet_string),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct basic_constraints_extension_s, empty_sequence),
            },

            .authority_key = {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct authority_key_identifier_s, tag_length),
                .authority_key = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_3_bytes_s, tag_length),
                    .data = OID_AUTHORITY_KEY
                },
                TL_SMALL_DEFINE(ASN1_OCTET_STRING, struct authority_key_identifier_s, octet_string),
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct authority_key_identifier_s, sequence),
                TL_SMALL_DEFINE(ASN1_CONTEXT_IMPLICIT_0, struct authority_key_identifier_s, context_0),
                /* authority_key_bytes is dynamic field */
            },
        }
    },

    .algorithm_identifier = {
        TL_SMALL_DEFINE(ASN1_SEQUENCE, struct signature_algorithm_identifier_s, tag_length),
        .algorithm_oid = {
            TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_8_bytes_s, tag_length),
            .data = OID_ECDSA_WITH_SHA384,
        },
    },

    /* Whole signature struct is dynamic field */
};

static enum tfm_plat_err_t
verify_params_sizes(struct x509_v3_cert_s *cert,
                    struct rse_asn1_iak_endorsement_cert_provisioned_params_s *provisioned_params,
                    struct rse_asn1_iak_endorsement_cert_dynamic_params_s *dynamic_params)
{
    /* ECDSA-384 signature must by 96 bytes */
    if (provisioned_params->signature_size !=
        (ECDSA_384_SIGNATURE_R_PART_SIZE + ECDSA_384_SIGNATURE_S_PART_SIZE)) {
        return TFM_PLAT_ERR_ASN1_IAK_ENDORSEMENT_SIGNATURE_INVALID_SIZE;
    }

    if (provisioned_params->endorsement_cert_ski_size !=
        sizeof(cert->tbs_certificate.extensions.authority_key.authority_key_bytes)) {
        return TFM_PLAT_ERR_ASN1_IAK_ENDORSEMENT_SKI_INVALID_SIZE;
    }

    /*  0x01 | SOC_INFO_REG | SoC UID */
    if ((1 + sizeof(dynamic_params->soc_info_reg_val) + dynamic_params->soc_uid_size) !=
        sizeof(cert->tbs_certificate.serial_number.data)) {
        return TFM_PLAT_ERR_ASN1_IAK_ENDORSEMENT_SERIAL_NUMBER_INVALID_SIZE;
    }

    if (dynamic_params->rak_pub_size != (sizeof(cert->tbs_certificate.key_info.key) - 1)) {
        return TFM_PLAT_ERR_ASN1_IAK_ENDORSEMENT_KEY_INVALID_SIZE;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static void convert_to_printable_string(uint8_t *out_buf, size_t out_buf_size, uint8_t *in_buf,
                                        size_t in_buf_size)
{
    static const char hex_digits[16] = "0123456789ABCDEF";

    assert(out_buf_size == (in_buf_size * 2));

    for (uint8_t i = 0; i < in_buf_size; i++) {
        out_buf[i * 2] = hex_digits[(in_buf[i] >> 4) & 0x0F];
        out_buf[(i * 2) + 1] = hex_digits[in_buf[i] & 0x0F];
    }
}

static size_t copy_signature_part(uint8_t *out_buf, uint8_t *part, size_t part_size)
{
    uint8_t *out_buf_ptr = out_buf;
    uint8_t *int_len;

    *out_buf_ptr++ = ASN1_INTEGER;
    int_len = out_buf_ptr++;

    /* Top bit of byte = 1 so need byte to indicate the integer is positive */
    if (part[0] >= 0x80) {
        *out_buf_ptr++ = ASN1_INTEGER_POSITIVE;
    }

    memcpy(out_buf_ptr, part, part_size);
    out_buf_ptr += part_size;

    *int_len = out_buf_ptr - (int_len + 1);

    return out_buf_ptr - out_buf;
}

static size_t write_signature(uint8_t *out_buf, uint8_t *r_part, uint8_t *s_part)
{
    uint8_t *out_buf_ptr = out_buf;
    uint8_t *sequence_len;

    *out_buf_ptr++ = ASN1_SEQUENCE;
    sequence_len = out_buf_ptr++;

    out_buf_ptr += copy_signature_part(out_buf_ptr, r_part, ECDSA_384_SIGNATURE_R_PART_SIZE);
    out_buf_ptr += copy_signature_part(out_buf_ptr, s_part, ECDSA_384_SIGNATURE_S_PART_SIZE);

    *sequence_len = out_buf_ptr - (sequence_len + 1);

    return out_buf_ptr - out_buf;
}

enum tfm_plat_err_t rse_asn1_iak_endorsement_cert_generate(
    struct rse_asn1_iak_endorsement_cert_provisioned_params_s *provisioned_params,
    struct rse_asn1_iak_endorsement_cert_dynamic_params_s *dynamic_params)
{
    enum tfm_plat_err_t plat_err;
    struct x509_v3_cert_s *cert = &iak_endorsement_certificate;
    uint8_t *serial_num_ptr;
    size_t signature_size;

    /* Validate arguments */
    plat_err = verify_params_sizes(cert, provisioned_params, dynamic_params);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Write given values to struct */
    /* We have to dynamically write the signature as the integer encoding requires an additional
     * 0x00 byte in the case that the first value is >= 0x80 to indicate it is positive */
    signature_size =
        write_signature(cert->signature.signature, provisioned_params->signature,
                        provisioned_params->signature + ECDSA_384_SIGNATURE_R_PART_SIZE);
    cert->signature.bit_string_unused_bits = 0x00;
    cert->signature.tag_length = (struct tl_small_s)TL_SMALL_INITIALISER_SIZE(
        ASN1_BIT_STRING,
        SIZEOF_STRUCT_EXCLUDING_TL(struct signature_value_s, tag_length, struct tl_small_s) -
            sizeof(cert->signature.signature) + signature_size);

    memcpy(cert->tbs_certificate.extensions.authority_key.authority_key_bytes,
           provisioned_params->endorsement_cert_ski,
           sizeof(cert->tbs_certificate.extensions.authority_key.authority_key_bytes));

    /*  0x01 | SOC_INFO_REG | SoC UID */
    serial_num_ptr = cert->tbs_certificate.serial_number.data;
    *serial_num_ptr++ = 0x01;

    /* Need to convert SOC_INFO_REG to big endian */
    *serial_num_ptr++ = (dynamic_params->soc_info_reg_val >> 24) & 0xFF;
    *serial_num_ptr++ = (dynamic_params->soc_info_reg_val >> 16) & 0xFF;
    *serial_num_ptr++ = (dynamic_params->soc_info_reg_val >> 8) & 0xFF;
    *serial_num_ptr++ = dynamic_params->soc_info_reg_val & 0xFF;

    /* Need to convert whole 12 byte SoC UID to big endian */
    for (size_t i = 0; i < dynamic_params->soc_uid_size; i++) {
        *serial_num_ptr++ = dynamic_params->soc_uid[dynamic_params->soc_uid_size - i - 1];
    }

    /* 0x04 | X | Y */
    cert->tbs_certificate.key_info.key[0] = 0x04;
    memcpy(cert->tbs_certificate.key_info.key + 1, dynamic_params->rak_pub,
           dynamic_params->rak_pub_size);

    /* Write values converted to printable_string format to struct */
    convert_to_printable_string(
        cert->tbs_certificate.issuer_name.endorsement_ski.hex_encoded_endorsement_ski.data,
        sizeof(cert->tbs_certificate.issuer_name.endorsement_ski.hex_encoded_endorsement_ski.data),
        provisioned_params->endorsement_cert_ski, provisioned_params->endorsement_cert_ski_size);

    convert_to_printable_string(
        cert->tbs_certificate.subject.hex_encoded_serial_number.hex_encoded_serial_number.data,
        sizeof(
            cert->tbs_certificate.subject.hex_encoded_serial_number.hex_encoded_serial_number.data),
        cert->tbs_certificate.serial_number.data + 1,
        sizeof(cert->tbs_certificate.serial_number.data) - 1);

    /* Write overall sequence */
    cert->sequence_certificate_tag = (struct tl_large_s)TL_LARGE_INITIALISER_SIZE(
        ASN1_SEQUENCE, SIZEOF_STRUCT_EXCLUDING_TL(struct x509_v3_cert_s, sequence_certificate_tag,
                                                  struct tl_large_s) -
                           sizeof(cert->signature.signature) + signature_size);

    return TFM_PLAT_ERR_SUCCESS;
}

static void get_signature_ptrs(uint8_t *signature, uint8_t **r_part, uint8_t **s_part)
{
    uint8_t *r_part_int_size, *s_part_int_size;

    /* Skip sequence and integer tag */
    r_part_int_size = signature + 2 + 1;
    *r_part = r_part_int_size + 1 + (*r_part_int_size - ECDSA_384_SIGNATURE_R_PART_SIZE);

    /* Skip integer tag */
    s_part_int_size = (r_part_int_size + 1) + *r_part_int_size + 1;
    *s_part = s_part_int_size + 1 + (*s_part_int_size - ECDSA_384_SIGNATURE_S_PART_SIZE);
}

enum tfm_plat_err_t rse_asn1_iak_endorsement_cert_verify(struct rse_asn1_pk_s *signing_pk)
{
    int32_t bl1_err;
    uint32_t cert_hash[SHA_384_HASH_SIZE / sizeof(uint32_t)];
    size_t hash_size;
    cc3xx_err_t cc3xx_err;
    struct x509_v3_cert_s *cert = &iak_endorsement_certificate;
    uint8_t *r_part_ptr, *s_part_ptr;
    uint32_t sig_r[ECDSA_384_SIGNATURE_R_PART_SIZE / sizeof(uint32_t)];
    uint32_t sig_s[ECDSA_384_SIGNATURE_S_PART_SIZE / sizeof(uint32_t)];

    bl1_err = bl1_hash_compute(TFM_BL1_HASH_ALG_SHA384, (uint8_t *)&cert->tbs_certificate,
                               sizeof(cert->tbs_certificate), (uint8_t *)cert_hash,
                               sizeof(cert_hash), &hash_size);
    if (bl1_err != 0) {
        return (enum tfm_plat_err_t)bl1_err;
    }

    get_signature_ptrs(cert->signature.signature, &r_part_ptr, &s_part_ptr);
    /* Copy to buffer to ensure 4-byte alignment */
    memcpy(sig_r, r_part_ptr, ECDSA_384_SIGNATURE_R_PART_SIZE);
    memcpy(sig_s, s_part_ptr, ECDSA_384_SIGNATURE_S_PART_SIZE);

    cc3xx_err = cc3xx_lowlevel_ecdsa_verify(CC3XX_EC_CURVE_SECP_384_R1, signing_pk->public_key_x,
                                            signing_pk->public_key_x_size, signing_pk->public_key_y,
                                            signing_pk->public_key_y_size, cert_hash, hash_size,
                                            sig_r, ECDSA_384_SIGNATURE_R_PART_SIZE, sig_s,
                                            ECDSA_384_SIGNATURE_S_PART_SIZE);
    if (cc3xx_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc3xx_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_asn1_iak_endorsement_cert_get(const uint8_t **cert, size_t *cert_size)
{
    struct x509_v3_cert_s *cert_ptr = &iak_endorsement_certificate;

    *cert = (uint8_t *)cert_ptr;
    *cert_size = sizeof(cert_ptr->sequence_certificate_tag) +
                 ((cert_ptr->sequence_certificate_tag.len_high << 8) |
                  (cert_ptr->sequence_certificate_tag.len_low));

    return TFM_PLAT_ERR_SUCCESS;
}

static void copy_key_to_buf(uint8_t *buf, struct rse_asn1_pk_s *public_key)
{
    memcpy(buf, public_key->public_key_x, public_key->public_key_x_size);
    memcpy(buf + public_key->public_key_x_size, public_key->public_key_y,
           public_key->public_key_y_size);
}

static enum tfm_plat_err_t encode_ecdsa256_public_key(uint8_t *buf, size_t buf_size,
                                                      struct rse_asn1_pk_s *public_key,
                                                      size_t *out_len)
{
    struct subject_ecdsa256_public_key_info_s *pk_info =
        (struct subject_ecdsa256_public_key_info_s *)buf;

    if (buf_size < sizeof(*pk_info)) {
        return TFM_PLAT_ERR_ASN1_PUBLIC_KEY_BUFFER_INVALID_SIZE;
    }

    if ((public_key->public_key_x_size != ECDSA_256_PUBLIC_KEY_X_SIZE) ||
        (public_key->public_key_y_size != ECDSA_256_PUBLIC_KEY_Y_SIZE)) {
        return TFM_PLAT_ERR_ASN1_PUBLIC_KEY_INVALID_KEY_SIZE;
    }

    /* Do not use compound literal for whole struct as there is
     * no need to initalise the key field to 0 */
    pk_info->tag_length = (struct tl_small_s)TL_SMALL_INITIALISER(
        ASN1_SEQUENCE, struct subject_ecdsa256_public_key_info_s, tag_length);
    pk_info->key_info = (struct subject_ecdsa256_public_key_info_alg_s) {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct subject_ecdsa256_public_key_info_alg_s, tag_length),
                .algorithm = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_7_bytes_s, tag_length),
                    .data = OID_ID_EC_PUBLIC_KEY,
                },
                .parameters = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_8_bytes_s, tag_length),
                    .data = OID_SECP256R1,
                }
            };
    pk_info->key_tag_length = (struct tl_small_s)TL_SMALL_INITIALISER(
        ASN1_BIT_STRING, struct subject_ecdsa256_public_key_info_s, key_tag_length);
    pk_info->bit_string_unused_bits = 0x00;

    pk_info->key[0] = 0x04;
    copy_key_to_buf(pk_info->key + 1, public_key);

    *out_len = sizeof(*pk_info);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t encode_ecdsa384_public_key(uint8_t *buf, size_t buf_size,
                                                      struct rse_asn1_pk_s *public_key,
                                                      size_t *out_len)
{
    struct subject_ecdsa384_public_key_info_s *pk_info =
        (struct subject_ecdsa384_public_key_info_s *)buf;

    if (buf_size < sizeof(*pk_info)) {
        return TFM_PLAT_ERR_ASN1_PUBLIC_KEY_BUFFER_INVALID_SIZE;
    }

    if ((public_key->public_key_x_size != ECDSA_384_PUBLIC_KEY_X_SIZE) ||
        (public_key->public_key_y_size != ECDSA_384_PUBLIC_KEY_Y_SIZE)) {
        return TFM_PLAT_ERR_ASN1_PUBLIC_KEY_INVALID_KEY_SIZE;
    }

    /* Do not use compound literal for whole struct as there is
     * no need to initalise the key field to 0 */
    pk_info->tag_length = (struct tl_small_s)TL_SMALL_INITIALISER(
        ASN1_SEQUENCE, struct subject_ecdsa384_public_key_info_s, tag_length);
    pk_info->key_info = (struct subject_ecdsa384_public_key_info_alg_s) {
                TL_SMALL_DEFINE(ASN1_SEQUENCE, struct subject_ecdsa384_public_key_info_alg_s, tag_length),
                .algorithm = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_7_bytes_s, tag_length),
                    .data = OID_ID_EC_PUBLIC_KEY,
                },
                .parameters = {
                    TL_SMALL_DEFINE(ASN1_OBJECT_IDENTIFIER, struct oid_5_bytes_s, tag_length),
                    .data = OID_SECP384R1,
                }
            };
    pk_info->key_tag_length = (struct tl_small_s)TL_SMALL_INITIALISER(
        ASN1_BIT_STRING, struct subject_ecdsa384_public_key_info_s, key_tag_length);
    pk_info->bit_string_unused_bits = 0x00;

    pk_info->key[0] = 0x04;
    copy_key_to_buf(pk_info->key + 1, public_key);

    *out_len = sizeof(*pk_info);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_asn1_ecdsa_public_key_get(uint8_t *buf, size_t buf_size,
                                                  enum rse_asn1_ecdsa_public_key_curve curve,
                                                  struct rse_asn1_pk_s *public_key, size_t *out_len)
{
    switch (curve) {
    case RSE_ASN1_ECDSA_PUBLIC_KEY_CURVE_SECP256R1:
        return encode_ecdsa256_public_key(buf, buf_size, public_key, out_len);
    case RSE_ASN1_ECDSA_PUBLIC_KEY_CURVE_SECP384R1:
        return encode_ecdsa384_public_key(buf, buf_size, public_key, out_len);
    default:
        return TFM_PLAT_ERR_ASN1_PUBLIC_KEY_INVALID_CURVE;
    }
}
