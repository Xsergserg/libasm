section .text
		global _ft_strlen

_ft_strlen:
			xor	rax, rax

iteration:
			cmp	byte[rdi + rax], 0
			je	finish
			jne	plus

plus:
			inc	rax
			jmp	iteration

finish:
			ret

