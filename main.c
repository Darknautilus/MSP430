
#include "msp430fg4618.h"
#include "lcd.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  lcd_init();
  
  display_dollar();
  
  for(;;);
    
  return 0;
}