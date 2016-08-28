org 0000h
ljmp main

multiply:
	using 0
	push acc
	push ar1
	push ar2
	push ar3
	push ar4
	;First get the sign bit of first number
	;Store it in r1
	mov a, 70h
	anl a, #80h
	mov r1, #00h
	cjne a, #80h, positive
	mov r1, #01h ;Indicates that number is negative
positive:
	; Store number with sign bit removed
	mov a, 70h
	anl a, #7Fh
	mov r2, a
	; Repeat the same for the second number
	mov a, 71h
	anl a, #80h
	cjne a, #80h, positive2
	; XOR since negative * negative = positive
	xrl 1, #01h
positive2:
	; Store number with sign bit removed
	mov a, 71h
	anl a, #7Fh
	mov r3, a
	mov a, #00h
	cjne r2, #00h, repeat ; Check if iterative number is identically zero
	sjmp end_multiply
	; Start multiplication
repeat:
	add a, r3
	jnc no_carry
	inc r4
no_carry:
	djnz r2, repeat
	mov 72h, a
	mov a, r4
	; Check if resultant is negative
	cjne r1, #01h, positive3
	add a, #80h ;Negative resultant
positive3:
	mov 73h, a
end_multiply:
	pop ar4
	pop ar3
	pop ar2
	pop ar1
	pop acc
	ret


org 100h
main:
	acall multiply
stop: sjmp stop
END