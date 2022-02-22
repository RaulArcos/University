.data

	mensaje: .asciiz "Introduce un texto: "
	C1: .space 30 # le das espcaio al usuario para meter 30 caracteres
	
.text

	main:
		#Imprime el texto de bienvenida
	 	li $v0, 4
		la $a0, mensaje 
	 	syscall
	 	
	 	addi $t0,$zero,0
	 	
	 	j pidecadena
	 	
	pidecadena:
	 	
	 	# esto es lo que recoge el texto del usuario
		li $v0, 8 # 8 es el codigo para coger texto
		la $a0, C1
		li $a1, 30
		syscall
		
		addi $t0,$zero,0
		j operacionxor
		
		
	operacionxor:
		
		while:
			beq $t0, 30, fin #si el contador llega al maximo de heucos de la cadena se sale
		
			lb $t1, C1($t0) # pasamos el caracter en la posicion t0 de C1 a t1
			beq $t1, 00, fin #si se encuentra un caracter terminador se sale
			xor $t1,$t1,63 #Realizammos xor 63
			sb $t1, C1($t0) #Guardamos el caracter en la posicion t0 de C2 
		
			addi $t0,$t0,1
		
			j while
		fin:
	
		#final del main
		li $v0, 10
		syscall
		