#!/usr/bin/env bash
#******************************************************************************
#  * @attention
#  *
#  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
#  * All rights reserved.</center></h2>
#  *
#  * This software component is licensed by ST under BSD 3-Clause license,
#  * the "License"; You may not use this file except in compliance with the
#  * License. You may obtain a copy of the License at:
#  *                        opensource.org/licenses/BSD-3-Clause
#  *
#  ******************************************************************************

echo "TFM UPDATE started"
sn_option=""
if [ $# -eq 1 ]; then
sn_option="sn=$1"
fi
# Absolute path to this script
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
# copy tfm_ns.bin
cp $SCRIPTPATH/../../build_ns/bin/tfm_ns.bin  $SCRIPTPATH/../../build_s/api_ns/bin

# Absolute path this script
BINPATH_SPE="$SCRIPTPATH/bin"
BINPATH_BL2="$SCRIPTPATH/bin"
BINPATH_NSPE="$SCRIPTPATH/image_signing/scripts"

PATH="/C/Program Files/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/":$PATH
stm32programmercli="STM32_Programmer_CLI"
# part ot be updated according to flash_layout.h
slot0=
slot1=
slot2=
slot3=
its=
sst=
nvcounter=

cubedir="`which STM32_Programmer_CLI`"
cubedir="$(dirname "${cubedir}")"

# bl2_header_size=0x400
header_size=0x400
slot_ns=$slot1
slot_ns=$((slot_ns + header_size))

connect="-c port=SWD "$sn_option" mode=UR"
connect_no_reset="-c port=SWD "$sn_option" mode=HotPlug"
connect_hardware_reset="-c port=SWD ${sn_option} mode=powerdown -hardRst"

echo "Write TFM Secure"
# part to be updated according to flash_layout.h
$stm32programmercli $connect_no_reset -d $BINPATH_SPE/tfm_s.bin $nvcounter -v
echo "TFM Secure Written"
echo "Write TFM NonSecure"
$stm32programmercli $connect_no_reset -d $BINPATH_SPE/tfm_ns.bin $slot_ns -v
echo "TFM NonSecure Written"
echo "Hardware reset"
$stm32programmercli $connect_hardware_reset
