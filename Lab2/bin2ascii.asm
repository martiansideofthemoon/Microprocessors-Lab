ORG 00H
LJMP MAIN


ORG 100H
	bin2ascii:
	USING 0
		PUSH PSW
		PUSH AR0
		PUSH AR1
		PUSH AR2
		PUSH ACC
		MOV R2, 50h
		MOV R1, 51h
		MOV R0, 52h
		REPEAT:
			MOV A,@R1
			ANL A,#0F0h
			RR A
			RR A
			RR A
			RR A
			CJNE A, #0Ah, NEXT3
			NEXT3:
				JC NUMBER3
				ADD A,#07h
			NUMBER3:
			ADD A,#30h
			MOV @R0,A
			INC R0
			MOV A,@R1
			ANL A,#0Fh
			CJNE A, #0Ah, NEXT4
			NEXT4:
				JC NUMBER4
				ADD A,#07h
			NUMBER4:
			ADD A,#30h
			MOV @R0,A
			INC R0
			INC R1
			DJNZ R2,REPEAT
		POP ACC
		POP AR2
		POP AR1
		POP AR0
		POP PSW
		RET
	
	
MAIN:
	LCALL bin2ascii

STOP: SJMP STOP
END