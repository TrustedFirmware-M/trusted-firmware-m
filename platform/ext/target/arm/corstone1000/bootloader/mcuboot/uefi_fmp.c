/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <stdbool.h>
#include "tfm_hal_device_header.h"
#include "uefi_fmp.h"
#include "flash_layout.h"

/* The count will increase when partial update is supported.
 * At present, only full WIC is considered as updatable image.
 */
#define NUMBER_OF_FMP_IMAGES    NR_OF_IMAGES_IN_FW_BANK
#define NO_OF_FMP_VARIABLES_PER_IMAGE   6

#define UEFI_ARCHITECTURE_64

#ifdef UEFI_ARCHITECTURE_64
typedef uint64_t uefi_ptr_t;
typedef uint64_t efi_uintn_t;
#else
typedef uint32_t uefi_ptr_t;
typedef uint32_t efi_uintn_t;
#endif

/* Below macro definations and struct declarations taken from UEFI spec 2.9 */

/*
 * Image Attribute Definitions
 */
#define IMAGE_ATTRIBUTE_IMAGE_UPDATABLE            0x00000001
#define IMAGE_ATTRIBUTE_RESET_REQUIRED             0x00000002
#define IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED    0x00000004
#define IMAGE_ATTRIBUTE_IN_USE                     0x00000008
#define IMAGE_ATTRIBUTE_UEFI_IMAGE                 0x00000010
#define IMAGE_ATTRIBUTE_DEPENDENCY                 0x00000020

typedef uint32_t DescriptorVersion_t;
typedef uint32_t DescriptorSize_t;
typedef uint8_t DescriptorCount_t;

typedef __PACKED_STRUCT {
    uint8_t ImageIndex;
    struct efi_guid ImageTypeId;
    uint64_t ImageId;
    uefi_ptr_t PtrImageIdName;
    uint32_t Version;
    uefi_ptr_t PtrVersionName;
    efi_uintn_t Size;
    uint64_t AttributesSupported;
    uint64_t AttributesSetting;
    uint64_t Compatibilities;
    /* Introduced with DescriptorVersion 2+ */
    uint32_t LowestSupportedImageVersion;
    /* Introduced with DescriptorVersion 3+ */
    uint32_t LastAttemptVersion;
    uint32_t LastAttemptStatus;
    uint64_t HardwareInstance;
    /* Introduced with DescriptorVersion 4+ */
    uefi_ptr_t PtrDependencies;
} EFI_FIRMWARE_IMAGE_DESCRIPTOR;

typedef __PACKED_STRUCT {
    DescriptorVersion_t DescriptorVersion;
    DescriptorSize_t DescriptorsSize;
    DescriptorCount_t DescriptorCount;
    EFI_FIRMWARE_IMAGE_DESCRIPTOR ImageDescriptor;
    uint16_t *ImageName;
    uint32_t ImageNameSize;
    uint16_t *ImageVersionName;
    uint32_t ImageVersionNameSize;
} EFI_FIRMWARE_MANAGEMENT_PROTOCOL_IMAGE_INFO;

struct corstone_image_info {
    uint8_t corstone_image_name[50];
    uint8_t corstone_version_name[50];
} __packed;

/* Change image names and version name when partial update is implemented */
struct corstone_image_info image_info[NUMBER_OF_FMP_IMAGES] = {
    {
        { 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'W', 'I', 'C', '\0' },
	{ 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'B', 'E', 'S', 'T', '\0'},
    },
    {
        { 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'W', 'I', 'C', '\0' },
	{ 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'B', 'E', 'S', 'T', '\0'},
    },
    {
        { 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'W', 'I', 'C', '\0' },
	{ 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'B', 'E', 'S', 'T', '\0'},
    },
    {
        { 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'W', 'I', 'C', '\0' },
	{ 'C', 'O', 'R', 'S', 'T', 'O', 'N', 'E', '1', '0', '0', '0', '_', 'B', 'E', 'S', 'T', '\0'},
    },
};
static EFI_FIRMWARE_MANAGEMENT_PROTOCOL_IMAGE_INFO fmp_info[NUMBER_OF_FMP_IMAGES];

extern fwu_bank_image_info_t fwu_image[];

static bool is_fmp_info_initialized = false;

static void init_fmp_info(void)
{
    if(is_fmp_info_initialized) {
        return;
    }
    memset(fmp_info, 0,
     sizeof(EFI_FIRMWARE_MANAGEMENT_PROTOCOL_IMAGE_INFO) * NUMBER_OF_FMP_IMAGES);

    /* Fill information for the WIC.
     * Add further details when partial image is supported.
     */

    for (int i = 0; i < NUMBER_OF_FMP_IMAGES; i++)
    {
        fmp_info[i].DescriptorVersion = 4;
        fmp_info[i].DescriptorCount = NUMBER_OF_FMP_IMAGES;
        fmp_info[i].DescriptorsSize =
                     sizeof(EFI_FIRMWARE_IMAGE_DESCRIPTOR) +
                     sizeof(image_info[i].corstone_image_name) + sizeof(image_info[i].corstone_version_name);

        fmp_info[i].ImageDescriptor.ImageIndex = i+1;

        memcpy(&fmp_info[i].ImageDescriptor.ImageTypeId, &fwu_image[i].image_guid,
                sizeof(struct efi_guid));

        fmp_info[i].ImageDescriptor.ImageId = i+1;
        fmp_info[i].ImageDescriptor.Version = FWU_IMAGE_INITIAL_VERSION;
        fmp_info[i].ImageDescriptor.AttributesSupported = 1;
        fmp_info[i].ImageDescriptor.AttributesSetting = (
                IMAGE_ATTRIBUTE_IMAGE_UPDATABLE | IMAGE_ATTRIBUTE_RESET_REQUIRED);
        fmp_info[i].ImageDescriptor.LowestSupportedImageVersion =
                FWU_IMAGE_INITIAL_VERSION;
        fmp_info[i].ImageDescriptor.LastAttemptVersion = FWU_IMAGE_INITIAL_VERSION;
        fmp_info[i].ImageDescriptor.LastAttemptStatus = LAST_ATTEMPT_STATUS_SUCCESS;

        fmp_info[i].ImageName = image_info[i].corstone_image_name;
        fmp_info[i].ImageNameSize = sizeof(image_info[i].corstone_image_name);
        fmp_info[i].ImageVersionName = image_info[i].corstone_version_name;
        fmp_info[i].ImageVersionNameSize = sizeof(image_info[i].corstone_version_name);
    }
    is_fmp_info_initialized = true;

    return;
}

