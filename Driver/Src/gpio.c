#include "gpio.h"
#include "stm32f4xx.h"

// PG13--> Green
// PG14--> RED

/**
 * @brief   Init LEDs
 * @note
 * @param   LED enum type
 * @retval  Init_LED
 */
void Init_LED(LED led)
{
	switch(led)
	{
		case GREEN:
			/*Enable clock PORT G*/
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

			/*select PIN mode*/
			GPIOG->MODER |= GPIO_MODER_MODER13_0;
			GPIOG->MODER &= ~(GPIO_MODER_MODER13_1);

			/* select output type push pull*/
			GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_13);

			/* select output speed */
			GPIOG->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13_0;
			GPIOG->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR13_1);

			/* select pull up/down */
			GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR13_0);
			GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR13_1);
			break;

		case RED:
			/*Enable clock PORT G */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

			/*select PIN mode output*/
			GPIOG->MODER |= GPIO_MODER_MODER14_0;
			GPIOG->MODER &= ~(GPIO_MODER_MODER14_1);

			/* select output type push pull*/
			GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_14);

			/* select output speed */
			GPIOG->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14_0;
			GPIOG->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR14_1;

			/* select pull up/down */
			GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR14_0);
			GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR14_1);
			break;
		default:
			break;
	}

}

/**
 * @brief   TurnON LEDs
 * @note
 * @param   LED enum type
 * @retval  Set_LED
 */
void Set_LED(LED led)
{
	switch(led){

		case GREEN:
			/* set pin 13 */
			GPIOG->BSRRL = GPIO_BSRR_BS_13;
			break;

		case RED:
			/* set pin 14 */
			GPIOG->BSRRL = GPIO_BSRR_BS_14;
			break;

		default:
		break;
	}
}

/**
 * @brief   TurnOFF LEDs
 * @note
 * @param   LED enum type
 * @retval  Set_LED
 */

void Reset_LED(LED led)
{
	switch(led){

		case GREEN:
			/* reset pin 13 */
			GPIOG->BSRRH = GPIO_BSRR_BS_13;
			break;

		case RED:
			/* reset pin 14 */
			GPIOG->BSRRH = GPIO_BSRR_BS_14;
			break;

		default:
		break;
	}
}
