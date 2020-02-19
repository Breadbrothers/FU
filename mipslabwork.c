/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

volatile int * portE = (volatile int*)0xbf886110;
volatile int * trisE = (volatile int*)0xbf886100;

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  * trisE = * trisE & 0xf00;
  TRISD =TRISD | 0x0fe0;
  *portE = 0;

  return;
}
/* This function is called repetitively from the main program */
void labwork( void )
{
  int btn= getbtns();
  if(btn)
  {
    int sw = getsw();
    if(btn & 0x4)
      mytime =  (sw << 12) | (mytime & 0x0fff);

    if(btn & 0x2)
      mytime =  (sw << 8) | (mytime & 0xf0ff );

    if(btn & 0x1)
      mytime =  (sw << 4) | (mytime & 0xff0f);
   }

  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  display_image(96, icon);
   *portE = *portE + 1;

}
