import os , requests, string , json, time , re #Importamos las librerias 
from bottle import run, request, response, get, post, put, delete   #Importamos el bottle para utilizar los endpoint y las distintas funciones

def principal(): #Declaramos la función principial: Muestra el menú.

    while True:
        os.system("clear") # Limpiar pantalla

        print(  #Mostramos opciones para el servicio web.                                         
            "Bienvenido a la UCA, ¿Qué deseas?:\n\n"
            "   [1] Dar de alta un Usuario nuevo.\n"
            "   [2] Ver listado de usuarios.\n"
            "   [3] Modificar un usuario.\n"
            "   [4] Eliminar un usuario.\n"
            "   [5] Busqueda de usuario por DNI.\n"
            "   [6] Ver listado de miebros por categoría\n"
            "   [7] Busqueda de usuario por nombre\n"
            "   [8] Salir\n"
        )

        op = int(input("Selección: ")) #Guardamos la opción elegida por el usuario
        
        if( op < 1  or op > 8): #La opcion no esta dentro de las posibles
            continue
        elif op == 1: #Entramos en la correspondiente funcion dependiendo de la opción seleccionada.
            dar_alta_usuario()
        elif op == 2:
            consultar_lista_usuarios()
        elif op == 3:
            modificar_usuario()
        elif op == 4:
            eliminar_usuario()
        elif op == 5:
            busqueda_dni()
        elif op == 6:
            busqueda_categoria()
        elif op == 7:
            busqueda_nombre()
        elif op == 8:
            salir()
        

    

def dar_alta_usuario(): #ENDPOINT dar de alta un usuario: recoge los datos introducidos y los guarda en el diccionario.
    
    os.system('clear')  # Limpiar pantalla
    print("Para dar de alta, debe introducir los siguientes datos:\n")
    
    while True: #INTRODUCCIÓN Y COMPROBACIÓN DNI

        dni = input("  DNI (Letra mayúscula): ") #DNI introducido por el usuario
        
        #MEJORA LETRA DNI: Comprobación de que la letra del DNI es correcta.
        LetraDNI='TRWAGMYFPDXBNJZSQVHLCKE' #Declaramos un array con las posibles letras del DNI.
        dniaux = dni[:-1] #Quitamos la letra al DNI introducido para quedarnos con el número.

        if len(dni) != 9 or any(chr.isdigit() for chr in dni) == False or dni[8].isdigit() : #Si el dni no tiene 9 caracteres O no contiene numeros O el ultimo no es una letra.
            print(" El DNI introducido NO es correcto, por favor Introduce uno válido.\n") 
            continue                                               
        elif LetraDNI[int(dniaux)%23] != dni[8]: #Comprueba si la letra del DNI coincide con la que debería ser.
            print(" La letra del DNI no es la correcta. Por favor introduce un DNI válido")
            continue
        else:
            break
    
    while True: #INTRODUCCIÓN Y COMPROBACIÓN NOMBRE.
        nombre = input("  Nombre Completo (Nombre Apellido1 Apellido2): ") #Nombre introducido por el usuario.
        
        if(any(chr.isdigit() for chr in nombre)): #Miramos que no haya dígitos en el nombre.
            print("Por favor, introduce un nombre real, no un nickname.")
            continue
        else:
            break
    
    while True: #INTRODUCCIÓN Y COMPROBACIÓN CORREO.
        correo = input("  Correo Electrónico: ") #Correo introducido por el usuario.
        if comprobacion_correo(correo) == False: #Llamamos a la función auxiliar comprobar_correo.
            print("Introduce un correo válido")
            continue
        else:
            break

    while True: #INTRODUCCIÓN Y COMPROBACIÓN DEPARTAMENTO.
        dep = input("  Departamento: ") 
        if(any(chr.isdigit() for chr in dep)): #Hacemos una comprobación similar a la del nombre.
            print("Por favor, introduce un departamento real, no puedes usar números.")
            continue
        else:
            break

    while True: #INTRODUCCIÓN DE LA CATEGORÍA.
        print("  Categoría:\n"

                    "   [1] PAS\n"
                    "   [2] PDI\n"
                    "   [3] Becario\n")
    
        cat = int(input("Selección: ")) #Dependiendo de la selección se guarda la opción en CAT

        if cat == 1:
            cat = "PAS"
            break
        elif cat == 2:
            cat = "PDI"
            break
        elif cat == 3:
            cat = "Becario"
            break
        if cat < 1 or cat > 3:
            print ("No es una opción")
            continue
    
    if cat == "PDI": #Si es PDI, añadimos las asignaturas.
        asig = [] #Creamos la lista de asignaturas.
        print("Por favor, Introduce las asignaturas, escribe 'salir' para terminar. ") 
        while True: #Introducimos tantas asignaturas como queramos hasta introducir "salir".
            asig_nombre = input("Nombre Asignatura: ")
            if(asig_nombre != 'salir'):
                asig.append(asig_nombre)
                continue
            else:
                datos = { 'dni': dni, 'nombre':nombre, 'correo': correo, 'dep': dep, 'cat':cat ,'asig':asig }  #Guardamos todo en una variable con las asignaturas.
                break
    else:
        datos = { 'dni': dni, 'nombre':nombre, 'correo': correo, 'dep': dep, 'cat':cat}  #Guardamos todo en una variable sin las asignaturas.

    r = requests.post("http://localhost:8080/dar-alta-usuario" , json = datos) #La enviamos como request al servidor y en formato json.
    print("\n" + r.text)    #Imprimimos el mensaje del servidor.
    print("\nDevolviendo al menú...\n") #Volvemos al menú principal.
    time.sleep(3)

