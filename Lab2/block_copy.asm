ORG 00H
LJMP MAIN


ORG 100H
	memcpy:
	USING 0
		PUSH PSW
		PUSH AR0
		PUSH AR1
		PUSH AR2
		PUSH ACC
		PUSH B
		MOV R2, 50h
		MOV R1, 51h
		MOV R0, 52h
		MOV A, R0
		MOV B, R1
		CJNE A, B, NEXT0
		NEXT0: JC REPEAT
			ADD A, R2
			MOV R0, A
			DEC R0
			MOV A, R1
			ADD A, R2
			MOV R1, A
			DEC R1
		REPEAT:
			MOV A,@R1
			MOV @R0,A
			MOV A, R0
			MOV B, R1
			CJNE A, B, NEXT
			NEXT: JC INCREMENT
				DEC R0
				DEC R0
				DEC R1
				DEC R1
			INCREMENT:
				INC R0
				INC R1
			DJNZ R2, REPEAT
		POP B
		POP ACC
		POP AR2
		POP AR1
		POP AR0
		POP PSW
		RET
	
	
MAIN:
	LCALL memcpy

STOP: SJMP STOP
END