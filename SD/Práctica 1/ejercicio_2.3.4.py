f = open("passwd", "r") #Abrimos el fichero passwd
for x  in f: 
    x = x.split(':') #Separamos cada linea por los : (deja los directorios intactos)
    
    if x[5].startswith('home',1) == 1: #En x[5] se encuentra el directorio /home
        print(x[5]) #lo mostramos por pantalla.
    
f.close() #Cerramos el fichero antes de finalizar la ejecución.
