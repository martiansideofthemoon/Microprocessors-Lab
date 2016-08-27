; This subroutine writes characters on the LCD
LCD_data equ P2    ;LCD Data port
LCD_rs   equ P0.0  ;LCD Register Select
LCD_rw   equ P0.1  ;LCD Read/Write
LCD_en   equ P0.2  ;LCD Enable
org 00h
	ljmp main
org 0003h
	sjmp isr_ext0
org 000Bh
	sjmp isr_timer0
org 50h
isr_ext0:
	mov r2, #00h
	CLR TR0
	reti
	
isr_timer0:
	INC R1
	CLR TR0
	CLR TF0
	MOV TL0, #00h
	MOV TH0, #00h
	SETB TR0
	reti

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

pulse_width:
	MOV TMOD, #09h
	SETB IT0
	CLR IE0
	MOV IP, #01h
	MOV IE, #83h
	MOV R2, #01h ;check register
	SETB TR0
loop:
	CJNE R2, #00h, loop
	mov 2, R1
	mov a,#80h		 ;Put cursor on first row,5 column
	acall lcd_command	 ;send command to LCD
	acall delay
	mov dptr,#my_string1   ;Load DPTR with sring1 Addr
	acall lcd_sendstring	   ;call text strings sending routine
	acall delay
	mov a,#0C0h		 ;Put cursor on first row,5 column
	acall lcd_command	 ;send command to LCD
	acall delay
	mov dptr,#my_string2   ;Load DPTR with sring1 Addr
	acall lcd_sendstring	   ;call text strings sending routine
	mov 50h, #01h
	mov 51h, #53h
	mov 52h, #54h
	mov 53h, r2
	acall bin2ascii
	mov r1, #54h
	acall lcd_sendbyte
	inc r1
	acall lcd_sendbyte
	mov 53h, TH0
	acall bin2ascii
	mov r1, #54h
	acall lcd_sendbyte
	inc r1
	acall lcd_sendbyte
	mov 53h, TL0
	acall bin2ascii
	mov r1, #54h
	acall lcd_sendbyte
	inc r1
	acall lcd_sendbyte
	ret

lcd_sendbyte:
	push acc
	mov a, @r1
	acall lcd_senddata
	pop acc
	ret

org 150h
main:
	;CLR P3.2
	acall lcd_setup
	acall pulse_width
stop:
	sjmp stop
	
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
	         movc  a,@a+dptr         ;load the first character in accumulator
	         jz    exit              ;go to exit if zero
	         acall lcd_senddata      ;send first char
	         inc   dptr              ;increment data pointer
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
org 300h
my_string1:
         DB   "PULSE WIDTH", 00H
my_string2:
		 DB   "COUNT IS ", 00H
	
END