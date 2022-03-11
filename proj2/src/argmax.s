.globl argmax

.text
# =================================================================
# FUNCTION: Given a int array, return the index of the largest
#   element. If there are multiple, return the one
#   with the smallest index.
# Arguments:
#   a0 (int*) is the pointer to the start of the array
#   a1 (int)  is the # of elements in the array
# Returns:
#   a0 (int)  is the first index of the largest element
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
# =================================================================
argmax:
	# Prologue
    addi sp sp -4
    sw s0 0(sp)
    
	addi t0 x0 1
    ble t0 a1 loop_start
	li a0 36
    j exit

loop_start:
	add t0 x0 x0
    lw t1 0(a0)
    add t2 x0 x0
	addi t0 x0 1
    addi a0 a0 4
    
loop_continue:
	bge t0 a1 loop_end
	lw s0 0(a0)
	bge t1 s0 next
    add t1 s0 x0
    add t2 t0 x0
next:
	addi t0 t0 1
    addi a0 a0 4
    j loop_continue
    
loop_end:
	# Epilogue
	add a0 t2 x0
    lw s0 0(sp)
    addi sp sp 4
	ret
