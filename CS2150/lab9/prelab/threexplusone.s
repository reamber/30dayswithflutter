; threeplusone.s
; Amber Liu
; al7bf
; 11/18/2018
; 1st param rdi
; optimization: 1. Use of lea command instead of add and imul at line 30, 2. did not call push and pop, saved memory space
; 3. using shr to divide instead

global threexplusone

	section .text

threexplusone:
	xor rax, rax		; reset rax
base:
	cmp rdi, 1			; base case, if param is 1
	je end				; jump to the end
	mov rdx, rdi
	and rdx, 1 			
	cmp rdx, 0			;checks if it is even
	je even
	cmp rdx, 1			;checks if it is odd
	je odd
even:
	shr rdi, 1			; shift right
	call threexplusone	; recursive call
	inc rax				; increase return count
	jmp base			

odd:
	lea rdi, [3*rdi+1]  ; 3x+1
	call threexplusone	; recursive call
	inc rax				; increase return count
	jmp base	
end:
	ret 				; return number of steps taken