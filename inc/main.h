#ifndef MAIN_H
#define MAIN_H

#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4

#define LOW(BAGR) GPIO_WriteLow(BAGR##_PORT, BAGR##_PIN)
#define HIGH(BAGR) GPIO_WriteHigh(BAGR##_PORT, BAGR##_PIN)
#define REVERSE(BAGR) GPIO_WriteReverse(BAGR##_PORT, BAGR##_PIN)

#define READ(BAGR) (GPIO_ReadInputPin(BAGR##_PORT, BAGR##_PIN)!=RESET) 
#define PUSH(BAGR) (GPIO_ReadInputPin(BAGR##_PORT, BAGR##_PIN)==RESET) 

// functions
void init(void);

#endif /* MAIN_H */
