LED	EQU P1.7	
ORG 00H
LJMP MAIN


ORG 100H
DELAY:
	USING 0		;ASSEMBLER DIRECTIVE TO INDICATE REGISTER BANK0
        PUSH PSW
        PUSH AR1	; STORE R1 (BANK O) ON THE STACK
        PUSH AR2
		PUSH AR3
		PUSH ACC
		PUSH B
		
		MOV A,4Fh
		MOV B,#10
		MUL AB
		MOV R3,A
		BACK0:
			MOV R2,#200
			BACK1:
				MOV R1,#0FFH
				BACK2:
					DJNZ R1, BACK2
				DJNZ R2, BACK1
			DJNZ R3, BACK0
		
		POP B
		POP ACC
		POP AR3
		POP AR2
        POP AR1
        POP PSW
        RET


MAIN:
		SETB LED
		LCALL DELAY
		CLR LED
		LCALL DELAY
		SJMP MAIN
END

