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
--  Abstract : Global configurations.
--
------------------------------------------------------------------------------*/

#ifndef _MPEG2DEC_CFG_H
#define _MPEG2DEC_CFG_H

/*
 *  Maximum number of macro blocks in one FRAME
 */
#define MPEG2_MIN_WIDTH   48

#define MPEG2_MIN_HEIGHT  48

#define MPEG2API_DEC_MBS  8160

#define MPEG2DEC_TABLE_SIZE 128

#define MPEG2 1

#define MPEG1 0

#define MAX_OUTPUT_PICS 2

#endif /* already included #ifndef _MPEG2DEC_CFG_H */