psa_status_t fmp_set_image_info(struct efi_guid *guid,
                     uint32_t current_version, uint32_t attempt_version,
                     uint32_t last_attempt_status)
{
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;

    FWU_LOG_MSG("%s:%d Enter\n\r", __func__, __LINE__);

    if (is_fmp_info_initialized == false) {
        init_fmp_info();
    }

    for (int i = 0; i < NUMBER_OF_FMP_IMAGES; i++) {
        if ((memcmp(guid, &fmp_info[i].ImageDescriptor.ImageTypeId,
                        sizeof(struct efi_guid))) == 0)
        {
            FWU_LOG_MSG("FMP image update: image id = %u\n\r",
                                    fmp_info[i].ImageDescriptor.ImageId);
            fmp_info[i].ImageDescriptor.Version = current_version;
            fmp_info[i].ImageDescriptor.LastAttemptVersion = attempt_version;
            fmp_info[i].ImageDescriptor.LastAttemptStatus = last_attempt_status;
            FWU_LOG_MSG("FMP image update: status = %u"
                            "version=%u last_attempt_version=%u.\n\r",
                            last_attempt_status, current_version,
                            attempt_version);
            status = PSA_SUCCESS;
            break;
        }
    }

    FWU_LOG_MSG("%s:%d Exit.\n\r", __func__, __LINE__);
    return status;
}


#define NO_OF_FMP_VARIABLES    (NUMBER_OF_FMP_IMAGES * NO_OF_FMP_VARIABLES_PER_IMAGE)

static psa_status_t pack_image_info(void *buffer, uint32_t size)
{
    typedef __PACKED_STRUCT {
        uint32_t variable_count;
        uint32_t variable_size[NO_OF_FMP_VARIABLES];
        uint8_t variable[];
    } packed_buffer_t;

    packed_buffer_t *packed_buffer = buffer;
    int runner = 0;
    int index = 0;
    int current_size = sizeof(packed_buffer_t);
    int size_requirement_1 = 0;
    int size_requirement_2 = 0;

    if (size < current_size) {
        FWU_LOG_MSG("%s:%d Buffer too small.\n\r", __func__, __LINE__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    packed_buffer->variable_count = NO_OF_FMP_VARIABLES;

    for (int i = 0; i < NUMBER_OF_FMP_IMAGES; i++) {

       packed_buffer->variable_size[index++] = sizeof(DescriptorVersion_t);
       packed_buffer->variable_size[index++] = sizeof(DescriptorSize_t);
       packed_buffer->variable_size[index++] = sizeof(DescriptorCount_t);
       packed_buffer->variable_size[index++] = sizeof(EFI_FIRMWARE_IMAGE_DESCRIPTOR);
       packed_buffer->variable_size[index++] = fmp_info[i].ImageNameSize;
       packed_buffer->variable_size[index++] = fmp_info[i].ImageVersionNameSize;

       size_requirement_1 = sizeof(DescriptorVersion_t) + sizeof(DescriptorSize_t) +
              sizeof(DescriptorCount_t) + sizeof(EFI_FIRMWARE_IMAGE_DESCRIPTOR);

       size_requirement_2 = fmp_info[i].ImageNameSize + fmp_info[i].ImageVersionNameSize;

       current_size += size_requirement_1 + size_requirement_2;

       if (size < current_size) {
           FWU_LOG_MSG("%s:%d Buffer too small.\n\r", __func__, __LINE__);
           return PSA_ERROR_BUFFER_TOO_SMALL;
       }

       FWU_LOG_MSG("%s:%d ImageInfo size = %u, ImageName size = %u, "
               "ImageVersionName size = %u\n\r", __func__, __LINE__,
               sizeof(EFI_FIRMWARE_IMAGE_DESCRIPTOR), fmp_info[i].ImageNameSize,
               fmp_info[i].ImageVersionNameSize);
   
       memcpy(&packed_buffer->variable[runner], &fmp_info[i], size_requirement_1);
       runner += size_requirement_1;
   
       memcpy(&packed_buffer->variable[runner], fmp_info[i].ImageName,
                                       fmp_info[i].ImageNameSize);
       runner += fmp_info[i].ImageNameSize;
   
       memcpy(&packed_buffer->variable[runner], fmp_info[i].ImageVersionName,
                                       fmp_info[i].ImageVersionNameSize);
       runner += fmp_info[i].ImageVersionNameSize;

    }

    return PSA_SUCCESS;
}

psa_status_t fmp_get_image_info(void *buffer, uint32_t size)
{
    psa_status_t status;

    FWU_LOG_MSG("%s:%d Enter\n\r", __func__, __LINE__);

    status = pack_image_info(buffer, size);

    FWU_LOG_MSG("%s:%d Exit\n\r", __func__, __LINE__);

    return status;
}
