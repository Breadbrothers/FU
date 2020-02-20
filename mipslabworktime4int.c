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
#define TMR2PERIOD ((80000000 / 64) 100);

int prime = 1234567;

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

volatile int* portE = (volatile int*) 0xbf886110;
volatile int* trisE = (volatile int*) 0xbf886100;
int timeoutcount = 0;

/* Interrupt Service Routine */
void user_isr( void )
{
   time2string( textstring, mytime );
   display_string( 3, textstring );
   display_update();
   tick( &mytime );
   IFS(0) = 0;
   display_image(96, icon);
   *portE = *portE + 1;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
   T2CON = 0x60;        //Set TCKPS to 110, thus prescale value to 64.
   TMR2 = 0x0;          //Initialize count to 0.
   PR2 = TMR2PERIOD;    //Set period between ticks to 10 ms.
   T2CONSET = 0x8000;   //Set bit 15 to 1, thus turn on timer.


   *trisE = *trisE & 0xf00;
   TRISD  = TRISD | 0x0fe0;
   *portE = 0;

   return;
}
/* This function is called repetitively from the main program */
void labwork( void )
{
   prime = nextprime( prime );
   display_string( 0, itoaconv( prime ) );
   display_update();
}