def consultar_lista_usuarios():
    os.system("clear")
    print("Lista de usuarios actuales en el sistema:\n")
    request = requests.get("http://localhost:8080/listar_miembros") #Realizamos un GET al servidor para conseguir la lista de usuarios.
    lista = request.json() #Guardamos los datos sacados del servidor en lista.

    for x in lista:
        print("["+x["dni"]+"]" + " " + x["nombre"] + " | " + x["correo"]) #Imprimimos todos los usuarios registrados en el sistema.

    while True:
        op = int(input("\n[1] Volver al menú\n[2] Salir\n\nSelección = ")) #Ponemos opción para volver al menú o salir del programa.
        
        if op == 1:
            principal()
            break
        elif op == 2:
            salir()
            break
        else:
            continue

def modificar_usuario(): #ENDPOINT modificar usuario: modifica los datos del usuario que queramos a través de su DNI.
    os.system("clear")
    
    while True:
        dni = input("Introduce el DNI del usuario que quieres modificar o 'salir' para volver.\n\n") #Introducimos el DNI del usuario a cambiar.
        
        if dni == "salir": #Si escribimos salir, volvemos al menú principal.
            break
        
        req = requests.get("http://localhost:8080/buscar-por-dni/"+str(dni))  #Lo enviamos al servidor y recibimos un json.
        req = req.json() #Recibimos los datos del dni solicitado.

        if dni == False:
            print("El usuario no existe o no está registrado aún.\n") #En el caso de no existir, tenemos la opción de registrarlo o intentar de nuevo.
            
            op = int(input("¿Quieres registrarlo?\n[1] Registrar Usuario\n[2] Intentar con otro DNI\n[3] Salir\n"))

            if cat == 1:
                dar_alta_usuario()
                break
            elif cat == 2:
                modificar_usuario()
                break
            elif cat == 3:
                principal()
                break
            if cat < 1 or cat > 3:
                print ("No es una opción")
                continue
            
        print("El usuario con DNI: '" + str(req["dni"]) + "' tiene los siguientes datos: "  #Si existe, impimimos la información del usario a modificar.
        + "\n[1] Nombre: " + str(req["nombre"]) + "\n[2] Correo: " + str(req["correo"])
        + "\n[3] Departamento: " + str(req['dep']) + "\n[4] Categoría: " + str(req['cat']))

        if(req["cat"] == "PDI"): #Si el usuario es PDI, también imprimimos sus asignaturas.
            print("[5] Asignaturas: " + str(req["asig"]
            +"\n[6] Cancelar")) #Opción para salir al menú principal.
        else: #Si no, en vez de las asignaturas damos la opción a cancelar y volver al menú principal.
            print("[5] Cancelar\n")
        
        while True: #(debido a la dificultad de añadir el DNI mal y la imposibilidad de cambiar el DNI en la vida real, hemos determinado que no puedas cambiarlo).
            op = int(input("Selección: ")) #Recogemos la opción del usuario.

            if op == 1: #Modificar nombre.
                nuevo = input("Introduzca el nombre nuevo:")
                
                if(any(chr.isdigit() for chr in nuevo)): #Miramos que no haya dígitos en el nombre.
                    print("Por favor, introduce un nombre real, no un nickname.")
                    continue
                else:
                    break  

                req = requests.put("http://localhost:8080/modif_miembro/"+str(dni)+"/"+str(op)+"/"+str(nuevo)) #Enviamos con PUT la información al servidor.
                print("Cambio Realizado con Éxito, volviendo al menú...")
                time.sleep(2)
                principal() #Volvemos al menú principal.
                break
            if op == 2: #Modificar correo.
                
                while True: #Introducción y comprobación de correo.
                    nuevo = input("Introduzca el correo nuevo:")
                    if comprobacion_correo(nuevo) == False: #Llamamos a la función auxiliar comprobar_correo.
                        print("Introduce un correo válido")
                        continue
                    else:
                        break
                req = requests.put("http://localhost:8080/modif_miembro/"+str(dni)+"/"+str(op)+"/"+str(nuevo)) #Enviamos con PUT la información al servidor.
                print("Cambio Realizado con Éxito, volviendo al menú...")
                time.sleep(2)
                principal()
                break
            if op == 3:
                nuevo = input("Introduzca el departamento nuevo:")
                req = requests.put("http://localhost:8080/modif_miembro/"+str(dni)+"/"+str(op)+"/"+str(nuevo)) #Enviamos con PUT la información al servidor.
                print("Cambio Realizado con Éxito, volviendo al menú...")
                time.sleep(2)
                principal()
                break
            if op == 4:
                print("Seleccione la nueva categoría nueva: ") #Hacemos una selección similar a la de dar de alta.

                while True:
                    print(
                    "   1. PAS\n"
                    "   2. PDI\n"
                    "   3. Becario\n")
    
                    cat = int(input("Selección: ")) 

                    if cat == 1:
                        cat = "PAS"
                        break
                    elif cat == 2:
                        cat = "PDI"
                        break
                    elif cat == 3:
                        cat = "Becario"
                        break
                    if cat < 1 or cat > 3:
                        print ("No es una opción")
                        continue

                req = requests.put("http://localhost:8080/modif_miembro/"+str(dni)+"/"+str(op)+"/"+str(cat)) #Enviamos con PUT la información al servidor.
                print("Cambio Realizado con Éxito, volviendo al menú...")
                time.sleep(2)
                principal()
                break
            if op == 5 and req["cat"] == "PDI":
                
                asig = [] #Creamos la lista de asignaturas.
                print("Por favor, Introduce las asignaturas, escribe 'salir' para terminar. ") 
                while True: #Introducimos tantas asignaturas como queramos hasta introducir "salir".
                    asig_nombre = input("Nombre Asignatura: ") 
                    if(asig_nombre != 'salir'):
                        asig.append(asig_nombre)
                        continue
                    else:
                        req = requests.put("http://localhost:8080/modif_miembro/"+str(dni)+"/"+str(op)+"/"+str(asig)) #Enviamos con PUT la información al servidor.
                        print("Cambio Realizado con Éxito, volviendo al menú...")
                        time.sleep(2)
                        principal()
                        break
            elif op == 5 and req["cat"] != "PDI": #Si es la opción 5 y no es PDI, volvemos al menú.
                principal()
                break
            if op == 6 and req["cat"] == "PDI": # Si es la opción 6 y SI es PDI, cambiamos sus asignaturas.
                principal()
                break
        
        
            if(op < 1 or op > 5) and req["cat"] != "PDI": #Si no es PDI las opciones correctas seran del 1 al 5
                print("Por favor selecciona una opción correcta.\n")
                continue
            if(op < 1 or op > 6) and req["cat"] == "PDI": #Si es PDI las opciones correctas seran del 1 al 6 (Incluimos cambiar asignaturas)
                print("Por favor selecciona una opción correcta.\n")
                continue

