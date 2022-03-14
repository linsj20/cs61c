.globl matmul

.text
# =======================================================
# FUNCTION: Matrix Multiplication of 2 integer matrices
#   d = matmul(m0, m1)
# Arguments:
#   a0 (int*)  is the pointer to the start of m0
#   a1 (int)   is the # of rows (height) of m0
#   a2 (int)   is the # of columns (width) of m0
#   a3 (int*)  is the pointer to the start of m1
#   a4 (int)   is the # of rows (height) of m1
#   a5 (int)   is the # of columns (width) of m1
#   a6 (int*)  is the pointer to the the start of d
# Returns:
#   None (void), sets d = matmul(m0, m1)
# Exceptions:
#   Make sure to check in top to bottom order!
#   - If the dimensions of m0 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m1 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m0 and m1 don't match,
#     this function terminates the program with exit code 38
# =======================================================
matmul:

	# Error checks
	addi t0 x0 1
    blt a1 t0 error
	blt a2 t0 error
    blt a4 t0 error
    blt a5 t0 error
    bne a2 a4 error
	# Prologue
    addi sp sp -28
	sw s0 0(sp)
    sw s1 4(sp)
    sw s2 8(sp)
    sw s3 12(sp)
    sw s4 16(sp)
    sw s5 20(sp)
    sw s6 24(sp)
    addi t0 x0 4
    mul s6 t0 a5
    mul s5 t0 a2
    j outer_loop_start
    
error:
	li a0 38
    j exit
    
outer_loop_start:
	addi s3 x0 -1
    sub s0 a0 s5

outer_loop:
	addi s3 s3 1
    add s0 s0 s5
    bge s3 a1 outer_loop_end 
        
inner_loop_start:
    addi s4 x0 -4
    add s1 a3 s4
    addi s4 x0 -1
    
inner_loop:
	addi s4 s4 1
    addi s1 s1 4
	bge s4 a5 inner_loop_end
	addi sp sp -32
    sw a0 0(sp)
    sw a1 4(sp)
    sw a2 8(sp)
    sw a3 12(sp)
    sw a4 16(sp)
    sw a5 20(sp)
    sw a6 24(sp)
    sw ra 28(sp)
    add a0 s0 x0
    add a1 s1 x0
    addi a3 x0 1
    addi t0 x0 4
    div a4 s6 t0
    jal ra dot
    add a7 a0 x0
    lw a0 0(sp)
    lw a1 4(sp)
    lw a2 8(sp)
    lw a3 12(sp)
    lw a4 16(sp)
    lw a5 20(sp)
    lw a6 24(sp)
    lw ra 28(sp)
    addi sp sp 32
    mul s2 s3 s6
    addi t0 x0 4
    mul t0 s4 t0
    add s2 s2 t0
    add a6 a6 s2
    sw a7 0(a6)
    sub a6 a6 s2
    j inner_loop
    
inner_loop_end:
	j outer_loop
    
outer_loop_end:
	

	# Epilogue
	lw s0 0(sp)
    lw s1 4(sp)
    lw s2 8(sp)
    lw s3 12(sp)
    lw s4 16(sp)
    lw s5 20(sp)
    lw s6 24(sp)
    addi sp sp 28
    
	ret
