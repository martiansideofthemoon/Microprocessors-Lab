; This subroutine writes characters on the LCD
LCD_data equ P2    ;LCD Data port
LCD_rs   equ P0.0  ;LCD Register Select
LCD_rw   equ P0.1  ;LCD Read/Write
LCD_en   equ P0.2  ;LCD Enable
switches equ p1
led equ p1

ORG 0000H
ljmp start

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

displayValues:
	using 0
	push acc
	push ar1
	mov led, #0A0h
	acall delay_5s
loop_display:
	mov r1, 51h
	mov a, 50h
	mov led, #0F0h
	acall delay_1s
	acall delay_1s
	acall readnibble
	mov led, #00h
	acall delay_1s
	cjne a, 4fh, check_index
	sjmp exit_display
check_index:
	jc exit_display
	mov a, r1
	add a, 4fh
	mov r1, a
	acall lcd_sendbyte
	sjmp loop_display
exit_display:
	acall lcd_init
	pop ar1
	pop acc
	ret
	
lcd_sendbyte:
	push acc
	mov a, @r1
	acall lcd_senddata
	pop acc
	ret

readValues:
	using 0
	push ar0
	push ar1
	mov led, #0B0h
	acall delay_5s
	mov r0, 50h	
	mov r1, 51h
loop_read:
	acall packnibbles
	mov @r1, 4fh
	inc r1
	djnz r0, loop_read
	pop ar1
	pop ar0
	ret

packnibbles:
	push acc
	mov led, #0F0h
	acall delay_5s
	acall readnibble
	mov a, 4fh
	swap a
	mov led, #00h
	acall delay_1s
	mov led, #0F0h
	acall delay_5s
	acall readnibble
	mov led, #00h
	acall delay_1s
	add a, 4fh
	mov 4fh, a
	pop acc
	ret

readnibble:
	push acc
	orl switches,#0fh	; 1 for input
	mov a,switches		; read switches
	anl a,#0fh
	mov 4fh,a
	pop acc
	ret

org 200h
start:
	  mov 50h, #02h
	  mov 51h, #52h

      mov P2,#00h
      mov P1,#00h
	  ;initial delay for lcd power up

	;here1:setb p1.0
      	  acall delay
	;clr p1.0
	  acall delay
	;sjmp here1


	  acall lcd_init      ;initialise LCD
	
	  acall delay
	  acall delay
	  acall delay
	  mov a,#80h		 ;Put cursor on first row,5 column
	  acall lcd_command	 ;send command to LCD
	  acall delay
	  acall readValues
	  acall displayValues

here: sjmp here				//stay here 

;------------------------LCD Initialisation routine----------------------------------------------------
lcd_init:
         mov   LCD_data,#38H  ;Function set: 2 Line, 8-bit, 5x7 dots
         clr   LCD_rs         ;Selected command register
         clr   LCD_rw         ;We are writing in instruction register
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en
	     acall delay

         mov   LCD_data,#0CH  ;Display on, Curson off
         clr   LCD_rs         ;Selected instruction register
         clr   LCD_rw         ;We are writing in instruction register
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en
         
		 acall delay
         mov   LCD_data,#01H  ;Clear LCD
         clr   LCD_rs         ;Selected command register
         clr   LCD_rw         ;We are writing in instruction register
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en
         
		 acall delay
         mov   LCD_data,#06H  ;Entry mode, auto increment with no shift
         clr   LCD_rs         ;Selected command register
         clr   LCD_rw         ;We are writing in instruction register
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en

		 acall delay
         
         ret                  ;Return from routine

;-----------------------command sending routine-------------------------------------
 lcd_command:
         mov   LCD_data,A     ;Move the command to LCD port
         clr   LCD_rs         ;Selected command register
         clr   LCD_rw         ;We are writing in instruction register
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en
		 acall delay
    
         ret  
;-----------------------data sending routine-------------------------------------		     
 lcd_senddata:
         mov   LCD_data,A     ;Move the command to LCD port
         setb  LCD_rs         ;Selected data register
         clr   LCD_rw         ;We are writing
         setb  LCD_en         ;Enable H->L
		 acall delay
         clr   LCD_en
         acall delay
		 acall delay
         ret                  ;Return from busy routine

;-----------------------text strings sending routine-------------------------------------
lcd_sendstring:
	push 0e0h
	lcd_sendstring_loop:
	 	 clr   a                 ;clear Accumulator for any previous data
	         mov  a,@r1         	;load the first character in accumulator
	         jz    exit              ;go to exit if zero
	         acall lcd_senddata      ;send first char
	         inc   r1              ;increment data pointer
	         sjmp  LCD_sendstring_loop    ;jump back to send the next character
exit:    pop 0e0h
         ret                     ;End of routine

;----------------------delay routine-----------------------------------------------------
delay:	 push 0
	 push 1
         mov r0,#1
loop2:	 mov r1,#255
	 loop1:	 djnz r1, loop1
	 djnz r0, loop2
	 pop 1
	 pop 0 
	 ret

;------------- ROM text strings---------------------------------------------------------------
org 300h
my_string1:
         DB   "EE337 - Lab 2", 00H
my_string2:
		 DB   "Kalpesh Krishna", 00H
end

