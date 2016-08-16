switches equ p1
leds equ p1

org 00h
	ljmp main

org 100h
main:
	sjmp loop
disp_old:
	lcall led_display	
	lcall readnibble
	mov a,4fh
	cjne a,#0fh,disp_old
	sjmp notff
loop:
	orl leds,#0f0h		; all leds ON
	lcall delay_5s
	anl leds,#0fh		; 0 for output
	lcall readnibble
notff:
	lcall delay_1s
	mov a,4fh
	mov 4eh,a
	lcall led_display
	lcall readnibble
	mov a,4fh
	cjne a,#0fh,disp_old
	sjmp main
	
stop:
	sjmp stop
	
readnibble:
	push acc
	orl switches,#0fh	; 1 for input
	mov a,switches		; read switches
	anl a,#0fh
	mov 4fh,a
	pop acc
	ret
	
delay_1s:
	using 0
	push ar1			; for 1 sec delay
	push ar2
	push ar3
	mov r3,#20		; 20 iterations of 50 ms
back2:
	mov r2,#200
back1:
	mov r1,#0FFH
back:

	djnz r1, back
	djnz r2, back1
	djnz r3, back2
	pop ar3
	pop ar2
	pop ar1
	ret
	
delay_5s:
	push ar4
	mov r4,#5
sec1:
	lcall delay_1s
	djnz r4,sec1
	pop ar4
	ret
	
led_display:
	push acc
	anl leds,#0fh		; 0 for output
	mov 4eh,a
	swap a
	orl leds,a
	lcall delay_5s
	anl leds,#0fh
	pop acc
	
end