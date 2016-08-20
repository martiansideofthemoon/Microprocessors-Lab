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
	
lcd_sendbyte:
	push acc
	mov a, @r1
	acall lcd_senddata
	pop acc
	ret

readSwitches:
	mov led, #0A0h
	acall delay_5s
	mov led, #00h
	acall delay_1s
	acall readnibble
	mov a, 4fh
	mov led, #0FFh
	acall delay_1s
	acall readnibble
	cjne a, 4fh, error
	swap a
	mov r1, a
	mov led, #00h
	ret
error:
	mov led, #10h
	ret
	
readnibble:
	push acc
	orl switches,#0fh	; 1 for input
	mov a,switches		; read switches
	anl a,#0fh
	mov 4fh,a
	pop acc
	ret

displayEight:
	  using 0
	  push acc
	  push ar2
	  mov a,#80h
	  acall lcd_command	 ;send command to LCD
	  acall delay
	  mov r2, #04h
repeat_display:
	  acall lcd_sendbyte
	  inc r1
	  djnz r2, repeat_display
	  mov a,#0C0h
	  acall lcd_command	 ;send command to LCD
	  acall delay
	  mov r2, #04h
repeat_display2:
	  acall lcd_sendbyte
	  inc r1
	  djnz r2, repeat_display2
	  pop ar2
	  pop acc
	  ret
	  

write_memory:
	clr   a
	movc  a,@a+dptr
	mov @r1, a
	jz    exit_write
	inc   dptr
	inc   r1
	sjmp  write_memory
exit_write:
	ret

org 200h
start:
	  mov dptr, #my_string1
	  mov R1, #70h
	  acall write_memory
      acall lcd_setup

procedure:
	  acall readSwitches ;Stored in r1
	  mov a, led
	  anl a, #0F0h
	  cjne a, #10h, continue
	  sjmp here
continue:
	  acall displayEight ;Starting from r1
	  acall delay_5s
	  acall displayEight
	  acall delay_5s
	  sjmp procedure
here: sjmp here				//stay here 

lcd_setup:
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
	  mov a,#80h
	  acall lcd_command	 ;send command to LCD
	  acall delay
	  ret

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
         DB   "ABCDEFGHIJKLMNOP", 00H
my_string2:
		 DB   "Kalpesh Krishna", 00H
end

