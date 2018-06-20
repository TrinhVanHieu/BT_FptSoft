
#include "hw_stm32f030_mini.h"
/**************************************************************************************************************************/

void delay(unsigned int timeout)
{
   unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

/*USART1_clock*/
void enable_clk_usart(void)
{
	unsigned int tmprep;
	tmprep = read_reg(RCC_APB2ENR, ~(0x01u << 14));
	tmprep = tmprep | (0x01u << 14);
	write_reg(RCC_APB2ENR, tmprep);
}


/*Init USART1*/
void init_usart(void)
{
	unsigned int tmprep;
	/*disenable UE = 0*/
	tmprep = read_reg(USART1_CR1, ~(0x01u << 0));
	tmprep = tmprep | (0x00u << 0);
	write_reg(USART1_CR1, tmprep);
	
	/*data 8 bit M[1:0] = 00 control CR1*/
		//M1 = 0
	tmprep = read_reg(USART1_CR1, ~(0x01u << 28));
	tmprep = tmprep | (0x00u <<28);
	write_reg(USART1_CR1, tmprep);
	
		//M0 = 0
	tmprep = read_reg(USART1_CR1, ~(0x01u << 12));
	tmprep = tmprep | (0x00u <<12);
	write_reg(USART1_CR1, tmprep);
	
	/*baud rate BRR*/
	
		/*OVER8 = 0 ->  Oversampling by 16*/
	tmprep = read_reg(USART1_CR1, ~(0x01u << 15));
	tmprep = tmprep | (0x00u <<15);
	write_reg(USART1_CR1, tmprep);
	
		//BRR: USARTDIV = 833d = 0341h
	tmprep = read_reg(USART1_BRR, ~(0x0fffu << 0));
	tmprep = tmprep | (0x0341u << 0);
	write_reg(USART1_BRR, tmprep);
	
	
	/*bits stop CR2*/
	tmprep = read_reg(USART1_CR2, ~(0x03u << 12));
	tmprep = tmprep | (0x00u << 12);
	write_reg(USART1_CR2, tmprep);
	
	/*enable UE = 1*/
	tmprep = read_reg(USART1_CR1, ~(0x01u << 0));
	tmprep = tmprep | (0x01 << 0);
	write_reg(USART1_CR1, tmprep);
	
	/*enable TE = 1*/
	tmprep = read_reg(USART1_CR1, ~(0x01u << 3));
	tmprep = tmprep | (0x01 << 3);
	write_reg(USART1_CR1, tmprep);
}
/*USART1_transmitter*/
void Usart1_transmitter(void)
{
	write_reg(USART1_TDR, 0x41u); //A = 0x41u
}

/******************************************************************************************************************/
void main(void)
{
	/*enable clock*/
	enable_clk_usart();
	/*init_usart*/
	init_usart();
  while(1)
  {
	Usart1_transmitter();
	delay(0xff);
  }
}
/********************************************************************************************************************8*/
void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}