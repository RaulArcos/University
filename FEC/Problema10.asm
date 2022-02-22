.data
	mensaje: .asciiz "Los Primos 0-100 son: "
	separador: .asciiz ","

.text

	main:
	li $v0, 4
	la $a0, mensaje #imprimimos mensaje de bienvenida
	syscall
	
	addi $t0,$zero,2 # guardamos el contador a 2 (ya que el 1 NO es primo)
	li $s0, 2 #Le damos los valores que vamos a comprobar, como son fijos los he asignado a $s0-3
	li $s1, 3
	li $s2, 5
	li $s3, 7
	
	while:

	beq $t0, 100, fin #Cuando el contador llega a 100 el programa acaba 
	
	beq $t0, $s0, imprimir
	beq $t0, $s1, imprimir
	beq $t0, $s2, imprimir
	beq $t0, $s3, imprimir	
	
	div $t0, $s0
	mfhi $t1  
	beq $t1, $zero, pasar #Si es divisible entre 2, pasa al siguiente
	
	div $t0, $s1
	mfhi $t1
	beq $t1, $zero, pasar #Si es divisible entre 3, pasa al siguiente
	
	div $t0, $s2
	mfhi $t1
	beq $t1, $zero, pasar #Si es divisible entre 5, pasa al siguiente
	
	div $t0, $s3
	mfhi $t1
	beq $t1, $zero, pasar #Si es divisible entre 7, pasa al siguiente
	
	j imprimir
	
	
	pasar:
	
	addi $t0,$t0,1 #Si entra aqui significa que NO es primo, por lo que simplemente suma al contador.
	j while
	
	imprimir:
	
	li $v0, 1 
	move $a0, $t0 #Si entra aqui es porque SI es primo, por lo que imprime $t0 y suma para que siga
	syscall
	
	li $v0, 4
	la $a0, separador
	syscall
	
	addi $t0,$t0,1
	j while
	
	
	fin:
	
	li $v0, 10
	syscall