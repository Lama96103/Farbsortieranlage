/****************************************************
	ISRs - Interrupt Handlers
****************************************************/
#include "global.h"


void EXTI15_10_IRQHandler()
{

    if (EXTI_GetFlagStatus(EXTI_Line10) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line10);
    }
    if (EXTI_GetFlagStatus(EXTI_Line11) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line11);
    }
    if (EXTI_GetFlagStatus(EXTI_Line12) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
    if (EXTI_GetFlagStatus(EXTI_Line13) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
    if (EXTI_GetFlagStatus(EXTI_Line14) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line14);
    }
    if (EXTI_GetFlagStatus(EXTI_Line15) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_Line15);
    }
}


void USART1_IRQHandler(void)
{
    /*
    if(indexColor > 3){
        colorflag = false;
        indexColor = 0;
    }

    if((char)USART_ReceiveData(USART1) == '#')
        {
            //led_toggle();
            color = 0;
            colorflag = true;
        }

    if(!colorflag){
        charInput[indexChar] = (char)USART_ReceiveData(USART1);
        indexChar >= CHARLEN-1 ? indexChar = 0 : indexChar++;
    }
    if(colorflag){
        charColor[indexColor] = (char)USART_ReceiveData(USART1);
        color += ((char)USART_ReceiveData(USART1)<<(8*indexColor));
        indexColor++;
        if(indexColor>3){
            color>>=8;
        }

    }

    if((char)USART_ReceiveData(USART1) == '$')
    {
        //led_toggle();
        renderflag = true;
    }
    */
}

void TIM6_IRQHandler (){

    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);

    ColorSortTick();
}
