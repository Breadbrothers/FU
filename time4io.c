#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"



int getsw(void){

  int SW = (PORTD >> 8) & 0x0f;

  return SW;
}


int getbtns(void){

  int BTN = (PORTD >> 5) & 0x07;
  return BTN;
}
