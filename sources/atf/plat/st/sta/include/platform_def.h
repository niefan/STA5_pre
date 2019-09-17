/*
 * Copyright (c) 2017, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __PLATFORM_DEF_H__
#define __PLATFORM_DEF_H__

#include <arch.h>
#include <common_def.h>
#include "../sta_def.h"
#include "shared_data.h"

/*******************************************************************************
 * Generic platform constants
 ******************************************************************************/

/* Size of cacheable stacks */
#define PLATFORM_STACK_SIZE		U(0xC00)

#define BL33_IMAGE_NAME			"bl33"

#define PLATFORM_CACHE_LINE_SIZE	U(64)
#define PLAT_NUM_PWR_DOMAINS		U(5)
#define PLATFORM_CLUSTER_COUNT		U(2)
#define PLATFORM_CLUSTER0_CORE_COUNT	U(0)
#define PLATFORM_CLUSTER1_CORE_COUNT	U(2)
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER0_CORE_COUNT + \
					 PLATFORM_CLUSTER1_CORE_COUNT)
#define PLATFORM_MAX_CPUS_PER_CLUSTER	U(2)

#define MAX_IO_DEVICES			U(2)
#define MAX_IO_HANDLES			U(3)

/* eMMC RPMB and eMMC User Data */
#define MAX_IO_BLOCK_DEVICES		U(2)

/*******************************************************************************
 * BL2 specific defines.
 ******************************************************************************/
/*
 * Put BL2 just below BL3-1. BL2_BASE is calculated using the current BL2 debug
 * size plus a little space for growth.
 */
#define BL2_LIMIT		(BL2_BASE + BL2_SIZE)

/*******************************************************************************
 * SCP_BL2 specific defines.
 * SCP BL2 is M3 OS.
 ******************************************************************************/
#define SCP_BL2_LIMIT		(SCP_BL2_BASE + SCP_BL2_SIZE)

/*******************************************************************************
 * BL32 specific defines.
 ******************************************************************************/
#define BL32_LIMIT		(BL32_BASE + BL32_SIZE)

/*******************************************************************************
 * BL33 specific defines.
 ******************************************************************************/
#define BL33_LIMIT		(BL33_BASE + BL33_SIZE)

/*
 * Load address of BL33 for this platform port
 */
#define PLAT_NS_IMAGE_OFFSET	BL33_BASE
#define PLAT_NS_IMAGE_MAXSIZE	BL33_SIZE

/*******************************************************************************
 * Platform specific page table and MMU setup constants
 ******************************************************************************/
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ull << 32)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ull << 32)

/*******************************************************************************
 * Declarations and constants to access the mailboxes safely. Each mailbox is
 * aligned on the biggest cache line size in the platform. This is known only
 * to the platform as it might have a combination of integrated and external
 * caches. Such alignment ensures that two maiboxes do not sit on the same cache
 * line at any cache level. They could belong to different cpus/clusters &
 * get written while being protected by different locks causing corruption of
 * a valid mailbox address.
 ******************************************************************************/
#define CACHE_WRITEBACK_SHIFT   6
#define CACHE_WRITEBACK_GRANULE (1 << CACHE_WRITEBACK_SHIFT)

/*
 * Secure Interrupt: based on the standard ARM mapping
 */
#define ARM_IRQ_SEC_PHY_TIMER           U(29)

#define ARM_IRQ_SEC_SGI_0		U(8)
#define ARM_IRQ_SEC_SGI_1		U(9)
#define ARM_IRQ_SEC_SGI_2		U(10)
#define ARM_IRQ_SEC_SGI_3		U(11)
#define ARM_IRQ_SEC_SGI_4		U(12)
#define ARM_IRQ_SEC_SGI_5		U(13)
#define ARM_IRQ_SEC_SGI_6		U(14)
#define ARM_IRQ_SEC_SGI_7		U(15)

/*
 * Define a list of Group 1 Secure and Group 0 interrupts as per GICv3
 * terminology. On a GICv2 system or mode, the lists will be merged and treated
 * as Group 0 interrupts.
 */
#define PLATFORM_G1S_PROPS(grp) \
	INTR_PROP_DESC(ARM_IRQ_SEC_SGI_0,		\
		       GIC_HIGHEST_SEC_PRIORITY,	\
		       grp, GIC_INTR_CFG_LEVEL),	\
	INTR_PROP_DESC(ARM_IRQ_SEC_PHY_TIMER,		\
		       GIC_HIGHEST_SEC_PRIORITY,	\
		       grp, GIC_INTR_CFG_LEVEL),	\
	INTR_PROP_DESC(IRQ_SEC_SPI_MBOX_TO_M3,		\
		       GIC_HIGHEST_SEC_PRIORITY,	\
		       grp, GIC_INTR_CFG_LEVEL)

#define PLATFORM_G0_PROPS(grp)

/*
 * Power: FIXME to be checked
 */
#define PLAT_MAX_PWR_LVL	U(1)

/* Local power state for power domains in Run state. */
#define ARM_LOCAL_STATE_RUN	U(0)
/* Local power state for retention. Valid only for CPU power domains */
#define ARM_LOCAL_STATE_RET	U(1)
/* Local power state for power-down. Valid for CPU and cluster power domains */
#define ARM_LOCAL_STATE_OFF	U(2)
/*
 * This macro defines the deepest retention state possible.
 *  A higher state id will represent an invalid or a power down state.
 */
#define PLAT_MAX_RET_STATE	ARM_LOCAL_STATE_RET
/*
 * This macro defines the deepest power down states possible. Any state ID
 * higher than this is invalid.
 */
#define PLAT_MAX_OFF_STATE	ARM_LOCAL_STATE_OFF

#endif /* __PLATFORM_DEF_H__ */