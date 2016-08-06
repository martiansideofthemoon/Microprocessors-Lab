ORG 00H
LJMP MAIN


ORG 100H
	bin2ascii:
	USING 0
		PUSH PSW
		PUSH AR0
		PUSH AR1
		PUSH AR2
		PUSH AR3
		PUSH ACC
		PUSH B
		MOV R2, 50h
		MOV R1, 51h
		MOV R0, 52h
		REPEAT:
			MOV A,@R1
			INC R1
			MOV B,#10
			DIV AB
			MOV R3,B
			MOV B,#10
			DIV AB
			MOV A,B
			ADD A,#30h
			MOV @R0,A
			INC R0
			MOV A,R3
			ADD A,#30h
			MOV @R0,A
			INC R0
			DJNZ R2,REPEAT
		POP B
		POP ACC
		POP AR3
		POP AR2
		POP AR1
		POP AR0
		POP PSW
		RET
	
	
MAIN:
	LCALL bin2ascii

STOP: SJMP STOP
END