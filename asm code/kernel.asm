.ktext 0x0000000010010000
__start:
	# Load trap_watchdog into IDT
	addi %i0, %g0, 0xF00F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<48
	setidt %i0, 0		# IDT[2] = addr

	# Load trap_doublefault into IDT
	addi %i0, %g0, 0xF01F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<48
	setidt %i0, 2		# IDT[2] = addr

	# Load trap_alignment into IDT
	addi %i0, %g0, 0xF02F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<48
	setidt %i0, 3		# IDT[3] = addr

	# Load trap_div0 into IDT
	addi %i0, %g0, 0xF03F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<48
	setidt %i0, 4		# IDT[4] = addr

	addi %i0, %g0, 200	# Set watchdog to 200ms
	wdt %i0			# Activate watchdog
	setint %g0, 1		# Enable interrupts
	
	addi %i0, %g0, 0xA	# main address
	addi %i1, %g0, 44	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<44
	call %i0		# call main

	hlt			# hlt
