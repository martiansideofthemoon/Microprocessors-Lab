LED	EQU P1
org 00h
	ljmp main
DELAY:
	USING 0
        PUSH PSW
        PUSH AR1
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
	MOV A, 4EH
	ANL A, #0Fh
	SWAP A
	MOV LED, A
	MOV 4Fh, #05h
	LCALL DELAY
	lcall readnibble
	CJNE A, #0Fh, value_changed
	SJMP old_data
	
loop:
	SETB P1.7
	SETB P1.6
	SETB P1.5
	SETB P1.4
	MOV 4Fh, #05h
	LCALL DELAY 
	CLR P1.7
	CLR P1.6
	CLR P1.5
	CLR P1.4
	MOV 4Fh, #01h
	LCALL DELAY
	lcall readnibble
value_changed:
	MOV 4Eh, A
	SWAP A
	MOV LED, A
	MOV 4Fh, #05h
	LCALL DELAY
	CLR P1.7
	CLR P1.6
	CLR P1.5
	CLR P1.4
	LCALL readnibble
	CJNE A, #0Fh, loop
	SJMP old_data
						
						
stop:
	sjmp stop
	
readnibble:
	SETB P1.0
	SETB P1.1
	SETB P1.2
	SETB P1.3
	MOV A, LED
	ANL A, #0Fh
	RET
END