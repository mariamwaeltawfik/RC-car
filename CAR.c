/*
 * CAR.c
 *
 * Created: 12/21/2023 12:09:23 AM
 *  Author: NOTEBOOK
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "MOTOR_Cfg.h"
#include "CAR.h"

void MOVE_Init(void){
DIO_WritePin(PINC4,HIGH);
DIO_WritePin(PINC5,HIGH);
DIO_WritePin(PINA4,HIGH);
DIO_WritePin(PINA5,HIGH);


	
}
static void TURN_Right(void){
	
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
}
static void TURN_Left(void){
	
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);

}
static void GO_Forward(void){
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
}
 static void GO_Backward(void){
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);

	
}
void MOVE_Runnable(void){
	if(!DIO_ReadPin(PIND2)){
		TURN_Right();
		while(!DIO_ReadPin(PIND2));
	}
	if(!DIO_ReadPin(PIND4)){
		TURN_Left();
		while(!DIO_ReadPin(PIND4));
	}
	if(!DIO_ReadPin(PIND3)){
		GO_Backward();
		while(!DIO_ReadPin(PIND3));
	}
	if(!DIO_ReadPin(PIND5)){
		GO_Forward();
		while(!DIO_ReadPin(PIND5));
	}
}