
	li $t4, 10
	sw $t4, -8($sp)
	add $t3, $t4, $t6 
repeat:
	nop
	nop
	nop

	bnez $t5, repeat 
	
	nop