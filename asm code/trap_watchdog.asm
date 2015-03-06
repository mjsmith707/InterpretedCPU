.ktext 0xF00F000000000000
__trap_watchdog: push %tra		# Save trap return address
	push %g1			# Save %g1
	addi %g1, %g0, 200		# Set watchdog to 200ms
	wdt %g1				# Activate watchdog
	pop %g1				# pop %g1
	setint %g0, 1			# Enable interrupts
	iret				# Interrupt return
