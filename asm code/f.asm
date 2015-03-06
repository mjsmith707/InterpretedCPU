.text 0x0000B00000000000
F:
	push %g1		# save g1
	addi %g1, %g0, 1	# i = 1
	jne %l0, %g1, else	# if (x == 1)
	mov %l7, %g1		# ret = 1
	pop %g1			# restore g1
	ret			# return to caller
else:
	push %i0		# save i0
	push %ra		# save return address
	addi %l0, %l0, -1	# arg0 = x-1
	addi %g1, %g0, 0xB	# F address
	addi %i0, %g0, 44	# shift amount
	shl %g1, %g1, %i0	# addr = addr<<44
	mov %i0, %l0		# i0 = x
	call %g1		# recursive call

	muli %g1, %i0, 2	# 2*x
	addi %g1, %g1, -1	# -1
	add %l0, %l7, %g1	# F(x-1) + 2*x - 1
	pop %ra			# restore return address
	pop %i0			# restore i0
	pop %g1			# restore g1
	ret			# return
