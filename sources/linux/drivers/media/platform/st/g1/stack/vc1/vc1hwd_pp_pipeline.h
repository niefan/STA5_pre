/*
 * (C) COPYRIGHT 2011 HANTRO PRODUCTS
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

/*------------------------------------------------------------------------------
--
--  Abstract : VC-1 decoder and PP pipeline support
--
------------------------------------------------------------------------------*/

#ifndef VC1HWD_PP_PIPELINE_H
#define VC1HWD_PP_PIPELINE_H

i32 vc1RegisterPP(const void *decInst, const void *ppInst,
                   void (*PPDecStartPp) (const void *, const DecPpInterface *),
                   void (*PPDecPipelineEndCallback) (const void *),
                   void  (*PPConfigQuery)(const void *, DecPpQuery *),
		   void (*PPDisplayIndex)(const void *, u32),
		   void (*PPBufferData) (const void *, u32, u32, u32, u32, u32));

i32 vc1UnregisterPP(const void *decInst, const void *ppInst);

#endif /* #ifdef VC1HWD_PP_PIPELINE_H */
