ORG 0000H
LJMP MAIN

ADDER_8BIT:
	MOV A, 50h ;Loading first value
	ADD A, 60h ;Adding second value to first
	MOV 70h, A ;Moving answer to correct address
	RETURN:	
	CLR A      ;Finishing program
	RET

INIT:
	MOV 50h, #30h ;Loading the first value
	MOV 60h, #40h ;Loading the second value
	RET

ORG 0100H
MAIN:
	MOV SP,#0C0H
	;ACALL INIT 		 ;Loading the values in memory
	ACALL ADDER_8BIT ;Adding the two values


A1:  
	SJMP A1
