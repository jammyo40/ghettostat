#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "pins.h"

#include "delay.h"
#include "i2c.h"
#include "i2cDevices.h"
#include "lcd.h"
#include "functions.h"

#pragma TRAP_PROC
void thermometerISR(void) {

}


void main(void) {

  EnableInterrupts; /* enable interrupts */
  /* include your code here */
  
  CONFIG1_COPD = 1;
  
  initI2C();
  initPortX();
  initializeDisplay();
  
  /*
  General Algorightm
  -Check if touched
  -If touched, check state and decide which button was touched
  -Update state and LCD
  
  */
  for(;;) {
    // Poll clock
    getTime();
    
    // Poll touchscreen
    /*if (isTouched()){
      determineButton();
      updateScreen();
    }     */
    __RESET_WATCHDOG(); /* feeds the dog */    
  } /* loop forever */
  /* please make sure that you never leave main */
}
