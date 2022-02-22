from bottle import run, route, get, post, request, delete, put ,response  #Importamos bottle con sus respectivas funciones
import json	  #Importar json

database = dict()   #Identificador --> dni, valor --> Usuario

class Usuario:			#Creamos la clase Usuario
	def __init__(self, dni, nombre, correo, dep, cat, asig):    #Constructor con sus respectivas variables	
         self.dni = dni	  #En el constructor, vamos dandole valores a la clase Usuario
         self.nombre = nombre
         self.correo = correo
         self.dep = dep
         self.cat = cat
         self.asig = asig

def persistencia():  #Función para guardar los usuarios tanto dados de alta, como modificados, como eliminados en un .txt

    f = open('info.txt', 'w')  #El .txt lo abriremos con la función open y el método write
    for key , value in database.items():   #Recorremos el diccionario e imprimimos la info que haya en el
        mostrar_info = '{"dni" : "' + str(value.dni)  + '" , "nombre" : "' + str(value.nombre) + '" , "correo" : "' + str(value.correo) + '" , "departamento" :  "' + str(value.dep) + '" , "categoria" : "' + str(value.cat) + '" , "asignatura" : "' + str(value.asig) +"\"}\n"
        f.write(mostrar_info)   #La cadena anterior se escribe en el .txt
    f.close()   #Cerrar .txt

def cargar_persist():  #Función para cargar los usuarios guardados una vez se inicie el server
    for cont in open('info.txt', 'r'):   #Abrimos el .txt con la función open y el método read, lo recorremos con un for
        lista = json.loads(cont)   #Introducimos json en una variable y luego añadimos otras variables para ir introduciendo los json del .txt
        dni = lista.get('dni')
        nombre = lista.get('nombre')
        correo = lista.get('correo')
        dep = lista.get('departamento')
        cat = lista.get('categoria')
        if(cat == 'PDI'):
            asig = lista.get('asignatura')
            usuario = Usuario(dni,nombre, correo, dep, cat, asig) #Llamada al constructor e introducir el objeto Usuario en una variable (CON ASIGNATURAS)
        else:  
            usuario = Usuario(dni, nombre, correo, dep, cat, "")
        database[dni] = usuario   #Se guarda en el diccionario, la key es el dni


@post('/dar-alta-usuario')	#Endpoint del tipo post
def dar_alta_usuario():		#Función para dar de alta a un miembro en el server

    datos = request.json	#Petición al cliente para obtener el json	

    dni = datos.get('dni')    #Introducimos en variables los json
    nombre = datos.get('nombre')
    correo = datos.get('correo')
    dep = datos.get('dep')
    cat = datos.get('cat')
    if(cat == "PDI"):
        asig = datos.get('asig')
        usuario = Usuario(dni, nombre, correo, dep, cat, asig)
    else:
        usuario = Usuario(dni, nombre, correo, dep, cat, "") 
    
    for key , value in database.items():
        if(dni == key):
            return "El usuario ya consta en la base."
        else:
            pass

    database[dni] = usuario			#Si el bucle continúa hasta salir, se debe a que dicho dni no está en el diccionario, por lo tanto podemos añadir el nuevo usuario.
    persistencia()      #Llamamos a la función para guardar el alta en el .txt
	
    print(database[dni].dni)	   #Imprimimos el dni a modo de confirmación del alta				

    return "USUARIO REGISTRADO CON EXITO"	#Devolvemos mensaje de éxito en el resgistro

@put('/modif_miembro/<dni_user>/<what_change>/<new_change>')   #Endpoint tipo put, con sus respectivos parámetros
def change_user(dni_user, what_change, new_change):   #Función que nos permitirá modificar datos de un usuario
    usuario = database[dni_user]  #Buscamos que el usuario está en el diccionario

    if(int(what_change) == 1):   #Según la opción elegida vamos a cambiar un dato u otro y guardamos el nuevo cambio
        usuario.nombre = new_change
    elif(int(what_change)==2):
        usuario.correo = new_change
    elif(int(what_change)==3):
        usuario.dep = new_change
    elif(int(what_change)==4):
        usuario.cat = new_change
    elif(int(what_change)==5):
        usuario.asig = new_change

    response.headers['Content-Type'] = 'application/json'   #Avisamos al cliente del tipo de contenido que se le va a devolver

    devolver_json = {'dni' : dni_user, 'nombre' : usuario.nombre, 'correo' : usuario.correo, 'dep' : usuario.dep, 'cat' : usuario.cat, 'asig' : usuario.asig}   #Guardamos en una variable
    persistencia()   #Llamamos a la función para guardar en el .txt
    
    return json.dumps(devolver_json)   #Devolvemos tipo json

