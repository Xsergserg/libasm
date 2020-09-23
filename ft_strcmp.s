section .text
		global _ft_strcmp

_ft_strcmp:
			xor	rax, rax
			cmp rdi, 0
			je	null_arg
			cmp rsi, 0
			je	null_arg

compare:
			mov	bl, byte [rdi + rax]
			cmp bl, byte [rsi + rax]
			jl	less_ret
			jg	greater_ret

equal:
			cmp	byte [rsi + rax], 0
			jne	increment
			je	equal_ret

finish:
			ret

increment:
			inc	rax
			jmp	compare

equal_ret:
			mov rax, 0
			jmp	finish

less_ret:
			mov rax, -1
			jmp	finish

greater_ret:
			mov rax, 1
			jmp	finish

null_arg:
			cmp	rdi, rsi
			je	equal_ret
			jl	less_ret
			jmp	greater_ret
