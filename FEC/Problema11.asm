.data

	vector: .word 12,4,3,5,2,1,4,6,7,4
	espacio: .asciiz " "

.text

	main:
	
	
			
	addi $t0, $zero, 0 #declaramos los contadores que vamos a utilizar
	addi $t1, $zero, 4
	addi $t4, $zero, 0
	addi $t5, $zero, 0
	
	while1:
	
	beq $t0, 44, whileimprime #Si consigue recorrer el vector y esta ordenado, va a imprimirlo
	 
	lw $t2, vector($t0) #Cargamos el valor t0 de vector en t2
	lw $t3, vector($t1) #Cargamos el valor t1 de vector en t3
	
	addi $t4, $t0, 0 
	
	bgt $t2,$t3, while2 #Si $t2 > $t3, vamos al segundo while
	
	addi $t0, $t0, 4
	addi $t1, $t1, 4
	
	j while1
	
	
	while2:
	
	addi $t0, $zero, 0 
	
	lw $t2, vector($t4)
	lw $t3, vector($t1)
	
	bgt $t2, $t3, mayor # si $t2 > $t3, pasamos a mayor
	addi $t1, $zero, 4
	ble $t2, $t3, while1 #Si el de la izq <= derecha, vuelve al primer while
	
	
	j while2
	
	mayor:
	
	sw $t2, vector($t1) # Guarda el menor a la izq
	sw $t3, vector($t4) #guarda el mayor a la derecha 
	
	addi $t1, $t1, 4
	addi $t4, $t4, 4
	
	j while2
	
	whileimprime: #Esta funcion no es necesaria, solo es para comprobar su funcionamiento
	
	beq $t5, 44, fin 
	
	lw $t1, vector($t5)
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 4
	la $a0, espacio
	syscall
	
	addi $t5, $t5, 4
	
	j whileimprime
	
	fin:
	
	li $v0, 10 
	syscall
	
	