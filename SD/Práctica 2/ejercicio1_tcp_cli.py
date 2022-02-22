#Ejercicio1 Cliente TCP - Raúl Arcos Herrera
import socket

#Datos importantes para la conexión
host = "127.0.0.1"
port = 1070

#Creamos el socket TCP 
sock = socket.socket()
sock.connect((host, port))


#Pedimos al usuario que instroduzca un mensaje a enviar al servidor.
mensaje_enviar = input("envia un mensaje: ")
sock.send(mensaje_enviar.encode('UTF-8'))

#Esperamos la respuesta del servidor sobre el mensaje enviado.
mensaje_recibido = sock.recv(1024)
print (mensaje_recibido.decode('UTF-8'))

sock.close