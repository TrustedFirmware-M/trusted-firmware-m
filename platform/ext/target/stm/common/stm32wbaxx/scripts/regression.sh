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

echo "regression script started"
sn_option=""
if [ $# -eq 1 ]; then
sn_option="sn=$1"
fi
PATH="/C/Program Files/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/":$PATH
stm32programmercli="STM32_Programmer_CLI"
# remove write protection
secbootadd0=0x180188
connect="-c port=SWD "$sn_option" mode=UR AP=1"
connect_no_reset="-c port=SWD "$sn_option" mode=HotPlug AP=1"
rdp_0="-ob RDP=0xAA TZEN=1"
remove_bank1_protect="-ob SECWM1_PSTRT=0x7f SECWM1_PEND=0x0"
remove_bank2_protect="-ob SECWM2_PSTRT=0x7f SECWM2_PEND=0x0"
erase_all="-e all"
default_ob1="-ob SRAM2_RST=1 SECBOOTADD0="0x180488" DBANK=1 SWAP_BANK=0 SECWM1_PSTRT=0x0 SECWM1_PEND=0x41 SECWM2_PSTRT=0x0 SECWM2_PEND=0x7f"

echo "Regression to RDP 0, enable tz"
$stm32programmercli $connect $rdp_0
echo "Remove bank1 protection"
$stm32programmercli $connect_no_reset $remove_bank1_protect
echo "Remove bank2 protection and erase all"
$stm32programmercli $connect_no_reset $remove_bank2_protect $erase_all
echo "-----------erasing-----------"
$stm32programmercli $connect $erase_all
echo "Set default OB 1 (dual bank, swap bank, sram2 reset, secure entry point, bank 1 full secure)"
$stm32programmercli $connect_no_reset $default_ob1
echo "regression script done, press key"
