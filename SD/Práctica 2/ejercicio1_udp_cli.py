#Ejercicio1 Cliente UDP - Raúl Arcos Herrera
from socket import *     

#Datos importantes para la conexión
host = "127.0.0.1"
port = 1070

#Creamos el socket UDP 
s = socket(AF_INET,SOCK_DGRAM)        
addr = (host,port)


#Pedimos al usuario que instroduzca un mensaje a enviar al servidor.
mensaje_enviar = input("envia un mensaje: ")
s.sendto(mensaje_enviar.encode(),addr)

#Esperamos la respuesta del servidor sobre el mensaje enviado.
mensaje_recibido,addr = s.recvfrom(512)
print (mensaje_recibido.decode())

s.close