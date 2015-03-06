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
	wdt %i0			# Activate watchdog

	setint %g0, 1		# Enable interrupts

	# Do some fun stuff
	add %i0, %g0, %g0 	# i=0
	addi %i1, %g0, 100000	# i<10000
	addi %g2, %g0, 0xDEADBEE8	# Aligned!
	loop:			# while i<100
	mul %i2, %i0, %i1	# %i2 = i*100
	sw %i2, %g2, 0		# MEM[%g2] = %i2
	addi %g2, %g0, 15	# g2+int64_t 15 or 16?!
	addi %i0, %i0, 1	# i++
	div %g0, %g0		# I wonder if %g0 is 0?
	jl %i0, %i1, loop	# if (i<100) goto loop
	hlt			# hlt
