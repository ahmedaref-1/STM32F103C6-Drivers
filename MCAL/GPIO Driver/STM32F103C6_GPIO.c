/*
 * STM32F103C6_EXTERNALINTERRUPTS.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Ahmed Aref Omaira
 */
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "STM32F103C6_GPIO.h"


/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/*******************************************
 *      INTERNALLY USED FUNCITONS          *
 * *****************************************/
void ConfigurationPin(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig , uint8_t Configuration , uint8_t PinCNFMask)
{
	if(Configuration == LOW)
	{
		switch(PinConfig->GPIO_PinNumber)
		{
		case GPIO_PIN_0 :
			GPIOx->CRL.CNF0 = PinCNFMask;
			GPIOx->CRL.MODE0 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_1 :
			GPIOx->CRL.CNF1 = PinCNFMask;
			GPIOx->CRL.MODE1 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_2 :
			GPIOx->CRL.CNF2 = PinCNFMask;
			GPIOx->CRL.MODE2 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_3 :
			GPIOx->CRL.CNF3 = PinCNFMask;
			GPIOx->CRL.MODE3 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_4 :
			GPIOx->CRL.CNF4 = PinCNFMask;
			GPIOx->CRL.MODE4 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_5 :
			GPIOx->CRL.CNF5 = PinCNFMask;
			GPIOx->CRL.MODE5 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_6 :
			GPIOx->CRL.CNF6 = PinCNFMask;
			GPIOx->CRL.MODE6 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_7 :
			GPIOx->CRL.CNF7 = PinCNFMask;
			GPIOx->CRL.MODE7 = PinConfig->GPIO_OutputSpeed;
			break;
		}
	}
	else
	{
		switch(PinConfig->GPIO_PinNumber)
		{
		case GPIO_PIN_8 :
			GPIOx->CRH.CNF8 = PinCNFMask;
			GPIOx->CRH.MODE8 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_9 :
			GPIOx->CRH.CNF9 = PinCNFMask;
			GPIOx->CRH.MODE9 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_10 :
			GPIOx->CRH.CNF10 = PinCNFMask;
			GPIOx->CRH.MODE10 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_11 :
			GPIOx->CRH.CNF11 = PinCNFMask;
			GPIOx->CRH.MODE11 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_12 :
			GPIOx->CRH.CNF12 = PinCNFMask;
			GPIOx->CRH.MODE12 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_13 :
			GPIOx->CRH.CNF13 = PinCNFMask;
			GPIOx->CRH.MODE13 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_14 :
			GPIOx->CRH.CNF14 = PinCNFMask;
			GPIOx->CRH.MODE14 = PinConfig->GPIO_OutputSpeed;
			break;

		case GPIO_PIN_15 :
			GPIOx->CRH.CNF15 = PinCNFMask;
			GPIOx->CRH.MODE15 = PinConfig->GPIO_OutputSpeed;
			break;
		}
	}

}


/*******************************************
 *        EXTERNALLY USED FUNCITONS        *
 *******************************************/
/********************************************************************************
  Fn                -MCAL_GPIO_Init
  Brief             -Initializes the GPIOx PINy according to the specified
                     parameters in the PinConfig.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -PinConfig: is a pointer to GPIO_PinConfig_t structure that
                     contains the configuration information for the specified
                     GPIO PIN.

  Retval            -None.

  Note              -STM32F103C6 MCU has GPIO A,B,C,D and E Modules but LQFP4
                     package has only GPIO A,B and part of C AND D exported as
                     external PINs from the MCU.
 ******************************************************************************/
void MCAL_GPIO_Init(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	// Port configuration register low  (GPIOx_CRL) (x=A..G) configure pin 0..7
	// Port configuration register high (GPIOx_CRH) (x=A..G) configure pin 8..15
	volatile uint8_t ConfigurationRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? LOW : HIGH;

	switch(PinConfig->GPIO_Mode)
	{
	case GPIO_MODE_Analog :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Analog_MASK );
		break;

	case GPIO_MODE_Input_FLO :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Input_FLO_MASK );
		break;

	case GPIO_MODE_Input_PU :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Input_PU_MASK );
		//Input pull-up, then ODRx.Pinx must be set
		GPIOx->ODR.ODR |= PinConfig->GPIO_PinNumber;
		break;

	case GPIO_MODE_Input_PD :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Input_PD_MASK );
		//Input pull-up, then ODRx.Pinx must be reset
		GPIOx->ODR.ODR &= ~(PinConfig->GPIO_PinNumber);
		break;

	case GPIO_MODE_Output_PP :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Output_PP_MASK );
		break;

	case GPIO_MODE_Output_OD :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Output_OD_MASK );
		break;

	case GPIO_MODE_Output_AF_PP :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Output_AF_PP_MASK );
		break;

	case GPIO_MODE_Output_AF_OD :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Output_AF_OD_MASK );
		break;

	case GPIO_MODE_Input_AF :
		ConfigurationPin(GPIOx , PinConfig , ConfigurationRegister, GPIO_CNF_Input_AF_MASK );
		break;
	}

}