def eliminar_usuario():#MEJORA eliminar usuario: eliminas un usuario tan solo introduciendo su DNI.

    os.system("clear")

    while True:
        print("Escriba el DNI del usuario a borrar o 'cancelar' para volver al menú.") #Recogemos el DNI del usuario a eliminar.
        dni = input("->")

        if(dni == "cancelar"): #Si es cancelar, volvemos al menú prinpcipal.
            principal()
            break
        
        else:
            req = requests.delete("http://localhost:8080/eliminar/"+str(dni)) #Si no, enviamos el request al servidor con el DNI.
            print(req.text)#Imprimimos la respuesta.

def busqueda_dni():# ENDPOINT busqueda por DNI: Sacamos los datos de un usuario del sistema a través de su DNI.
    
    os.system("clear")

    while True:
        print("Introduce el DNI o 'cancelar' para volver.") #Pedimos el DNI al usuario.
        dni = input("->")

        if(dni == "cancelar"): #Si es cancelar, volvemos al menú prinpcipal.
            break

        req = requests.get("http://localhost:8080/buscar-por-dni/"+str(dni)) #Si no, enviamos el request al servidor con el DNI.
        req = req.json() #Guardamos la respuesta del servidor con los datos del usuario solicitado.

        if req["dni"] == False: # si el req es False, quiere decir que no ha encontrado a un usuario con ese DNI.
            print("El usuario no existe o no está registrado aún.\n")
            
            op = int(input("¿Quieres registrarlo?\n[1] Registrar Usuario\n[2] Intentar con otro DNI\n[3] Salir\n")) #Se da la opción de registrarlo o intentar de nuevo.

            if op == 1:
                dar_alta_usuario()
                break
            elif op == 2:
                busqueda_dni()
                break
            elif op == 3:
                principal()
                break
            if op < 1 or op > 3:
                print ("No es una opción")
                continue
            
        print("El usuario con DNI: '" + str(req["dni"]) + "' tiene los siguientes datos: "  #Imprimimos los datos del usuario solicitado.
        + "\n Nombre: " + str(req["nombre"]) + "\n Correo: " + str(req["correo"])
        + "\n Departamento: " + str(req['dep']) + "\n Categoría: " + str(req['cat']))

        if(req["cat"] == "PDI"): #Si el usuario es PDI, también imprimimos sus asignaturas.
            print("\n Asignaturas: " + str(req["asig"]))
        print("\n[1] Buscar otro usuario \n[2] Volver al menu")

        while True: #Damos la opción de buscar a otro usuario o salir al menú principal.
            op = int(input("Selección: "))

            if op == 1:
                busqueda_dni()
                break
            if op == 2:
                principal()
                break
        
