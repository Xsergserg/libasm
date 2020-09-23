section	.text
		global  _ft_strdup
		extern  _malloc
        extern  _ft_strlen

_ft_strdup:
            xor     rax, rax
            call    _ft_strlen
            inc     rax
            push    rdi
            mov     rdi, rax
            call    _malloc
            pop     rdi
            xor     rcx, rcx
            jmp     copy

copy:
            mov	bl, byte[rdi + rcx]
			mov	[rax + rcx], bl
			cmp	bl, 0
			je	finish
			inc	rcx
			jmp	copy

error:
            xor rax, rax

finish:
            ret