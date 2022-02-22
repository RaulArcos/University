.data
 
  mensaje: .asciiz "Introduce un Caracter/Numero: "

.text

	main:
	
	li $v0, 4
	la $a0, mensaje
	syscall
	
	li $v0, 5 
	syscall
	
	move $t0, $v0
	
	
	isdigit:
	
	bgt $t0, 75, devolver0
	blt $t0, 48, devolver0
	j devolver1
	
	
	devolver1:
	
	addi $t1, $zero, 1
	j resultado
	
	devolver0:
	
	addi $t0, $zero, 0
	
	j resultado
	
	resultado:
	
	li $v0, 1
	move $a0, $t0
	syscall