.data
	
	orig: .asciiz "Raul "
	dest: .asciiz "Hola me llamo, "

.text
	
	main:
	
	la $a0, orig #Cargamos ambas cadenas en el buffer
	la $a1, dest
		
	addi $t0, $zero, 0 #Ponemos a 0 las dos variables que usaremos de contador
	addi $t1, $zero, 0
	
	strcat:
	
		for1:
		
		lb $t2, dest($t0) #Cargamos letra de destino
		beq $t2, 00, fin1 #si se encuentra un caracter terminador se sale
		addi $t0, $t0, 1#si no es 00, contamos (Para saber cuantops caracteres tiene dest)
		#Este for sirve exclusivamente para saber donde podemos empezar a copiar en dest
		
		j for1
		
		fin1:
		
		j for2
		
		for2:
		
		lb $t3, orig($t1) #Copiamos primer byte de orig
		beq $t3, 00, fin2 #si se encuentra un caracter terminador se sale
		sb $t3,dest($t0) #lo guardamos en el byte t0 de dest (el siguiente al 00)
		addi $t1, $t1, 1
		addi $t0, $t0, 1
		
		j for2
		
		fin2:
		
		li $v0, 4 
		la $a0, dest
		syscall
		
		li $v0, 10
		syscall
		
		