//Agenda
     #include <stdio.h>
     #include <stdlib.h>
     #include <conio.h>
     #include <string.h>
     #define NAME_ARCHIVE "contacts.bin"
     #define NAME_ARCHIVE_AUX "contacts_aux.bin"
     //Contactos
     typedef struct contacts{
         char name[20];
         char direcction[30];
         int phone;
     }Contacts;
     //Funciones
     void menu(char *nameArchive);
     Contacts createContact();
     void saveContact(Contacts contact, char *nameArchive);
     void showContacts(char *nameArchive);
     void deleteContact(char *nameArchive);
     void stop();

     int main (){

         menu(NAME_ARCHIVE);
         stop();
         return 0;
     }

     void menu(char *nameArchive)
     {
         int op;
         do{
             system("cls");
             printf("[1]Create contact\n");
             printf("[2]Show contacts\n");
             printf("[3]Delete contact\n");
             printf("[4]Exit\n");
             printf("Login option: ");
             scanf("%i",&op);
         if(op>0 && op<5){
             system("cls");
             switch(op){
                 case 1:
                     saveContact(createContact(),NAME_ARCHIVE);
                     break;
                 case 2:
                     showContacts(NAME_ARCHIVE);
                     break;
                 case 3:
                     deleteContact(NAME_ARCHIVE);
                     break;
                 case 4:
                     exit(1);
                 default:
                     printf("wrong choice\n");
                     stop();
             }
         }
         }while(op!=4);
     }
     //Creando el contacto
     Contacts createContact()
     {
         Contacts contact;
         printf("Name:\n");
         fflush(stdin);
         gets(contact.name);
         printf("Direcction:\n");
         fflush(stdin);
         gets(contact.direcction);
         printf("Phone number:\n");
         scanf("%i",&contact.phone);

         return contact;
     }

     void saveContact(Contacts contact, char* nameArchive)
     {
         FILE* file;
         //si el archivo existe va a
         //gregar el nuevo contacto que creamos al final del archivo
         //no va a sobreescribir
         file=fopen(nameArchive,"ab");

         if(!file){
             printf("Error\n");
             stop();
         }
         else{
             //Recibe 4 parametros:
             //1-Dirección de memoria de la variable que queremos guardar
             //2-El tamaño del tipo de dato
             //3-La cantidad de datos que queremos guardar
             //4-La variable del archivo
             fwrite(&contact, sizeof(Contacts),1, file);
             printf("Contact Save!\n");
             stop();
             fclose(file);
         }

     }

     void deleteContact(char *nameArchive)
     {
         system("cls");
         FILE *file, *fileAux;
         Contacts contact;
         fileAux=fopen(NAME_ARCHIVE_AUX,"wb");
         file=fopen(nameArchive,"rb");

         if(!file){
             printf("Empty\n");
         }
         else{

             char name[20];
             printf("Name of the contact to delete:\n");
             fflush(stdin);
             gets(name);
             //Recibe los mismo parametros que fwrite
             while(fread(&contact, sizeof(Contacts),1, file)){

                 if (!strcmp(contact.name,name))
                 fwrite(&contact, sizeof(Contacts),1, fileAux);
             }
             fileAux=fopen(NAME_ARCHIVE_AUX,"rb");
             file=fopen(nameArchive,"wb");
             while(fread(&contact, sizeof(Contacts),1, fileAux)){

                 fwrite(&contact, sizeof(Contacts),1, file);
             }

         }

         stop();
         fclose(file);
         fclose(fileAux);
         remove(fileAux);
     }
     //Mostrar contactos
     void showContacts(char *nameArchive)
     {
         FILE *file;
         file=fopen(nameArchive,"rb");
         if(!file){
             printf("Empty\n");
             stop();
         }
         else{
             Contacts contact;
             printf("%-20s %-30s %-30s\n", "Name", "Direcction","Phone");
             //recibe los mismo parametros que fwrite
             while(fread(&contact, sizeof(Contacts),1, file)){
                 printf("%-20s %-30s %-30i\n", contact.name, contact.direcction,contact.phone);

             }

             fclose(file);
             printf("\n");
             stop();

         }
     }

     void stop()
     {
         printf("Press any key to continue...\n");
         getch();
     }
