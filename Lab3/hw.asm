LED	EQU P1
org 00h
	ljmp main
DELAY:
	USING 0		;ASSEMBLER DIRECTIVE TO INDICATE REGISTER BANK0
        PUSH PSW
        PUSH AR1	; STORE R1 (BANK O) ON THE STACK
        PUSH AR2
		PUSH AR3
		PUSH B
		PUSH ACC
		MOV A,4Fh
		MOV B,#20
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
		POP ACC
		POP B
		POP AR3
		POP AR2
        POP AR1
        POP PSW
        RET	
org 100h
main:
	sjmp loop
old_data:
	MOV A, 4EH			;display data from 4eh
	ANL A, #0Fh
	MOV LED, A
	lcall readnibble		;read the input on P1.0-P1.3 (nibble)
	MOV A, 4Eh
	CJNE A, #0Fh, loop	;if read value != 0Fh go to loop
	RET 					;else return to caller with previously read nibble in location 4EH (lower 4 bits).
	
loop:
	SETB P1.7		;turn on all 4 leds (routine is ready to accept input)
	SETB P1.6
	SETB P1.5
	SETB P1.4
	MOV 4Fh, #05h
	LCALL DELAY			;wait for 5 sec during which user can give input 
	CLR P1.7
	CLR P1.6
	CLR P1.5
	CLR P1.4
	lcall readnibble	;read the input on P1.0-P1.3 (nibble)
	MOV 4Fh, #01h
	LCALL DELAY  		;wait for one sec
	MOV A, 4Eh
	SWAP A
	MOV LED, A
	MOV 4Fh, #05h
	LCALL DELAY  		;wait for 5 sec 
	
	CLR P1.7
	CLR P1.6
	CLR P1.5
	CLR P1.4
	MOV A, LED
	CJNE A, #0Fh, loop	;read the input from switches
 			;if read value != 0Fh go to loop
	RET					;else return to caller with previously read nibble in location 4EH (lower 4 bits).
						
						
stop:
	sjmp stop
	
readnibble:
	MOV A, LED			; set pins 0-3 for configuring as input pins
	ANL A, #0Fh			; read value on pins
	MOV 4Eh, A
	RET
END