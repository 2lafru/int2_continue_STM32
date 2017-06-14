/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f1xx.h"
#include "stm32f1xx_nucleo.h"

void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~TIM_SR_UIF;													// On met à zéro l'indicateur

	GPIOA->ODR ^= GPIO_ODR_ODR5;												// On commute le port A5
}

void configurerTimer(void)
{
	TIM2->ARR = 999; 															// Valeur de rechargement
	TIM2->PSC = SystemCoreClock/1000 - 1;										// Division de fréquence
	TIM2->DIER = TIM_DIER_UIE;													// On active les interruptions
	TIM2->CR1 = TIM_CR1_CEN;													// Activation du chronomètre

	NVIC_SetPriority(TIM2_IRQn, 1);												// Priorité max pour l'interruption du timer 2
	NVIC_EnableIRQ(TIM2_IRQn);													// On active l'interruption du timer 2
}

int main(void)
{
	RCC->APB2ENR = RCC_APB2ENR_IOPAEN;											// On active le port A
	RCC->APB1ENR = RCC_APB1ENR_TIM2EN;											// On active le timer 2
	GPIOA->CRL = GPIO_CRL_MODE5_0;												// On règle le port A5 comme une sortie à fréquence maximale 2 MHz

	configurerTimer();

	while(1);
	return 0;
}
