#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
//#include <stdio.h>



void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    //init_uart1();

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(BTN_PORT, BTN_PIN, GPIO_MODE_IN_FL_NO_IT);

}


int main(void)
{
  
    uint32_t time = 0;
    bool btn_state = PUSH(BTN);

    init();

    while (1) {
        if (milis() - time > 20 ) {
            
            time = milis();
            //printf("%ld\n", time);
            if (btn_state == 0 && PUSH(BTN) == 1){
                REVERSE(LED);

            }
            btn_state = PUSH(BTN);
            


        }




        //delay_ms(333);
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
