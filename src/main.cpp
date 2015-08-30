/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "config/stm32plus.h"
#include "config/gpio.h"
#include "config/timing.h"

#include "board/f4discovery.h"

#include "usb_bsp.h"
#include "usbh_core.h"
#include "usbh_usr.h"
#include "usbh_hid_core.h"
#include "stm32f4xx_conf.h"

using namespace stm32plus;

/* Defines -------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/** @defgroup USBH_USR_MAIN_Private_Variables
* @{
*/

USB_OTG_CORE_HANDLE           USB_OTG_Core_dev;
USBH_HOST                     USB_Host;

/* Constants -----------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/**************************************************************************/
/*
    @brief  Main Program.
	@param  None.
    @retval None.
 */
/**************************************************************************/
int main(void)
{
  //Initialise Systick
  MillisecondTimer::initialise();

  F4Discovery board;

  printf("initializing...");
  fflush(stdout);

  /* Init Host Library */
  USBH_Init(&USB_OTG_Core_dev,
		  USB_OTG_FS_CORE_ID,
		  &USB_Host,
		  &HID_cb,
		  &USR_Callbacks);

  printf("Finished\r\n");

  while(1){
	  board.led1.Toggle();
	  /* Host Task handler */
	  USBH_Process(&USB_OTG_Core_dev , &USB_Host);
	  MillisecondTimer::delay(3);
  }

}

/* End Of File ---------------------------------------------------------------*/

