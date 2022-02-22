.data

mensaje1: .asciiz "Introduce un numero: "
mensaje2: .asciiz "No es primo"
mensaje3: .asciiz "Si es primo"

.text

	main:
	
	addi $t2, $zero, 0  #Damos valores a las variables que vamos a usar
	addi $t0, $zero, 2
	li $s0, 2
	
	li $v0, 4
	la $a0, mensaje1 #Imprimimos el mensaje para que el usuario introduzca un numero
	syscall
	
	li $v0, 5 #Captamos numero introducido por usuario
	syscall
	
	move $t1, $v0 #Lo guardamos en t1
	
	beq $t1,1,noprimo #Si el numero es 1, directamente no es primo
	
	div $t1,$s0 #dividimos t1/2 ( n/2)
	mflo $t2    #guardamos el cociendte en $t2
	
	primo:
	
	bge  $t0, $t2, siprimo #si llegamos desde >1 hasta n/2 y no ha dado resto 0, si es primo
	
	div $t1, $t0
	mfhi $t3
	beq $t3,$zero, noprimo # si da resto = 0, no es primo
	
	addi $t0, $t0, 1
	
	j primo
	
	siprimo:
	
	li $v0, 4
	la $a0, mensaje3 #Imprime mensaje de que si es primo
	syscall
	li $v0, 10
	syscall
	
	noprimo:
	li $v0, 4
	la $a0, mensaje2 #Imprime mensaje de que no es primo
	syscall
	li $v0, 10
	syscall
	
	
	
	