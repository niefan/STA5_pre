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
--  Abstract : Header file for stream decoding utilities
--
------------------------------------------------------------------------------*/

#ifndef RV_UTILS_H
#define RV_UTILS_H

/*------------------------------------------------------------------------------
    1. Include headers
------------------------------------------------------------------------------*/

#include "rv_container.h"


#ifdef _UTEST
#include <stdio.h>
#endif

/*------------------------------------------------------------------------------
    2. Module defines
------------------------------------------------------------------------------*/

/* constant definitions */
#ifndef OK
#define OK 0
#endif

#ifndef NOK
#define NOK 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif

/* decoder states */
enum
{
    STATE_OK,
    STATE_NOT_READY,
    STATE_SYNC_LOST
};

#define HANTRO_OK 0
#define HANTRO_NOK 1

#ifndef NULL
#define NULL 0
#endif

/* Error concealment */
#define	FREEZED_PIC_RDY 1

enum
{
    RV_I_PIC = 0,
    RV_FI_PIC = 1,
    RV_P_PIC = 2,
    RV_B_PIC = 3
};

enum
{
    RV_SLICE
};

/* value to be returned by GetBits if stream buffer is empty */
#define END_OF_STREAM 0xFFFFFFFFU

/* macro for assertion, used only if compiler flag _ASSERT_USED is defined */
#ifdef _ASSERT_USED
#ifndef ASSERT
#include <assert.h>
#define ASSERT(expr) assert(expr)
#endif
#else
#define ASSERT(expr)
#endif

/* macro to check if stream ends */
#define IS_END_OF_STREAM(pContainer) \
    ( (pContainer)->StrmDesc.strmBuffReadBits == \
      (8*(pContainer)->StrmDesc.strmBuffSize) )

/* macro to saturate value to range [min,max]. Note that for unsigned value
 * both min and max should be positive, otherwise result will be wrong due to
 * arithmetic conversion. If min > max -> value will be equal to min. */
#define SATURATE(min,value,max) \
    if ((value) < (min)) (value) = (min); \
    else if ((value) > (max)) (value) = (max);

#define ABS(val) (((val) < 0) ? -(val) : (val))

/*------------------------------------------------------------------------------
    3. Data types
------------------------------------------------------------------------------*/

typedef struct
{
    u8 *pStrmBuffStart; /* pointer to start of stream buffer */
    u8 *pStrmCurrPos;   /* current read address in stream buffer */
    u32 bitPosInWord;   /* bit position in stream buffer byte */
    u32 strmBuffSize;   /* size of stream buffer (bytes) */
    u32 strmBuffReadBits;   /* number of bits read from stream buffer */
} strmData_t;

/*------------------------------------------------------------------------------
    4. Function prototypes
------------------------------------------------------------------------------*/

u32 rv_GetBits(DecContainer *, u32 numBits);
u32 rv_ShowBits(DecContainer *, u32 numBits);
u32 rv_ShowBits32(DecContainer *);
u32 rv_FlushBits(DecContainer *, u32 numBits);

u32 rv_CheckStuffing(DecContainer *);

u32 rv_NumBits(u32 value);

#endif /* RV_UTILS_H */
