/********Headers********/
#include <xc.h>
/******************************************************************************/
/* Configuration                                                             */
/******************************************************************************/

// Select Oscillator and switching.
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);
// Select clock.
_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_ON & FCKSM_CSDCMD);
// Watchdog Timer.S
_FWDT(FWDTEN_OFF);
// Select debug channel.
_FICD(ICS_PGD1 & JTAGEN_OFF);

_FPOR(PWMPIN_ON);

#include <stdint.h>        // Includes uint16_t definition
#include <stdio.h>         // Includes sprintf
#include <stdbool.h>       // Includes true/false definition
#include <math.h>

#include "main.h"


int main(int argc, char** argv) {
    Init_All();
    //PutAX(24, AX_BAUD_RATE ,34);
    
    
    char LCDString[50] = {};
    uint16_t ax_pos = 0;
    int8_t ax_dir = 1;
    
    while (1)
    {       //PutAX(22, AX_BAUD_RATE ,34);

        
        PutAX(22, AX_GOAL_POSITION, ax_pos);
        PutAX(24, AX_GOAL_POSITION, 1023-ax_pos);
        
        sprintf(LCDString, "POS\n%d",ax_pos);
        LCD_WriteString(LCDString);

        ax_pos += ax_dir*2;
        
        if ((ax_pos < 0) || (ax_pos > 1023))
        {
            ax_dir *= -1;
            ax_pos += ax_dir*2;    
        }
     
        __delay_ms(200);
    }
}

