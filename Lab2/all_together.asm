LED	EQU P1
ORG 00H
LJMP MAIN
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
		NEXT0: JC REPEAT1
			ADD A, R2
			MOV R0, A
			DEC R0
			MOV A, R1
			ADD A, R2
			MOV R1, A
			DEC R1
		REPEAT1:
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
			DJNZ R2, REPEAT1
		POP B
		POP ACC
		POP AR2
		POP AR1
		POP AR0
		POP PSW
		RET

	zeroOut:
	USING 0
		PUSH PSW
		PUSH AR1
		PUSH AR2
		MOV R2, 50h
		MOV R1, 51h
		REPEAT2:
			MOV @R1, #00h
			INC R1
			DJNZ R2, REPEAT2
		POP AR2
		POP AR1
		POP PSW
		RET

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

display:
	USING 0
		PUSH PSW
		PUSH AR1
		PUSH AR2
		PUSH ACC
		MOV R2, 50h
		MOV R1, 51h
		REPEAT3:
			MOV A, @R1
			ANL A, #0F0h
			MOV LED, A
			LCALL DELAY
			INC R1
			DJNZ R2, REPEAT3
		POP ACC
		POP AR2
		POP AR1
		POP PSW
		RET


ORG 0200H
MAIN:
MOV SP,#0CFH;-----------------------Initialize STACK POINTER

MOV 50H,#03h;------------------------No of memory locations of Array A
MOV 51H,#52h;------------------------Array A start location
LCALL zeroOut;----------------------Clear memory

MOV 50H,#03h;------------------------No of memory locations of Array B
MOV 51H,#55h;------------------------Array B start location
LCALL zeroOut;----------------------Clear memory

MOV 50H,#03h;------------------------No of memory locations of source array
MOV 51H,#58h;------------------------Source array start location
MOV 52H,#52h;------------------------Destination array(A) start location
LCALL bin2ascii;--------------------Write at memory location

MOV 50H,#06h;------------------------No of elements of Array A to be copied in Array B
MOV 51H,#52h;------------------------Array A start location
MOV 52H,#61h;------------------------Array B start location
LCALL memcpy;-----------------------Copy block of memory to other location

MOV 50H,#06h;------------------------No of memory locations of Array B
MOV 51H,#61h;------------------------Array B start location
MOV 4FH,#02h;------------------------User defined delay value
LCALL display;----------------------Display the last four bits of elements on LEDs

here:SJMP here;---------------------WHILE loop(Infinite Loop)

END