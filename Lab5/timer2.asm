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

ORG 0000H
LJMP MAIN

ORG 0100H
T2_INIT:
MOV T2MOD,#02H;
CLR EXF2;
/* Next, disable baud rate generator */
/* Next. ignore events on T2EX */
;Initialize values in TH2, TL2 depending on required frequency
MOV TH2,#0FDh; /* Init msb_value */
MOV TL2,#0A8h; /* Init lsb_value */
;Reload values in RCAP
MOV RCAP2H,#0FDh; /* reload msb_value */
MOV RCAP2L,#0A8h; /* reload lsb_value */
CLR C_T2; /* timer mode */
CLR CP_RL2; /* reload mode */
CLR ET2; /* clear timer2 interrupt */
SETB TR2
RET

MAIN:
LCALL T2_INIT
OVER: SJMP OVER
END