/*******************************************************************************
  Fn                -MCAL_GPIO_DeInit

  Brief             -Reset all the GPIO Registers.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Retval            -None.

 Note              	-None.
 *******************************************************************************/
void MCAL_GPIO_DeInit (GPIO_t* GPIOx)
{
	/*
	1st method by reset all GPIOx registers
	GPIOx->CRL 	=  0x44444444;
	GPIOx->CRH 	=  0x44444444;
	*/
	/*
	GPIOx->IDR  Read Only
	 */
	/*
	GPIOx->ODR 	=  0x00000000;
	GPIOx->BSRR =  0x00000000;
	GPIOx->BRR 	=  0x00000000;
	GPIOx->LCKR =  0x00000000;
	*/

	/*
	2nd method APB2 peripheral reset register (RCC_APB2RSTR)
	Set and cleared by software.
	*/

	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR.IOPARST = TRUE;
		RCC->APB2RSTR.IOPARST = FALSE;
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR.IOPBRST = TRUE;
		RCC->APB2RSTR.IOPBRST = FALSE;
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR.IOPCRST = TRUE;
		RCC->APB2RSTR.IOPCRST = FALSE;
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR.IOPDRST = TRUE;
		RCC->APB2RSTR.IOPDRST = FALSE;
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR.IOPERST = TRUE;
		RCC->APB2RSTR.IOPERST = FALSE;
	}
	else //Reset all Ports
	{
		RCC->APB2RSTR.APB2RSTR = TRUE;
		RCC->APB2RSTR.APB2RSTR = FALSE;
	}

}



/*******************************************************************************
  Fn                -MCAL_GPIO_ReadPin

  Brief             -Read specific PIN.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -PinNumber: set pin number according @ref GPIO_PINS_define.

  Retval            -The input pin value.

  Note              -None.
 ******************************************************************************/
uint8_t  MCAL_GPIO_ReadPin (GPIO_t* GPIOx , uint16_t PinNumber)
{

	/*
	 1st method : reading from PIN directly

	switch(PinNumber)
	{
	case GPIO_PIN_0 :
		return (GPIOx->IDR.PIN_0);
	case GPIO_PIN_1 :
		return (GPIOx->IDR.PIN_1);
	case GPIO_PIN_2 :
		return (GPIOx->IDR.PIN_2);
	case GPIO_PIN_3 :
		return (GPIOx->IDR.PIN_3);
	case GPIO_PIN_4 :
		return (GPIOx->IDR.PIN_4);
	case GPIO_PIN_5 :
		return (GPIOx->IDR.PIN_5);
	case GPIO_PIN_6 :
		return (GPIOx->IDR.PIN_6);
	case GPIO_PIN_7 :
		return (GPIOx->IDR.PIN_7);
	case GPIO_PIN_8 :
		return (GPIOx->IDR.PIN_8);
	case GPIO_PIN_9 :
		return (GPIOx->IDR.PIN_9);
	case GPIO_PIN_10 :
		return (GPIOx->IDR.PIN_10);
	case GPIO_PIN_11 :
		return (GPIOx->IDR.PIN_11);
	case GPIO_PIN_12 :
		return (GPIOx->IDR.PIN_12);
	case GPIO_PIN_13 :
		return (GPIOx->IDR.PIN_13);
	case GPIO_PIN_14 :
		return (GPIOx->IDR.PIN_14);
	case GPIO_PIN_15 :
		return (GPIOx->IDR.PIN_15);
	}*/

	/*
	2nd method : compare IDR Register with PIN and return either 1 or 0

	*/
	return ((((GPIOx->IDR.IDR) & PinNumber) == PinNumber)? HIGH : LOW);
}



/*******************************************************************************
  Fn                -MCAL_GPIO_ReadPort

  Brief             -Read specific PORT.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Retval            -The input port value.

  Note              -None.
 ******************************************************************************/
uint16_t  MCAL_GPIO_ReadPort (GPIO_t* GPIOx)
{
	uint16_t portValue = 0;
	portValue = GPIOx->IDR.IDR;
	return portValue;
}



/*******************************************************************************
  Fn                -MCAL_GPIO_WritePort

  Brief             -Write on specific PIN.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -PinNumber: specifies the port pin to write on it, set pin
                     number according @ref GPIO_PINS_define

  Param [in]        -Value: Pin value.

  Retval            -None.

  Note              -None.
 ******************************************************************************/
