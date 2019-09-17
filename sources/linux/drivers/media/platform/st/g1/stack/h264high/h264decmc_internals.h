/*
 * (C) COPYRIGHT 2012 HANTRO PRODUCTS
 *
 * Please contact: hantro-support@verisilicon.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */



#ifndef SOFTWARE_SOURCE_H264HIGH_H264DECMC_INTERNALS_H_
#define SOFTWARE_SOURCE_H264HIGH_H264DECMC_INTERNALS_H_

#include "basetype.h"
#include "h264hwd_container.h"

void h264MCPushOutputAll(decContainer_t *pDecCont);
void h264MCWaitPicReadyAll(decContainer_t *pDecCont);

void h264MCSetHwRdyCallback(decContainer_t *pDecCont);

void h264MCSetRefPicStatus(volatile u8 *pSyncMem, u32 isFieldPic,
                           u32 isBottomField);

void h264MCHwRdyCallback(void *args, i32 core_id);

#endif /* SOFTWARE_SOURCE_H264HIGH_H264DECMC_INTERNALS_H_ */
