#Ejercicio2 Cliente TCP - Raúl Arcos Herrera
import socket              
import os #utilizaremos algunas funciones utiles aprendidas en la anterior práctica.

#Datos importantes para realizar la conexión con el servidor.
host = "127.0.0.1"  
port = 1070                 
tambuffer = 4096 #esta será la cantidad de bytes que enviamos por cada iteracion.


#Creamos nuestro socket TCP
s = socket.socket()          

#Nombre del archivo que el cliente solicita enviar al servidor.
nombrearchivo = 'fichero'
formato =  '.pdf'
#Obtenemos el tamaño del fichero que queremos enviar:
tamarchivo = os.path.getsize(nombrearchivo+formato)
print(tamarchivo)
print(nombrearchivo+formato)
#Realizamos la conexión TCP con el servidor:
print(f"Conectando con {host}:{port}")

if s.connect((host, port)):
    print("Conectado con éxito.")
else:
    print("Error durante la conexión!")
    s.close() 
    quit

#Mandamos al servidor el nombre del archivo que estamos enviando.
s.send(nombrearchivo.encode())

#Abrimos el archivo a enviar.
if "ok" == s.recv(512).decode("utf-8"):
    
    if ("Existe" == s.recv(512).decode('utf-8')):
        respuesta = input("El PDF ya existe, ¿Quieres sobreescribir? y/n")
        s.send(respuesta.encode())
    
    f = open(nombrearchivo+formato,'rb')

    i=0

    #Comenzamos un bucle en el que leerá 1024Bytes del archivo y los enviará hasta enviarlos todos.
    while True:
        bytes_leidos = f.read(tambuffer)

        if not bytes_leidos:
            recibido,addr = s.recvfrom(512)
            print(recibido.decode())
            #os.remove(nombrearchivo+formato)
            break #Si no lee mas bytes de fichero.pdf significa que ha terminado de pasarse.   
    
        s.send(bytes_leidos)
        i = i + len(bytes_leidos)
        print(f"{i/1000000}/{tamarchivo/1000000} MB enviados...")


s.close()  