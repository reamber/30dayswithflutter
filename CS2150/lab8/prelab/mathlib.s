; mathlib.s
; Amber Liu
; al7bf
; 11/04/2018
; Purpose : This file contains the implementation of the function
;           mathlib, which has a product that multiplies two inputs and power which raise first input to power of second
; rdi is x 
; rsi is y

	global product
	global power
	section .text

product:
	; Standard Prologue: we do not have to create any local var

	; subroutine body
	xor rax, rax		; zero out the return register
	xor r10, r10		; zero out counter i
start:
	cmp r10, rsi 		; does i == n?
	je done 			; if so, we are done
	add rax, rdi 		; add a[i] to rax
	inc r10 			; increase counter i
	jmp start			; we are done with this loop
done:
	; Standard epilogue: return value is already in rax, no callee-saved register
	ret 

power:
	xor rax, rax 		; set return to 0
	cmp rsi, 0			; check rsi = 0
	je end				; if yes, jump to end
	dec rsi 			; y--
	call power			; power(x, y-1)
	mov rsi, rax		; thanks to TA Vernon for help on this line 
	call product		; x* power(x, y-1)
	ret
end:
	mov rax, 1 			; x^0 = 1, return 1
	ret