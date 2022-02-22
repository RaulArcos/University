.data

 mensaje1: .asciiz "Los numeros son: "
 intermedio: .asciiz " y "
 barran: .asciiz "\n" 
 mensaje2:.asciiz "Tras es Swap son:"
 numero1: .word 4	
 numero2: .word 2

.text

	main:
	
	lw $t0, numero1 #cargamos numero1 en t0
	lw $t1, numero2#cargamos numero2 rn t1
	#Esto es solo para imprimir, la funcion esta abajo
	li $v0, 4
	la $a0, mensaje1
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	li $v0, 4
	la $a0, intermedio
	syscall
	li $v0, 1
	move $a0, $t1
	syscall
	
	jal swap #Una vez inicializados t0 y t1, llamamos a la funcion swap
	
	li $v0, 4
	la $a0, barran
	syscall
	li $v0, 4
	la $a0, mensaje2
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	li $v0, 4
	la $a0, intermedio
	syscall
	li $v0, 1
	move $a0, $t1
	syscall	
	
	
	
	li $v0, 10
	syscall
	
	#Llamamos a la funcion swap
		swap:
	
		add $t2,$t0,$zero #aux = p1
		add $t0,$t1,$zero #p1 = p2
		add $t1,$t2,$zero #p2 = aux
	
		jr $ra