/*	Author: troy
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, INIT, PRESS, RELEASE, PRESS2, RELEASE2} state;
void Tick() {

switch(state) { 
	case Start:
        PORTB = 0x01;
        state = INIT;
        break;
	case INIT:
        if( (PINA & 0x01) == 0x01) {
            state = PRESS; break;
        } else {
            state = INIT; break;
        };
    case PRESS:
        if( (PINA & 0x01) == 0x00) {
            state = RELEASE; break;
        } else {
            state = PRESS; break;
        }
    case RELEASE:
        if( (PINA & 0x01) == 0x01) {
            state = PRESS2; break;
        } else {
            state = RELEASE; break;
        }
    case PRESS2:
        if( (PINA & 0x01) == 0x00) {
            state = RELEASE2; break;
        } else {
            state = PRESS2; break;
        }
    case RELEASE2:
        if((PINA & 0x01) == 0x01) {
            state = PRESS; break;
        } else {
            state = RELEASE2; break;
        }
    
    default:
    break;
} 

switch(state) {
    case Start:
    break;
    
    case INIT:
    PORTB = 0x01;
    break;
    
    case PRESS:
    PORTB = 0x02;
    break;
    
    case RELEASE:
    break;
    
    case PRESS2:
    PORTB = 0x01;
    break;
    
    case RELEASE2:
    break;
    
    default:
    break;
}
 
} 
int main (void) {

DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x01;

state = Start; 
while(1) { Tick(); }
} 
