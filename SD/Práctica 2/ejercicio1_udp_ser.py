#Ejercicio1 Servidor UDP - Raúl Arcos Herrera
from socket import *     

#Datos importantes para la conexión
host = "127.0.0.1" 
port = 1070          

#Estableciendo la conexión UDP
s = socket(AF_INET,SOCK_DGRAM) 
s.bind((host, port))        # Bind al puerto seleccionado.
addr = (host,port)

print(f"Esperando mensajes de {host}:{port}")

#Recibimos mensaje de cliente
mensaje_recibido,addr = s.recvfrom(512)
mensaje_recibido = mensaje_recibido.decode()
print(f"Cliente: {mensaje_recibido}")

s.sendto(bytes("Servidor: Mensaje Recibido!", "utf-8"),addr)

s.close()


