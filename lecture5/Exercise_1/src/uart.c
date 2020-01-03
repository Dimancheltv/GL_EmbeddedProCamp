#include "stm32f3xx.h"                 
#include "../inc/uart.h"    

void init(void)
{
        /*! USART clock */
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
        /*! GPIOC clock */
        RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
        
        /*! TX setup pc4 */
        GPIOC->MODER |= GPIO_MODER_MODER4_1; 
        GPIOC->OTYPER &= ~GPIO_OTYPER_OT_4; 
        GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR4; 
        GPIOC->PUPDR |= GPIO_PUPDR_PUPDR4_0;
        GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;
        GPIOC->AFR[0]&= ~GPIO_AFRL_AFRL4;
        GPIOC->AFR[0]|= 7 << (4 * 4);
        
        /*! RX setup pc5 */
        GPIOC->MODER |= GPIO_MODER_MODER5_1;
        GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR5;
        GPIOC->AFR[0]&= ~GPIO_AFRL_AFRL5;
        GPIOC->AFR[0]|= 7 << (5 * 4);
        
        /*! UASRT baud_rate */
        USART1->BRR = 8000000 / BAUD_RATE;
}

void open(void) 
{
		/*! enable USART */
		USART1->CR1 |=  USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
	
		while (!(USART1->ISR & USART_ISR_TXE));
	
}

char read(void)
{
		/*! wait for the data to be received */
		while (!(USART1->ISR & USART_ISR_RXNE));
	
		return (char)USART1->RDR;
}


void write(char *buffer) 
{
		while (*buffer != '\0') {
			/*! write symbols */
			usart_putc(*(buffer++));        
		}    
}

void close(void)
{
		while (!(USART1->ISR & USART_ISR_TXE));

		/*! disable USART */
		USART1->CR1 &= ~(USART_CR1_TE | USART_CR1_RE | USART_CR1_UE);
}

void deinit(void)
{
		/*! disable USART */
		USART2->CR1 &= ~USART_CR1_TE;
		USART2->CR1 &= ~USART_CR1_RE;
		USART2->CR1 &= ~USART_CR1_RXNEIE;

		/*! disable clock */
		RCC->APB2ENR |= ~RCC_APB2ENR_USART1EN;
}

inline void usart_putc(char c) 
{
		while (!(USART1->ISR & USART_ISR_TXE));
		USART1->TDR = (uint8_t)c;
			/*! clear TXE */
		USART1->RQR = USART_RQR_TXFRQ;
}



