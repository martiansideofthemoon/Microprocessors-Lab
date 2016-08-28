org 0000h
ljmp main

max_signed:
	using 0
	push acc
	push ar1
	push ar2
	mov a, 50h
	mov 55h, a
	mov a, #00h
	mov r1, #50h
	mov r2, #05h
	; Split it into four cases, both compared numbers are +ve,
	; One negative, one positive, the other way round,
	; Both negative
	; Comparison not needed for middle two cases
repeat2:
	mov a, @r1
	acall is_positive
	mov a, 56h
	cjne a, #01h, first_neg
	; First number is positive
	mov a, 55h
	acall is_positive
	mov a, 56h
	cjne a, #01h, second_neg
	;both positive
	;We need to follow standard comparison
	sjmp compare
second_neg:
	; first positive, second negative
	; We move positive number into 55h
	mov 55h, @r1
	sjmp less_than2
first_neg:
	; first number negative
	mov a, 55h
	acall is_positive
	mov a, 56h
	cjne a, #02h, second_pos
	; both negative
	;We need to follow standard comparison
	sjmp compare
second_pos:
	; first negative, second positive
	; We can skip this step since +ve number is in 55h
	sjmp less_than2
compare:	
	mov a, @r1
	cjne a, 55h, not_equal2
not_equal2:
	jc less_than2
	mov 55h, a
less_than2:
	inc r1
	djnz r2, repeat2
	pop ar2
	pop ar1
	pop acc
	ret

is_positive:
	using 0
	; Uncomment the 3 lines below to check from 50h
	; This subroutine checks from ACC otherwise
	
	;push acc
	;mov a, 50h
	anl a, #80h
	mov 56h, #01h
	cjne a, #80h, positive
	mov 56h, #02h ;Negative number
positive:
	;pop acc
	ret
	
max_unsigned:
	using 0
	push acc
	push ar1
	push ar2
	mov 55h, #00h
	mov a, #00h
	mov r1, #50h
	mov r2, #05h
	; Keep comparing new number with current maxima. This is stored in 55h
repeat:
	mov a, @r1
	cjne a, 55h, not_equal
not_equal:
	jc less_than 
	mov 55h, a ;Change the current maxima
less_than:
	inc r1
	djnz r2, repeat
	pop ar2
	pop ar1
	pop acc
	ret

org 100h
main:
	acall max_signed
stop: sjmp stop
END