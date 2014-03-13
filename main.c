
#include "msp430fg4618.h"
#include "lcd.h"
#include <stdint.h>

void startCompteur()
{
  volatile int i = 0;
  int compteur =0;
   lcd_display_number(compteur);
  for(;;)
  {
    if(P1IN==0x01)
    {
      compteur++;
      while(P1IN==0x01);
    }
    lcd_display_number(compteur);
    for(i=0;i<1000;i++);
  }
}

unsigned int alea()
{
  static uint16_t n =1;
  
  n = n * 3 + 5 ;
  return n;
}
  

void tirage ()
{
  volatile int i = 0;
  unsigned int n;
  for(;;)
  {
    if(P1IN==0x01)
    {
      n = alea();
      while(P1IN==0x01);
    }
    lcd_display_number(n);
    for(i=0;i<1000;i++);
  }
}
      
void question19()
{
  unsigned long a = 30000;
  unsigned int b = 40000;
  unsigned long c = a*b;
  lcd_display_number(c);
}

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR =0x00;
  
  
  
  lcd_init();
  
  //lcd_display_number(65535);
  
  //lcd_display_seven_digits(1,2,3,4,5,6,7);
  
  tirage();

  //question19();  
    
  return 0;
}