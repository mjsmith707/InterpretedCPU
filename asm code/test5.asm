.text
_start:
	addi %i0, %g0, 0	# i = 0
	addi %i1, %g0, 10	# i<10
loop:
	addi %i0, %i0, 1	# i++
	jl %i0, %i1, loop	# while i<10 goto loop
	hlt
