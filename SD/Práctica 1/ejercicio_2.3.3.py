import filecmp

rutaorig = "/etc/network/interfaces"
rutadest = "/home/miguelfj/Escritorio/interfaces_bck"

print(filecmp.cmp(rutaorig,rutadest))