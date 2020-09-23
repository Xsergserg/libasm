section	.text
		global	_ft_read
		extern	___error

_ft_read:
			mov	rax, 0x2000003
			syscall
			jc errno
			ret

errno:
			push rax
			call ___error
			pop r8
			mov [rax], r8
			mov rax, -1
			ret
