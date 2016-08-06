ORG 00H
LJMP MAIN


ORG 100H
	zeroOut:
	USING 0
		PUSH PSW
		PUSH AR1
		PUSH AR2
		MOV R2, 50h
		MOV R1, 51h
		REPEAT:
			MOV @R1, #00h
			INC R1
			DJNZ R2, REPEAT
		POP AR2
		POP AR1
		POP PSW
		RET
	
	
MAIN:
	LCALL zeroOut

STOP: SJMP STOP
END