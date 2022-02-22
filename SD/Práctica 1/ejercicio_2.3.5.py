import os #journaldev.com/17232/python-os-module

directorio = os.getcwd() #Obtenemos dirección de trabajo actual
lista = os.listdir(directorio) #Obtenemos la lista de ficheros del directorio actual

print("Los ficheros disponibles son:")
print(lista)
print("Nombre del fichero a cambiar: ", end="")
fichero = input() #Introducimos el nombre del fichero que queremos cambiar

for x in lista:
  
    if x == fichero: #Si encuentra el fichero que buscamos
        print("Introduzca un nombre nuevo")
        nom_nuevo = input()
        os.rename(x,nom_nuevo) #Utilizamos rename para cambiar el nombre por el nuevo introducido
            print("Cambio realizado con éxito") 
            quit() #Si el cambio se ha realizado con éxito salimos del programa.
    else:
        print("No se ha encontrado, ¿Seguro que se llamaba así?")
        quit()

