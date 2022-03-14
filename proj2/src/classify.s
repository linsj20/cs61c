.globl classify

.text
# =====================================
# COMMAND LINE ARGUMENTS
# =====================================
# Args:
#   a0 (int)        argc
#   a1 (char**)     argv
#   a1[1] (char*)   pointer to the filepath string of m0
#   a1[2] (char*)   pointer to the filepath string of m1
#   a1[3] (char*)   pointer to the filepath string of input matrix
#   a1[4] (char*)   pointer to the filepath string of output file
#   a2 (int)        silent mode, if this is 1, you should not print
#                   anything. Otherwise, you should print the
#                   classification and a newline.
# Returns:
#   a0 (int)        Classification
# Exceptions:
#   - If there are an incorrect number of command line args,
#     this function terminates the program with exit code 31
#   - If malloc fails, this function terminates the program with exit code 26
#
# Usage:
#   main.s <M0_PATH> <M1_PATH> <INPUT_PATH> <OUTPUT_PATH>
classify:
	addi t0 x0 5
    bne t0 a0 exit2
    
	addi sp sp -80
    sw ra 0(sp)
    sw s0 4(sp)
    sw s1 8(sp)
    sw s2 12(sp)
    sw s3 16(sp)
    sw s4 20(sp)
    sw s5 24(sp)
    sw s6 28(sp)
    add s0 a0 x0
    lw s1 4(a1)
    lw s2 8(a1)
    lw s3 12(a1)
    lw s4 16(a1)
    add s5 a2 x0
    
	# Read pretrained m0
	add a0 s1 x0
    addi a1 sp 32
	addi a2 sp 36
    jal ra read_matrix
    sw a0 40(sp)
    
	# Read pretrained m1
	add a0 s2 x0
    addi a1 sp 44
	addi a2 sp 48
    jal ra read_matrix
    sw a0 52(sp)

	# Read input matrix
	add a0 s3 x0
    addi a1 sp 56
	addi a2 sp 60
    jal ra read_matrix
    sw a0 64(sp)

	# Compute h = matmul(m0, input)
	lw t0 32(sp)
    lw t1 60(sp)
    mul a0 t0 t1
    slli a0 a0 2
    jal ra malloc
    beq a0 x0 exit1
    sw a0 68(sp)
    add a6 a0 x0
    lw a0 40(sp)
	lw a1 32(sp)
    lw a2 36(sp)
    lw a3 64(sp)
    lw a4 56(sp)
    lw a5 60(sp)
    jal matmul
    
	# Compute h = relu(h)
	lw a0 68(sp)
	lw t0 32(sp)
    lw t1 60(sp)
    mul a1 t0 t1
    jal ra relu
    
	# Compute o = matmul(m1, h)
	lw t0 44(sp)
    lw t1 60(sp)
    mul a0 t0 t1
    slli a0 a0 2
    jal ra malloc
    beq a0 x0 exit1
    sw a0 72(sp)
    add a6 a0 x0
    lw a0 52(sp)
	lw a1 44(sp)
    lw a2 48(sp)
    lw a3 68(sp)
    lw a4 32(sp)
    lw a5 60(sp)
    jal matmul

	# Write output matrix o
	lw a2 44(sp)
    lw a3 60(sp)
	add a0 s4 x0
    lw a1 72(sp)
    jal ra write_matrix
    
	# Compute and return argmax(o)
	lw a0 72(sp)
    lw t0 44(sp)
    lw t1 60(sp)
    mul a1 t0 t1
    jal ra argmax
	sw a0 76(sp)
    
	# If enabled, print argmax(o) and newline
	bne s5 x0 branch
    lw a0 76(sp)
    jal ra print_int
    li a0 '\n'
    jal ra print_char
branch:	
	lw a0 68(sp)
    jal ra free
    lw a0 72(sp)
    jal ra free

    lw ra 0(sp)
    lw s0 4(sp)
    lw s1 8(sp)
    lw s2 12(sp)
    lw s3 16(sp)
    lw s4 20(sp)
    lw s5 24(sp)
    lw s6 28(sp)
    addi sp sp 80
	ret
exit1:
	li a0 26
    j exit
exit2:
	li a0 31
    j exit