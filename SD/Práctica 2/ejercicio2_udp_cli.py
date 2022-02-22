from socket import *     
import sys         
import os #utilizaremos algunas funciones utiles aprendidas en la anterior práctica.

#Datos importantes para realizar la conexión con el servidor.
host = "127.0.0.1"  
port = 1070                 
tambuffer = 4096 #esta será la cantidad de bytes que enviamos por cada iteracion.


#Creamos nuestro socket UDP
s = socket(AF_INET,SOCK_DGRAM)        
addr = (host,port)

#Nombre del archivo que el cliente solicita enviar al servidor.
nombrearchivo = 'fichero'
formato =  '.pdf'
#Obtenemos el tamaño del fichero que queremos enviar:
tamarchivo = os.path.getsize(nombrearchivo+formato)
print(tamarchivo)
print(nombrearchivo+formato)
#Realizamos la conexión TCP con el servidor:

#Mandamos al servidor una linea con el nombre del archivo que estamos enviando y su peso.
s.sendto(nombrearchivo.encode(),addr)
recibido,addr = s.recvfrom(512)
print(recibido)
if "ok" == recibido.decode():
    print("Comunicación Exitosa")
    f = open(nombrearchivo+formato,'rb')

    i=0

    bytes_enviados = f.read(tambuffer)

    while (bytes_enviados):
        if(s.sendto(bytes_enviados,addr)):
            print ("Enviando...")
            bytes_enviados = f.read(tambuffer)
    
    print("Transmisión completa!")
    f.close()
    #os.remove(nombrearchivo+formato)
    s.close()  