def busqueda_categoria(): #ENDPOINT busqueda por categoria: muestra los usuarios que pertenecen a diferentes categorías.
    os.system("clear")

    while True:
        print("  Categoría a buscar:\n"

                    "   1. PAS\n"
                    "   2. PDI\n"
                    "   3. Becario\n")
    
        cat = int(input("Selección: ")) #Recogemos la opción de categoria del usuario.

        if cat == 1:
            cat = "PAS"
            break
        elif cat == 2:
            cat = "PDI"
            break
        elif cat == 3:
            cat = "Becario"
            break
        if cat < 1 or cat > 3:
            print ("No es una opción")
            continue
    
    os.system("clear")        
    print("Lista de usuarios '" + cat + "' en el sistema:\n") 
    request = requests.get("http://localhost:8080/miemb_categoria/"+str(cat)) #Realizamos un GET al servidor para conseguir la lista de usuarios.
    lista = request.json() #Guardamos los datos sacados del servidor en lista.

    if lista == False: #Si la lista está vacía es que no hay usuarios en el sistema con esa categoría.
        print("No hay ningún usuario en esta categoría.")
    else:
        for x in lista: #Imprimimos todos los usuarios que se encuentren en la lista.
            print("["+x["dni"]+"]" + " " + x["nombre"] + " | " + x["correo"])

    while True:
        op = int(input("\n[1].Volver al menú\n[2].Salir\n\nSelección = ")) #Damos la opción de volver al menú o salir del programa.
        
        if op == 1:
            principal()
            break
        elif op == 2:
            salir()
            break
        else:
            continue

