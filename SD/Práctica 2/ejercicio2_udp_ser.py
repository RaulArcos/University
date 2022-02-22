#Ejercicio2 Servidor UDP - Raúl Arcos Herrera
from socket import *            
import os
import sys 


#Datos importantes para la conexión
host = "127.0.0.1" 
port = 1070                 
s = socket(AF_INET,SOCK_DGRAM) 
tambuffer = 4096 #esta será la cantidad de bytes que enviamos por cada iteracion.
formato = ".pdf"

s.bind((host, port))        # Bind al puerto seleccionado.
addr = (host,port)

  
print(f"Tratado de conectar con {host}:{port}")


#Recogemos la información sobre el fichero a recibir:
nombrearchivo,addr = s.recvfrom(512)
nombrearchivo = nombrearchivo.decode()
print(nombrearchivo)
s.sendto(bytes("ok", "utf-8"),addr)
#nombrearchivo = os.path.basename(nombrearchivo)

#Creamos el nuevo archivo que vamos a recibir y comenzamos el bucle para su recepción
f = open(nombrearchivo+formato,'wb')
bytes_leidos, addr = s.recvfrom(tambuffer)

try:

    while bytes_leidos:
        f.write(bytes_leidos)   
        print("Recibiendo...")
        s.settimeout(5)
        bytes_leidos, addr = s.recvfrom(tambuffer)
except timeout:
    f.close
    print("Trasmision completada")
    s.close()