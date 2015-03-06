.text 0x0000A00000000000
main:
	addi %l0, %g0, 100	# arg0 = 100
	addi %g1, %g0, 0xB	# addr
	addi %g2, %g0, 44	# shift amount
	shl %g1, %g1, %g2	# addr<<44
	call %g1		# F(100)
	mov %i1, %l0		# %i1 = F(100)
	ret			# return
