def copia(origen,destino):
    p1 = open(origen,'r')
    texto = p1.readlines()
    p1.close
    p2 = open(destino,'w')
    p2.writelines(texto)

rutaorig = "/etc/network/interfaces"
rutadest = "/home/miguelfj/Escritorio/interfaces_bck"

copia(rutaorig,rutadest)

#Usamos la función copia pasándola a la ruta origen con nuestra configuración de red y como destino usamos la ruta al escritorio
