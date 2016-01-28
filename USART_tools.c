#include "precompiled_header.h"

#include "USART_tools.h"


volatile uint8_t dma_message[] = "UART Initialized\n";

void UART_init(){
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	DMA_InitTypeDef DMA_InitStruct;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1,ENABLE);			//Enable the DMA, by the manual.

	//UART4 configuration: 9600 8N1
	USART_StructInit(&USART_InitStruct);
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;

	GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;

	GPIO_Init(GPIOC,&GPIO_InitStruct);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4);//UART4_Tx -> PC10
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4);//UART4_Rx <- PC11

	USART_Init(UART4,&USART_InitStruct);

	DMA_StructInit(&DMA_InitStruct);
//	DMA_InitStruct.DMA_BufferSize = 18; //Will contain the number of data samples to transmit.
	DMA_InitStruct.DMA_Channel = DMA_Channel_4; //UART4_TX stream4 channel 4 of DMA1.
	DMA_InitStruct.DMA_DIR = DMA_DIR_MemoryToPeripheral;
//	DMA_InitStruct.DMA_Memory0BaseAddr = (uint32_t)(dma_message);//Will contain the memory buffer address.
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal; //To enable the double buffer mode.
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&(UART4->DR);
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_InitStruct.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStruct.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_InitStruct.DMA_FIFOMode = DMA_FIFOMode_Disable;

	DMA_Init(DMA1_Stream4,&DMA_InitStruct);

	USART_DMACmd(UART4,USART_DMAReq_Tx,ENABLE);
	USART_Cmd(UART4,ENABLE);	//Send the idle-frame.
}

uint16_t inline UART_DMA_print(uint8_t *message, uint16_t len){
		if(!(DMA1_Stream4->CR & DMA_SxCR_EN)){

			UART4->SR &= ~USART_SR_TC;

			DMA1_Stream4->M0AR = (uint32_t)message;
			DMA1_Stream4->NDTR = len;
			DMA1_Stream4->CR |= DMA_SxCR_EN;
			return len;
		}

		return 0;
};

void UART_print(char *message,uint16_t len){
	int i=0;
	for(i = 0;i<len;++i){
		while(!(UART4->SR & USART_SR_TC)){};
		UART4->DR = *(((uint8_t *)message)+i);
	}
};
