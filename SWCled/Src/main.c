/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ABDESSAMAD BENJAA
 * @brief          : Main program body
 ******************************************************************************
// 1.where is the led is connected?
 * Port : A
 * Pin : 5
 * 2.how to enable AHB1 bus to bring clock to PORT A?
 * the responsible module to bring clock to port A is RCC module
 */
#include <stdint.h>
/*AHB1 address and GPIOA address*/

#define 	PERIPH_BASE 			(0x40000000UL)
#define 	AHB1PERIPH_OFFSET 		(0x00020000UL)
#define 	AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define		GPIOA_OFFSET			(0x0000UL)

#define 	GPIOA_BASE 				(AHB1PERIPH_BASE + GPIOA_OFFSET)
/*RCC address*/
#define 	RCC_OFFST				(0x00003800UL)
#define 	RCC_BASE				(RCC_OFFST + AHB1PERIPH_BASE)

#define 	AHB1EN_R_OFFSET			(0x30UL)
#define 	RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define 	MODE_R_OFFSET			(0x00UL)
#define		GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define 	OD_R_OFFSET				(0x14UL)
#define 	GPIOA_ODR_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

/*set b0 to one*/
#define 	GPIOAEN					(1UL<<0)

#define 	PIN13					(1U<<13)
#define		LED_PIN13				PIN13

#define 	PIN14					(1U<<14)
#define		LED_PIN14				PIN14

#define 	PIN15					(1U<<15)
#define		LED_PIN15				PIN15

/*
 * (1U << 10) set bit 10 to 1
 * & = not (1 << 11) set bit 11 to zero*/
int main(){
	/*Enable clock access to GPIOA*/
	RCC_AHB1EN_R |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA_MODE_R |= (21U << 26);
	GPIOA_MODE_R &= 0x57FFFFFF;
	while(1)
	{
		/*Toggle PA5*/
		/*GPIOA_MODE_R |= LED_PIN;*/

		GPIOA_ODR_R ^= LED_PIN13;
		for(int i = 0; i<500000; i++){}
		GPIOA_ODR_R ^= LED_PIN13;
		for(int i = 0; i<500000; i++){}

		GPIOA_ODR_R ^= LED_PIN14;
		for(int i = 0; i<500000; i++){}
		GPIOA_ODR_R ^= LED_PIN14;
		for(int i = 0; i<500000; i++){}

		GPIOA_ODR_R ^= LED_PIN15;
		for(int i = 0; i<500000; i++){}
		GPIOA_ODR_R ^= LED_PIN15;
		for(int i = 0; i<500000; i++){}




	}
}

