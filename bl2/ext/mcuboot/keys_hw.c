/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Original code taken from mcuboot project at:
 * https://github.com/mcu-tools/mcuboot
 * Git SHA of the original version: ac55554059147fff718015be9f4bd3108123f50a
 * Modifications are Copyright (c) 2019-2025 Arm Limited.
 */

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <bootutil/sign_key.h>
#include "mcuboot_config/mcuboot_config.h"
#include "tfm_plat_rotpk.h"
#include "tfm_plat_crypto_keys.h"

unsigned int pub_key_len;
struct bootutil_key bootutil_keys[1] = {
    {
        .key = 0,
        .len = &pub_key_len,
    },
};
const int bootutil_key_cnt = 1;

int boot_retrieve_public_key_hash(uint8_t image_index,
                                  uint8_t key_index,
                                  uint8_t *public_key_hash,
                                  size_t *key_hash_size)
{
    (void) key_index;
    return tfm_plat_get_rotpk_hash(image_index,
                                   public_key_hash,
                                   (uint32_t *)key_hash_size);
}
