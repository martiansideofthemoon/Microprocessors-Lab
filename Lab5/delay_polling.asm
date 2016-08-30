org 00h
	ljmp main
org 50h
delay_1s:
	USING 0
	PUSH AR1
	MOV R1, #1Fh
timer:
	MOV TMOD, #01h
	MOV TL0, #00h
	MOV TH0, #00h
	SETB TR0
	acall poll
	CLR TR0
	CLR TF0
	DJNZ R1, timer
	POP AR1
	ret
	
poll:
	JNB TF0, poll
	ret

org 100h
main:
	CLR P1.7
	acall delay_1s
	SETB P1.7
stop:
	sjmp stop

	
END