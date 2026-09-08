/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __CMSIS_FIXED_PARTITIONS_H
#define __CMSIS_FIXED_PARTITIONS_H

/**
 * @brief Get cmsis driver on partition "label"
 *
 * Example devicetree fragment:
 *
 *	partitions {
 *		compatible = "cmsis,fixed-partitions";
 *
 *		flash_partition1: partition@0 {
 *			label = "partition1";
 *		};
 *
 *		flash_partition2: partition@1 {
 *			label = "partition2";
 *		};
 *	};
 *
 * Example usage:
 *
 *     DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(flash_partition1)
 *     DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(flash_partition2)
 *
 * @param label lowercase-and-underscores node label name
 * @return ARM_DRIVER_FLASH to partition "label"
 */
#define DT_CMSIS_FIXED_PARTITIONS_DRIVER_BY_LABEL(label) \
		UTIL_CAT(Driver_, DT_NODELABEL(label))

/**
 * @brief Get addresse of fixed partition "label"
 *
 * Example devicetree fragment:
 *
 *	partitions {
 *		compatible = "cmsis,fixed-partitions";
 *
 *		flash_partition1: partition@0 {
 *			label = "partition1";
 *			reg = <0x10000000 0x00100000>;
 *		};
 *
 *		flash_partition2: partition@1 {
 *			label = "partition2";
 *			reg = <0x20000000 0x00200000>;
 *		};
 *	};
 *
 * Example usage:
 *
 *     DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(flash_partition1) //0x10000000
 *     DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(flash_partition2) //0x20000000
 *
 * @param label lowercase-and-underscores node label name
 * @return address of fixed partition "label"
 */
#define DT_CMSIS_FIXED_PARTITIONS_ADDR_BY_LABEL(label) \
		DT_REG_ADDR(DT_NODELABEL(label))

/**
 * @brief Get size of fixed partition "label"
 *
 * Example devicetree fragment:
 *
 *	partitions {
 *		compatible = "cmsis,fixed-partitions";
 *
 *		flash_partition1: partition@0 {
 *			label = "partition1";
 *			reg = <0x1000000 0x00100000>;
 *		};
 *
 *		flash_partition2: partition@1 {
 *			label = "partition2";
 *			reg = <0x20000000 0x00200000>;
 *		};
 *	};
 *
 * Example usage:
 *
 *     DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(flash_partition1) //0x00100000
 *     DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(flash_partition2) //0x00200000
 *
 * @param label lowercase-and-underscores node label name
 * @return size of fixed partition "label"
 */
#define DT_CMSIS_FIXED_PARTITIONS_SIZE_BY_LABEL(label) \
		DT_REG_SIZE(DT_NODELABEL(label))

#endif /* __CMSIS_FIXED_PARTITIONS_H */
