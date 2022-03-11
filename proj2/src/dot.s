.globl dot

.text
# =======================================================
# FUNCTION: Dot product of 2 int arrays
# Arguments:
#   a0 (int*) is the pointer to the start of arr0
#   a1 (int*) is the pointer to the start of arr1
#   a2 (int)  is the number of elements to use
#   a3 (int)  is the stride of arr0
#   a4 (int)  is the stride of arr1
# Returns:
#   a0 (int)  is the dot product of arr0 and arr1
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
#   - If the stride of either array is less than 1,
#     this function terminates the program with error code 37
# =======================================================
dot:

	# Prologue

	addi t0 x0 1
    blt a2 t0 ecp1
    blt a3 t0 ecp2
    blt a4 t0 ecp2
    j loop_start
    
ecp1:	
    li a0 36
    j exit
    
ecp2:
	li a0 37
	j exit
    
loop_start:
	addi t0 x0 4
    mul a6 t0 a3
    mul a7 t0 a4
	lw t1 0(a0)
    lw t2 0(a1)
	mul t0 t1 t2
	addi a5 x0 1
	add a0 a0 a6
    add a1 a1 a7
    
loop_continue:
	bge a5 a2 loop_end
	lw t1 0(a0)
    lw t2 0(a1)
	mul t1 t1 t2
	add t0 t0 t1
    addi a5 a5 1
    add a0 a0 a6
    add a1 a1 a7
	j loop_continue
    
loop_end:
	add a0 t0 x0

	# Epilogue


	ret
