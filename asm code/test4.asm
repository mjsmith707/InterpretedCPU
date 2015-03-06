__start:
	# Load trap_watchdog into IDT
	addi %i0, %g0, 0xF00F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<16
	setidt %i0, 0		# IDT[2] = addr

	# Load trap_doublefault into IDT
	addi %i0, %g0, 0xF01F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<16
	setidt %i0, 2		# IDT[2] = addr

	# Load trap_alignment into IDT
	addi %i0, %g0, 0xF02F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<16
	setidt %i0, 3		# IDT[3] = addr

	# Load trap_div0 into IDT
	addi %i0, %g0, 0xF03F	# idt address
	addi %i1, %g0, 48	# shift amount
	shl %i0, %i0, %i1	# addr = addr<<16
	setidt %i0, 4		# IDT[4] = addr

	addi %i0, %g0, 200	# Set watchdog to 200ms
	wdt %i0		# Activate watchdog

	setint %g0, 1		# Enable interrupts

	# Do some fun stuff
	add %i0, %g0, %g0 	# i=0
	addi %i1, %g0, 100000	# i<10000
	loop:			# while i<100
	push %i0		# push to stack
	addi %i0, %i0, 1	# i++
	jl %i0, %i1, loop	# if (i<100) goto loop

	addi %g1, %g0, 99950	# i = 99950
	add %g2, %g0, %g0	# i<0
	loop2:
	subi %g1, %g1, 1	# i--
	pop %g3			# pop stack
	jg %g1, %g2, loop2	# if (i>99950) goto loop2
	hlt			# hlt
