/**********************************************************************************/
/*!
*  \file      dsp_mem_def.h
*
*  \brief     <i><b> DSP Interface and MEM mapping </b></i>
*
*  \details   DSP Interface and MEM mapping
*
*  \author    APG-MID Application Team
*
*  \author    (original version) Christophe Quarre
*
*  \version   1.0
*
*  \date      2013/04/15
*
*  \bug       Unknown
*
*  \warning   
* 
*  This file is part of <component name> and is dual licensed,
*  ST Proprietary License or GNU General Public License version 2.
*
********************************************************************************
*
* Copyright (c) 2014 STMicroelectronics - All Rights Reserved
* Reproduction and Communication of this document is strictly prohibited
* unless specifically authorized in writing by STMicroelectronics.
* FOR MORE INFORMATION PLEASE READ CAREFULLY THE LICENSE AGREEMENT LOCATED
* IN THE ROOT DIRECTORY OF THIS SOFTWARE PACKAGE.
*
********************************************************************************
*
* ALTERNATIVELY, this software may be distributed under the terms of the
* GNU General Public License ("GPL") version 2, in which case the following
* provisions apply instead of the ones mentioned above :
*
********************************************************************************
*
* <component_name> is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*
* <component_name> is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* Please refer to <http://www.gnu.org/licenses/>.
*/
/***********************************************************************************/

#ifndef DSP_MEM_DEF_H_
#define DSP_MEM_DEF_H_

#include "emerald.h"            // This must be always included

//#include "audio.h"
/////////////////////////////////////////////////////////////////////
//FROM AUDIO.H 
//---------------------------------------------------------------------------
//  Programmable Audio pipeline management
//---------------------------------------------------------------------------
typedef void (*FUNCPTR)(void);

typedef void (*AUDIO_FUNCPTR)(fraction _XMEM *data, fraction _YMEM *params);

#define AF	AUDIO_FUNCPTR	//short alias

typedef struct {
    //int id;                      //just for reference
    AUDIO_FUNCPTR       func;      //filter func: init, run, update...
    fraction _XMEM      *data;     //ptr to corresponding data struct
    fraction _YMEM      *params;   //ptr to corresponding params struct
} T_Filter;

typedef struct {
    AUDIO_FUNCPTR       audioFunc;
    AUDIO_FUNCPTR       initFunc;
    AUDIO_FUNCPTR       updateFunc;
} T_FilterFuncs;

#ifndef NULL
#define NULL  0
#endif

#define DSP_ALIB_VERSION    11
/////////////////////////////////////////////////////////////////////

//#include "compiler_switches.h"
#define ACCORDO2_DSP0
//#define ACCORDO2_DSP1
//#define ACCORDO2_DSP2

//DSP MEM sizes
//NOTE: this sizes must match the memory_config
#if defined ACCORDO_DSP2
#define XRAM_SIZE                   12288
#define YRAM_SIZE                   12288
#else /*ACCORDO_DSP0 or ACCORDO_DSP1*/
#define XRAM_SIZE                   4096
#define YRAM_SIZE                   4096
#endif

//XMEM / YMEM POOLS are the pre-allocated buffers to hold the entire audio flow built via STAudioLib
//These pools size extend till the bottom of the respective X and Y mem.
#define DSP_XMEM_POOL_OFFSET         0x50
#define DSP_YMEM_POOL_OFFSET         0x200

#if 1
#define DSP_XMEM_POOL_WSIZE         (XRAM_SIZE - DSP_XMEM_POOL_OFFSET)
#define DSP_YMEM_POOL_WSIZE         (YRAM_SIZE - DSP_YMEM_POOL_OFFSET)
#else
//TMP for testing (These memory pool size can be increased if necessary)
#define DSP_XMEM_POOL_WSIZE        1000
#define DSP_YMEM_POOL_WSIZE        1000
#endif


//Fixed codes for ARM/DSP synchro
#define DSP_XMEM_LOADED_CODE		0xFEED
#define DSP_YMEM_LOADED_CODE		0xFEED
#define DSP_RUNNING_CODE			0xF00D

//ARM / DSP control interface
//ARM-XMEM and ARM-YMEM Interfacese are the only two variables with fixed placement !!!
#define DSP_AXI_OFFSET              0x8       /* @ARM = XRAM + 0x20 */
#define DSP_AYI_OFFSET              0x8       /* @ARM = YRAM + 0x20 */


typedef struct {
    unsigned int         chk_xmem_loaded;
    unsigned int         chk_dsp_running;
    unsigned int         isInitsDone;
    unsigned int         frame_counter;
    unsigned int*        pXmem_pool;		//address set by DSP
} T_ARM_XMEM_Interface;

typedef struct {
    unsigned int         alib_version;
    unsigned int         chk_ymem_loaded;
    T_FilterFuncs _YMEM* pAlib_func_table;	//address set by DSP
    T_FilterFuncs _YMEM* pUser_func_table;  //address set by DSP
    T_Filter _YMEM*      pFunc_table;		//address set by ARM
    T_Filter _YMEM*      pInit_table;		//address set by ARM
    T_Filter _YMEM**     pUpdate_table;		//address set by ARM
    fraction* _YMEM*     pTransfer_table;	//address set by ARM
    unsigned int _YMEM*  pYmem_pool;		//address set by DSP
} T_ARM_YMEM_Interface;

// ************************************************************************
//IMPORTANT: The enum below MUST match the content of g_alib_func_table[]
// ************************************************************************
typedef enum {
    NO_DSP_TYPE         = -1,	//keep first
    EXIT_LOOP,
    MUX_2OUT,
    MUX_4OUT,
    MUX_6OUT,
    MUX_8OUT,
    MUX_10OUT,
    CD_DEEMPH,
    GAIN_STATIC_2NCH,
    GAIN_SMOOTH_NCH,
    LOUD_STATIC_DP,
    LOUD_STATIC_DUAL_DP,
    TONE_STATIC_DP,
    TONE_STATIC_DUAL_DP,
    EQUA_STATIC_3BANDS_DP,
    EQUA_STATIC_4BANDS_DP,
    EQUA_STATIC_5BANDS_DP,
    EQUA_STATIC_6BANDS_DP,
    EQUA_STATIC_7BANDS_DP,
    EQUA_STATIC_8BANDS_DP,
    EQUA_STATIC_9BANDS_DP,
    EQUA_STATIC_10BANDS_DP,
    MIXE_2INS_NCH,
    MIXE_3INS_NCH,
    MIXE_4INS_NCH,
    MIXE_5INS_NCH,
    MIXE_6INS_NCH,
    MIXE_7INS_NCH,
    MIXE_8INS_NCH,
    COMP_MONO,
    COMP_STEREO,
    COMP_QUADRO,
    COMP_6CH,
    LMTR_MONO,
    LMTR_STEREO,
    LMTR_QUADRO,
    LMTR_6CH,
    DLAY_Y_2CH,
    DLAY_Y_4CH,
    DLAY_Y_6CH,
    DLAY_X_2CH,
    DLAY_X_4CH,
    DLAY_X_6CH,
    SINE_2CH,
    DCO_1CH,
    DCO_4CH_MONOZCF,
    NUM_DSP_TYPE				//keep last
} T_AudioFuncType;


#ifdef EMERALDCC
extern T_ARM_XMEM_Interface        g_axi;
extern T_ARM_YMEM_Interface _YMEM  g_ayi;
#endif

#endif /* DSP_MEM_DEF_H_ */

