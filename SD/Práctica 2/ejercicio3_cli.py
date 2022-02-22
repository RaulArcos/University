#Ejercicio3 Cliente - Miguel Angel Fernandez
import socket
import os
 
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
addr = ("localhost", 6000)
 
comando = input("Por favor, introduce un comando: ")
s.sendto(comando.encode(), addr)
response, addr = s.recvfrom(1024)
print(response.decode())
if comando == "exit":
    print("Sesión cerrada en el servidor %s:%s\n" % addr)

nomfichero = input()
s.sendto(nomfichero.encode(), addr)

camb_dir = input()
s.sendto(camb_dir.encode(), addr)

nombre_fichero = input()
s.sendto(nombre_fichero.encode(), addr)
mensaje = input()
s.sendto(mensaje.encode(), addr)

orig =input()
s.sendto(orig.encode(), addr)
des = input()
s.sendto(dest.encode(), addr)
 
s.close()