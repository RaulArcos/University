#Ejercicio1 Servidor TCP - Raúl Arcos Herrera
import socket

#Datos importantes para la conexión
host = "127.0.0.1"
port = 1070

#Realizamos la conexión a través de TCP 
sock = socket.socket()
sock.bind((host, port))
sock.listen(5)

print(f"Tratado de conectar con {host}:{port}")

#Aceptamos las posibles conexiones inminentes.
c, ad = sock.accept()   

#Recibimos mensaje del cliente.
mensaje_recibido = c.recv(512).decode()
#Imprimimos por pantalla el mensaje.
print(f"Cliente: {mensaje_recibido}")

#Enviamos el mensaje de confirmación al cliente.
c.send(bytes("Server: Mensaje recibido!", "utf-8"))

c.close()
sock.close()