@get('/listar_miembros')   #Endpoint tipo get
def miembros_server():   #Función para listar todos los miembros del server

    devuelve = []   #Creación de la lista

    for key , value in database.items():   #Recorremos el diccionario con un for
        devuelve.append({'dni' : key, 'nombre' : value.nombre, 'correo' : value.correo})  #Cargamos en la lista creada los usuarios ya registrados

    response.headers['Content-Type'] = 'application/json'   #Aviso al cliente
    return json.dumps(devuelve)    #Devolvemos tipo json

@get('/buscar-por-dni/<dni_user>')  #Endpoint tipo get con el parámetro dni del usuario
def busqueda_dni(dni_user):   #Esta función nos permitirá buscar a un miembro por su dni

    for key, value in database.items():  #Recorremos el diccionario
        if(dni_user == key):    #Si coincide el dni con el buscado en el diccionario sacamos los valores y los guardamos en una variable lista
            lista = {'dni' : key, 'nombre' : value.nombre, 'correo' : value.correo, 'dep' : value.dep, 'cat' : value.cat, 'asig' : value.asig}

            response.headers['Content-Type'] = 'application/json'  #Aviso al cliente
            return json.dumps(lista)   #Devuelve la lista de los datos del usuario en tipo json
        else:
            pass  #Si no hay coincidencia seguimos recorriendo
    response.headers['Content-Type'] = 'application/json'
    
    lista = {'dni' : False}   #Si sale del bucle es porque no existe el dni y devolvemos False
    return json.dumps(lista)   #Devolvemos la lista tipo json

@get('/buscar-por-nombre/<nom_user>')   #Endpoint tipo get
def busqueda_nombre(nom_user):   #Función de mejora que sirve para buscar un miembro mediante su nombre parcialmente

    lista = [] #Declaramos la lista de posbiles usuarios con ese nombre.

    for key, value in database.items():   #Recorremos el diccionario
        if(nom_user in value.nombre):   #Si el nombre del usuario coincide parcialmente con el del diccionario nos muestra sus datos
            lista.append({'dni' : key, 'nombre' : value.nombre, 'correo' : value.correo}) #Guardamos en la lista los datos basicos de las personas que coincidan con el nombre buscado.
        else:
            pass 
    
    response.headers['Content-Type'] = 'application/json'
    return json.dumps(lista)   #Devolvemos la lista con los datos del usuario en tipo json

@get('/miemb_categoria/<categoria>')   #Endpoint tipo get
def miembros_cat(categoria):   #Función para mostrar los miembros que pertenezcan a la categoría indicada

    devuelve = []   #Creamos listado

    for key , value in database.items():  #Recorremos el diccionario
        if(value.cat == categoria):   #Si la categoría coincide con la del diccionario nos devuelve los datos sobre los usuarios de la categoría
          devuelve.append({'dni' : key, 'nombre' : value.nombre, 'correo' : value.correo})  
        else:
            pass   #Si no hay coincidiencia sigue recorriendo el diccionario

    response.headers['Content-Type'] = 'application/json'
    return json.dumps(devuelve)   #Devuelve la lista en tipo json

@delete('/eliminar/<dni_user>')   #Endpoint tipo delete
def eliminar(dni_user):   #Función para dar de baja o eliminar la cuenta de un usuario

    for key , value in database.items():   #Recorremos el diccionario
        if(dni_user == key):   #Si el dni coincide con el del diccionario
           del database[dni_user]   #Borramos de el diccionario al usuario
           persistencia()   #Llamamos a la función para actualizar el .txt
           return 'El usuario ha sido eliminado'  #Devuelve mensaje de operación realizada con éxito
        else:
            pass
    
    return 'El usuario indicado no existe'   #Si sale del bucle y no ha habido coincidencia se devuelve un mensaje de error


if __name__ == '__main__':		
    cargar_persist()		#Llamamos a la función creada para cargar la información del servidor en la función principal
    run(host='localhost', port=8080, debug=True,reloader=True)      #Iniciamos el servidor con su respectiva dirección y puerto

	
