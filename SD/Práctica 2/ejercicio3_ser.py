#Ejercicio3 Servidor - Miguel Angel Fernandez
import socket
import os
 
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("localhost", 6000))
print("UDP conectado a puerto 6000...")
 
comando, addr = s.recvfrom(1024)

if comando == "exit":
    s.sendto("Conexion finalizada\n", addr)
    s.close()
if comando == "ls":
    devuelvels = lista()
    print("devuelve_ls:",devuelvels)
    devuelvels = "Ficheros en el directorio actual"+os.getcwd()+":\n""devuelve_ls"
    print(devuelvels)
    s.sendto("devuelve_ls".encode("utf-8"), addr)
if comando == "rm":
    s.sendto("Introduce el nombre del fichero:".encode(), addr)#pedimos el nombre del fichero
    via = os.getcwd()+"/"+nomfichero
    if os.via.isfile(via) :
        from os import remove
        remove(via)
        s.sendto("Fichero borrado".encode("utf-8"), addr) 
    else:
        s.sendto("El fichero escrito no existe".encode("utf-8"), addr) 
if comando == "write":
    s.sendto("Introduce el nombre del fichero:".encode(), addr)#pedimos el nombre del fichero
    s.sendto("Introduce el texto a escribir".encode(), addr)#solicitamos el texto que se va a escribir en el fichero
    print("contenido:",mensaje)

    file = open(os.getcwd()+"---"+nombre_fichero,"w")
    file.write(mensaje)
    file.close()

    s.sendto("Fichero creado".encode("utf-8"), addr)
if comando == "cd":
    s.sendto("Introduce el directorio que desea cambiar:".encode(), addr)#pedimos el nombre del directorio
    if(os.path.exists(camb_dir)):
        os.chdir(camb_dir)
        cd_recib = "El directorio de trabajo ha sido cambiado: "+"camb_dir"
        s.sendto("cd_recib".encode("utf-8"), addr) 
    else:
        s.sendto("El directorio introducido no existe".encode("utf-8"), addr) 
if comando == "mv":
    s.sendto("Introduce el directorio origen".encode(), addr)#pedimos que se escriba el directorio origen donde se encuentra el fichero
    s.sendto("Introduce el directorio destino".encode(), addr)#pedimos que se escriba el directorio donde se enviará el fichero 
    if os.path.exists(orig) & os.path.exists(dest):
        ruta = shutil.move(orig, dest)
        s.sendto("El fichero ha sido movido del directorio".encode("utf-8"), addr)
    else:
        s.sendto("El directorio escrito no existe".encode("utf-8"), addr)


    