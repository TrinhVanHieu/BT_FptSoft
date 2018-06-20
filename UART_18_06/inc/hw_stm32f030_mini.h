
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__


#define write_reg(addr, value)  		 	*((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)     			*((unsigned long int *)(addr)) & (mask)

/*RCC - Clock*/	
#define BASE_ADDRESS_RCC         			0x40021000u

#define RCC_APB2ENR                			BASE_ADDRESS_RCC + 0x18 //USART1



/*USART1*/
#define BASE_ADDRESS_USART1					0x40013800u

#define USART1_CR1							(BASE_ADDRESS_USART1 + 0x00u)
#define USART1_CR2							(BASE_ADDRESS_USART1 + 0x04u)
#define USART1_CR3							(BASE_ADDRESS_USART1 + 0x08u)
#define USART1_BRR							(BASE_ADDRESS_USART1 + 0x0Cu)
#define USART1_ISR							(BASE_ADDRESS_USART1 + 0x1Cu)
#define USART1_TDR							(BASE_ADDRESS_USART1 + 0x28u)

/* end file */
#endif /* __HW_STM32F030_MINI_H__ */

