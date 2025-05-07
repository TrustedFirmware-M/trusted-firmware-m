/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "cmsis_driver_config.h"
#include "RTE_Device.h"
#include "Driver_MPC_Sie.h"

#if (defined (RTE_ISRAM0_MPC) && (RTE_ISRAM0_MPC == 1)) || \
    (defined (RTE_ISRAM1_MPC) && (RTE_ISRAM1_MPC == 1)) || \
    (defined (RTE_ISRAM2_MPC) && (RTE_ISRAM2_MPC == 1)) || \
    (defined (RTE_ISRAM3_MPC) && (RTE_ISRAM3_MPC == 1)) || \
    (defined (RTE_QSPI_MPC) && (RTE_QSPI_MPC == 1)) || \
    (defined (RTE_DDR4_MPC) && (RTE_DDR4_MPC == 1))

#if (defined (RTE_ISRAM0_MPC) && (RTE_ISRAM0_MPC == 1))
ARM_DRIVER_MPC(MPC_ISRAM0_DEV, Driver_ISRAM0_MPC);
#endif /* RTE_ISRAM0_MPC */

#if (defined (RTE_ISRAM1_MPC) && (RTE_ISRAM1_MPC == 1))
ARM_DRIVER_MPC(MPC_ISRAM1_DEV, Driver_ISRAM1_MPC);
#endif /* RTE_ISRAM1_MPC */

#if (defined (RTE_ISRAM2_MPC) && (RTE_ISRAM2_MPC == 1))
ARM_DRIVER_MPC(MPC_ISRAM2_DEV, Driver_ISRAM2_MPC);
#endif /* RTE_ISRAM2_MPC */

#if (defined (RTE_ISRAM3_MPC) && (RTE_ISRAM3_MPC == 1))
ARM_DRIVER_MPC(MPC_ISRAM3_DEV, Driver_ISRAM3_MPC);
#endif /* RTE_ISRAM3_MPC */

#if (defined (RTE_QSPI_MPC) && (RTE_QSPI_MPC == 1))
ARM_DRIVER_MPC(MPC_QSPI_DEV, Driver_QSPI_MPC);
#endif /* RTE_QSPI_MPC */

#if (defined (RTE_DDR4_MPC) && (RTE_DDR4_MPC == 1))
ARM_DRIVER_MPC(MPC_DDR4_DEV, Driver_DDR4_MPC);
#endif /* RTE_DDR4_MPC */

#endif
