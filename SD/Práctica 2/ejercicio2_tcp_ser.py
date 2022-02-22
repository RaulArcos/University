#Ejercicio2 Servidor TCP - Raúl Arcos Herrera
import socket             
import os 


#Datos importantes para la conexión
host = "127.0.0.1" 
port = 1070                 
tambuffer = 4096 #esta será la cantidad de bytes que enviamos por cada iteracion.

formato = ".pdf"
s = socket.socket()  #Creamos el socket a través de TCP
s.bind((host, port))        # Bind al puerto seleccionado.

#Hacemos 5 intentos de conexión con el cliente.
s.listen(5)    
print(f"Tratado de conectar con {host}:{port}")

#Aceptamos conexión en el caso en el que el cliente intente establecerla.
c, ad = s.accept()    


#Recogemos la información sobre el fichero a recibir:
nombrearchivo = c.recv(512)
nombrearchivo = nombrearchivo.decode()

c.send(bytes("ok", "utf-8"))

#COMPROBAMOS QUE EL ARCHIVO QUE QUEREMOS PASAR YA EXISTE ( 1ª MEJORA )
directorio = os.getcwd() #Obtenemos dirección de trabajo actual
lista = os.listdir(directorio) #Obtenemos la lista de ficheros del directorio actual

for x in lista:
  
    if x == nombrearchivo+formato: #Si encuentra el fichero que buscamos
        c.send(bytes("Existe", "utf-8"))
        mensaje = c.recv(512).decode()
        if mensaje == "n":
            c.send(bytes("Operación cancelada", "utf-8"))           
            c.close
            s.close

#Creamos el nuevo archivo que vamos a recibir y comenzamos el bucle para su recepción
f = open(nombrearchivo+formato,'wb')

while True:

    bytes_leidos = c.recv(tambuffer)
    if not bytes_leidos:
        c.send(bytes("Servidor: Transmisión Finalizada!", "utf-8")) 
        break
    f.write(bytes_leidos)
    print("Recibiendo...")
c.close()
s.close()
