; This subroutine writes characters on the LCD
LCD_data equ P2    ;LCD Data port
LCD_rs   equ P0.0  ;LCD Register Select
LCD_rw   equ P0.1  ;LCD Read/Write
LCD_en   equ P0.2  ;LCD Enable
; Defining Timer-2 registers
T2CON DATA 0C8H
T2MOD DATA 0C9H
RCAP2L DATA 0CAH
RCAP2H DATA 0CBH
TL2 DATA 0CCH
TH2 DATA 0CDH
; Defining interrupt enable (IE) bit
ET2 BIT 0ADH
; Defining interrupt priority (IP) bit
PT2 BIT 0BDH
; Defining P1
T2EX BIT 91H
T2 BIT 90H
; Defining timer control (T2CON) register bits
TF2 BIT 0CFH
EXF2 BIT 0CEH
RCLK BIT 0CDH
TCLK BIT 0CCH
EXEN2 BIT 0CBH
TR2 BIT 0CAH
C_T2 BIT 0C9H
CP_RL2 BIT 0C8H
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
	CLR EA
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
	MOV P1, #0A0h
	;SETB P3.2
	MOV R1, #00h
	MOV TH0, #00h
	MOV TL0, #00h
	MOV TMOD, #09h
	MOV R2, #01h ;check register
	SETB IT0
here1:
	JB P3.2, here1 ;Accounting for initial positive value
	;MOV P1, #0B0h
	SETB TR0
	CLR IE0
	;MOV IP, #01h
	MOV IE, #83h
	
loop:
	CJNE R2, #00h, loop
	;MOV P1, #0C0h
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

T2_INIT:
MOV T2MOD,#02H;
CLR EXF2;
/* Next, disable baud rate generator */
/* Next. ignore events on T2EX */
;Initialize values in TH2, TL2 depending on required frequency
MOV TH2,#0FBh; /* Init msb_value */
MOV TL2,#050h; /* Init lsb_value */
;Reload values in RCAP
MOV RCAP2H,#0FBh; /* reload msb_value */
MOV RCAP2L,#050h; /* reload lsb_value */
CLR C_T2; /* timer mode */
CLR CP_RL2; /* reload mode */
CLR ET2; /* clear timer2 interrupt */
SETB TR2
RET

org 200h
main:
	;CLR P3.2
	acall T2_INIT
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