void MCAL_GPIO_WritePin (GPIO_t* GPIOx , uint16_t PinNumber , uint8_t Value)
{
	/******** 1 - Using GPIOx->ODR to write on it ********/
	// 1st method : writing on PIN directly
	/*switch(PinNumber)
	{
	case GPIO_PIN_0 :
		(GPIOx->ODR.PIN_0) = Value;
	case GPIO_PIN_1 :
		(GPIOx->ODR.PIN_1) = Value;
	case GPIO_PIN_2 :
		(GPIOx->ODR.PIN_2) = Value;
	case GPIO_PIN_3 :
		(GPIOx->ODR.PIN_3) = Value;
	case GPIO_PIN_4 :
		(GPIOx->ODR.PIN_4) = Value;
	case GPIO_PIN_5 :
		(GPIOx->ODR.PIN_5) = Value;
	case GPIO_PIN_6 :
		(GPIOx->ODR.PIN_6) = Value;
	case GPIO_PIN_7 :
		(GPIOx->ODR.PIN_7) = Value;
	case GPIO_PIN_8 :
		(GPIOx->ODR.PIN_8) = Value;
	case GPIO_PIN_9 :
		(GPIOx->ODR.PIN_9) = Value;
	case GPIO_PIN_10 :
		(GPIOx->ODR.PIN_10) = Value;
	case GPIO_PIN_11 :
		(GPIOx->ODR.PIN_11) = Value;
	case GPIO_PIN_12 :
		(GPIOx->ODR.PIN_12) = Value;
	case GPIO_PIN_13 :
		(GPIOx->ODR.PIN_13) = Value;
	case GPIO_PIN_14 :
		(GPIOx->ODR.PIN_14) = Value;
	case GPIO_PIN_15 :
		(GPIOx->ODR.PIN_15) = Value;
	}*/

	// 2nd method : write on ODR register Directly
	if (Value == HIGH || Value == TRUE)
		GPIOx->ODR.ODR |= PinNumber;
	else
		GPIOx->ODR.ODR &= ~(PinNumber);

	/******** 2 - Using GPIOx->BSRR & GPIOx->BRR  to write on it ********/
	/*********  CAUTION THIS METHOD DIDN'T WORK  ************************/
	/*
	if (Value == HIGH || Value == TRUE || GPIO_PIN_SET)
		GPIOx->BSRR.BS |= (uint16_t)PinNumber;
	else
		GPIOx->BSRR.BR |= (uint16_t)PinNumber;
	*/

}



/*******************************************************************************
  Fn                -MCAL_GPIO_WritePort

  Brief             -Write on specific PORT.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -Value: Port value.

  Retval            -None.

  Note              -None.
 *****************************************************************************/
void MCAL_GPIO_WritePort    (GPIO_t* GPIOx , uint16_t Value)
{
	GPIOx->ODR.ODR  = (uint16_t)Value;
}




/*******************************************************************************
  Fn                -MCAL_GPIO_TogglePin

  Brief             -Toggle a specific pin in GPIOx.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -PinNumber: specifies the port pin to toggle it, set pin
                     number according @ref GPIO_PINS_define.

  Retval            -None.

  Note              -None.
 *****************************************************************************/
void MCAL_GPIO_TogglePin    (GPIO_t* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR.ODR ^= PinNumber;
}



/*******************************************************************************
  Fn                -MCAL_GPIO_TogglePORT

  Brief             -Toggle GPIOx PORT.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Retval            -None.

  Note              -None.
 ********************************************************************************/
void MCAL_GPIO_TogglePORT(GPIO_t* GPIOx)
{
	GPIOx->ODR.ODR ^= (uint16_t)GPIO_PORT_SET;
}



/*******************************************************************************
  Fn                -MCAL_GPIO_LockPin

  Brief             -The locking mechanism allows the IO configuration to be
                     frozen.

  Param [in]        -GPIOx: where x can be (A..E depending on device used) to
                     select the GPIO Peripheral.

  Param [in]        -PinNumber: specifies the port pin to lock it, set pin
                     number according @ref GPIO_PINS_define.

  Retval            -DONE if PinConfig is locked or ERROR if pin not locked
                     Return_t is defined at @ref GLOBAL_ENUM.

  Note              -During the LOCK Key Writing sequence, the value of
                     LCK[15:0] must not change. Any error in the lock
                     sequence will abort the lock.
 ******************************************************************************/
Return_t MCAL_GPIO_LockPin   (GPIO_t* GPIOx , uint16_t PinNumber)
{
	// These bits are read write but can only be written when the LCKK bit is 0.
	GPIOx->LCKR.LCKR |= PinNumber;

	/*
	 This bit can be read anytime.
	 It can only be modified using the Lock Key Writing Sequence.
  	 LOCK key writing sequence:
     Write 1
     Write 0
     Write 1
     Read 0
	 Read 1 (this read is optional but confirms that the lock is active)
	*/
	GPIOx->LCKR.LCKK = TRUE;
	GPIOx->LCKR.LCKK = FALSE;
	GPIOx->LCKR.LCKK = TRUE;
	return ((GPIOx->LCKR.LCKK == TRUE)? GPIO_RETURN_LOCK_SUCCESS : GPIO_RETURN_LOCK_FAIL);
}

