.ktext 0xF02F000000000000
__trap_alignment: push %tra
	push %g1			# Save %g1
	setint %g0, 1			# Reenable all interrupts
	pop %g1				# restore g1
	iret				# Interrupt return
