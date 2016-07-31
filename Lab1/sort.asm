ORG 0000H
LJMP MAIN

;R0 and R1 should contain the address of two no.s
;location given by R0:- 	MSB of 1st no.
;location given by R0+1:-	LSB of 1st no.
;location given by R1:- 	MSB of 1st no.
;location given by R1+1:-	LSB of 1st no.
;location given by R0+2:- 	CARRY	
;location given by R0+3:-	MSB OF ANS	
;location given by R0+4:- 	LSB OF ANS

;---------------------------------------------------------;
;this function adds and stores result in appropriate location
SORT:
	MOV R0,#60h
	MOV R1,#70h
SWAP1:	
	MOV A,@R0
	MOV @R1,A
	INC R0
	INC R1
	CJNE R0,#66h,SWAP1
	
	MOV R0,#70h
	MOV R1,#71h
	
START:
	MOV A,@R0
	MOV B,@R1
	CJNE A,B,NEXT0
NEXT0:
	JC NO_SWAP
	MOV A,@R0
	MOV R2,A
	MOV A,@R1
	MOV @R0,A
	MOV A,R2
	MOV @R1,A
NO_SWAP:
	INC R1
	CJNE R1,#76h,START
	INC R0
	MOV A,R0
	INC A
	MOV R1,A
	CJNE R0,#75h,START
	RETURN:
	RET

INIT:
	;-- store the numbers to be added/subtracted at appropriate location
	MOV 60h,#0AAh
	MOV 61h,#0BBh
	MOV 62h,#0CCh
	MOV 63h,#0DDh
	MOV 64h,#0EEh
	RET


ORG 0100H
MAIN:
	MOV SP,#0C0H	;move stack pointer to indirect RAM location
	ACALL INIT
	ACALL SORT
END
