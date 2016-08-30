org 00h
	ljmp main
org 000Bh
	sjmp isr_timer0
org 50h
isr_timer0:
	INC R1
	CLR TR0
	CLR TF0
	MOV TL0, #00h
	MOV TH0, #00h
	SETB TR0
	reti
delay_1s:
	SETB EA
	SETB ET0
	USING 0
	PUSH AR1
	MOV TMOD, #01h
	MOV TL0, #00h
	MOV TH0, #00h
	SETB TR0
this:
	CJNE R1, #1Fh, this
	CLR ET0
	CLR EA
	POP AR1
	ret


org 100h
main:
	CLR P1.7
	acall delay_1s
	SETB P1.7
stop:
	sjmp stop

	
END