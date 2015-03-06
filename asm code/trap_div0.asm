.ktext 0xF03F000000000000
__trap_div0: push %tra			# Save trap return address
	push %g1			# Save %g1
	setint %g0, 1			# Reenable all interrupts
	pop %g1				# restore g1
	iret				# interrupt return
