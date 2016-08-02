ORG 0000H
LJMP MAIN

ADDER_N:
	MOV A,50h        ;Loading the value of n
	ANL A,#0FFh      ;Checking if n=0
	JZ RETURN        ;Quitting subroutine if n=0
	MOV R0, #50h
	MOV R2, A        ;Loading R0 with n
	MOV R1,#01h      ;Setting the first addend, R1 with 1
	CLR A            ;Setting A=0
	
	ADD_NEXT:
		ADD A,R1     ;Adding A with R1
		MOV @R0,A    ;Storing A in next memory location
		INC R0		 ;Increment memory location
		INC R1       ;Incrementing R1
	DJNZ R2,ADD_NEXT ;Decrementing R0 till we hit zero
	
	RETURN:
	RET

INIT:
	MOV 50h, #10h ;Deciding the value of n in memory
	RET


ORG 0100H
MAIN:
	MOV SP,#0C0H
	ACALL INIT    ;Initializing the memory with n
	ACALL ADDER_N ;Adding natural numbers from 1 to n
A1:  
	SJMP A1
END