section .text
		global _ft_strcpy

_ft_strcpy:
			xor	rax, rax

copy:
			mov	bl, byte[rsi + rax]
			mov	[rdi + rax], bl
			cmp	bl, 0
			je	finish
			inc	rax
			jmp	copy

finish:
			mov rax, rdi
			ret


