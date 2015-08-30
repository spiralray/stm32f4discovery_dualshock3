/********************************************************************************/
/*!
	@file			ff_rtc_if.c
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        2.00
    @date           2013.11.30
	@brief          FatFs Realtime Clock Section.					@n
					Hardware Abstraction Layer.

    @section HISTORY
		2012.08.27	V1.00 	Start Here.
		2013.11.30	V2.00	Improved Portability for STM32F42xxx/STM32F43xxx.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "ff_rtc_if.h"

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/

/* Constants -----------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/**************************************************************************/
/*! 
    @brief  FatFs Realtime Clock Section.
	@param  RTC : rtc structure
    @retval : 1
*/
/**************************************************************************/
int rtc_gettime(FF_RTC *ff_rtc)
{

#if defined(USE_REDBULL) || defined(USE_ECH_BOARD)
	/* See rtc_support.h */
	RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);  
	RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);

	ff_rtc->sec   = ts_sec;
	ff_rtc->min   = ts_min;
	ff_rtc->hour  = ts_hour;
	ff_rtc->mday  = ts_mday;
	ff_rtc->month = ts_mon;
	ff_rtc->year  = (ts_year + 1980);	/* Valid for AC1980 ~ AC2079 */

#else /* STM32F4-Discovery and STM32F429I-Disco */
	/* 2013/11/30 12:34:56 */
	ff_rtc->sec   = 56;
	ff_rtc->min   = 34;
	ff_rtc->hour  = 12;
	ff_rtc->mday  = 30;
	ff_rtc->month = 11;
	ff_rtc->year  = 2013;
#endif

	return 1;
}

/**************************************************************************/
/*! 
    @brief  FatFs Realtime Clock Section.
	@param  RTC : rtc structure
    @retval : 1
*/
/**************************************************************************/
int rtc_settime(const FF_RTC *ff_rtc)
{

#if defined(USE_REDBULL) || defined(USE_ECH_BOARD)
	/* See rtc_support.h */
	ts_sec	= ff_rtc->sec;
	ts_min  = ff_rtc->min;
	ts_hour = ff_rtc->hour;
	ts_mday = ff_rtc->mday;
	ts_mon  = ff_rtc->month;
	ts_year = ff_rtc->year - 1980;	/* Valid for AC1980 ~ AC2079 */

	RTC_SetTime(RTC_Format_BIN, &RTC_TimeStructure);  
	RTC_SetDate(RTC_Format_BIN, &RTC_DateStructure); 

#else /* STM32F4-Discovery and STM32F429I-Disco */
	/* 2013/11/30 13:34:56 */
	/* Do nothing */
#endif

	return 1;
}


/* End Of File ---------------------------------------------------------------*/
