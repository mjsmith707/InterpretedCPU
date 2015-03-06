.ktext 0xF01F000000000000
__trap_doublefault: push %tra		# Save trap return address
	push %tra			# Save trap retaddr
	push %g1			# Save %g1
	setint %g0, 1			# Reenable all interrupts
	pop %g1				# restore g1
	iret				# Interrupt return
