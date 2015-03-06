	.text
	.globl	main
	.type main, @function

main:
	pushq	%rbp		# Save callers frame pointer
	movq	%rsp, %rbp	# establish frame pointer
	pushfq			# Save flagsr (why??)
	pushq	%rbx		# Save %rbx
	pushq	%r12		# Save %r12
	pushq	%r13		# Save %r13
	
	movq	0, %rbx		# i = 0
	addq	1000000, %r12	# i<1000000
	
	