def busqueda_nombre(): #FUNCION MEJORA busqueda nombre: permite al usuario buscar por nombre parcialmente.

    os.system("clear")

    while True:
        
        print("Introduce el nombre (completo o incompleto) o 'cancelar' para volver.\n") #Pedimos el DNI al usuario.
        nom = input("->")

        if(nom == "cancelar"): #Si es cancelar, volvemos al menú prinpcipal.
            break

        req = requests.get("http://localhost:8080/buscar-por-nombre/"+str(nom)) #Si no, enviamos el request al servidor con el DNI.
        req = req.json() #Guardamos la respuesta del servidor con los datos del usuario solicitado.

        if req == False: # si el req es False, quiere decir que no ha encontrado a un usuario con ese DNI.
            print("Ningún usuario coincide con el nombre introducido.\n")
            
            op = int(input("¿Quieres registrarlo?\n[1] Registrar Usuario\n[2] Intentar con otro Nombre\n[3] Salir\n")) #Se da la opción de registrarlo o intentar de nuevo.

            if op == 1:
                dar_alta_usuario()
                break
            elif op == 2:
                busqueda_nombre()
                break
            elif op == 3:
                principal()
                break
            if op < 1 or op > 3:
                print ("No es una opción")
                continue
        

        else:
            os.system("clear")
            print("Usuarios con nombre que contiene: " + nom + "\n")
            for x in req: #Imprimimos todos los usuarios que se encuentren en la lista.
                print("["+x["dni"]+"]" + " " + x["nombre"] + " | " + x["correo"])
        
        #REUTILIZAMOS CODIGO PARA UNA VEZ VISTA LA LISTA DE USUARIOS CON NOMBRE SIMILAR, PODER VER LOS DATOS DEL QUE QUERAMOS.
        while True:
            
            print("\nIntroduce el DNI del usuario para ver sus datos o 'cancelar' para volver.") #Pedimos el DNI al usuario.
            dni = input("->")

            if(dni == "cancelar"): #Si es cancelar, volvemos al menú prinpcipal.
                os.system("clear")
                break

            req = requests.get("http://localhost:8080/buscar-por-dni/"+str(dni)) #Si no, enviamos el request al servidor con el DNI.
            req = req.json() #Guardamos la respuesta del servidor con los datos del usuario solicitado.

            if req["dni"] == False: # si el req es False, quiere decir que no ha encontrado a un usuario con ese DNI.
                print("Vaya, parece que te has equivocado escribiendo el DNI, intentalo de nuevo.\n")
                continue
                
            print("El usuario con DNI: '" + str(req["dni"]) + "' tiene los siguientes datos: "  #Imprimimos los datos del usuario solicitado.
            + "\n Nombre: " + str(req["nombre"]) + "\n Correo: " + str(req["correo"])
            + "\n Departamento: " + str(req['dep']) + "\n Categoría: " + str(req['cat']))

            if(req["cat"] == "PDI"): #Si el usuario es PDI, también imprimimos sus asignaturas.
                print("\n Asignaturas: " + str(req["asig"]))
            print("\n[1] Buscar otro usuario \n[2] Volver al menu")

            while True: #Damos la opción de buscar a otro usuario o salir al menú principal.
                op = int(input("Selección: "))

                if op == 1:
                    busqueda_dni()
                    break
                if op == 2:
                    principal()
                    break


def comprobacion_correo(correo): #FUNCION AUXILIAR comprobar correo: comprueba mediante la librería "re" y expresiones si el correo es correcto.
    
    exp = '^(\w|\.|\_|\-)+[@](\w|\_|\-|\.)+[.]\w{2,3}$' #Declaramos las expresiones para comprobar que realmente es un correo.
    
    if(re.search(exp, correo)): #Si encuentra las expresiones en el correo utilizando re.search, es válido y devuelve true
        return True
    else: #Si no, el correo no es válido.
        return False

def salir():  
    print ("\nServicio Terminado, Gracias por su uso.")
    exit()  


principal()