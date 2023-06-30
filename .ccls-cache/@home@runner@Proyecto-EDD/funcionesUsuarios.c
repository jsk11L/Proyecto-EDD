#include "Map.h"
#include "list.h"
#include "juego.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void leerCadena(char cadena[31]) {
  scanf("%30[^\n]s", cadena);
  getchar();
}

int is_equal_string(void *key1, void *key2) {
  if (strcmp((char *)key1, (char *)key2) == 0)
    return 1;
  return 0;
}

tipoUsuario* crearUsuario(char user[], char pass[]) {
  tipoUsuario * new = (tipoUsuario *)malloc(sizeof(tipoUsuario));
  new->historial = createList();
  assert(new != NULL);
  strcpy(new->user,strdup(user));
  strcpy(new->pass,strdup(pass));
  new->dinero = 0;
  new->gananciasTotales = 0;
  new->dificultad = 1;
  new->modo = 1;
  new->difM = false;
  new->difD = false;
  new->bonus = 0;
  return new;
}

bool verificarContrasena(tipoUsuario* aux, char contrasena[]){
  if(strcmp(contrasena,aux->pass)==0){
    return true;
  }
  
  for(int i = 3; i > 0; i--){
      printf("Contraseña equivocada.\nTe quedan %i intentos\n",i);
      printf("Ingrese la contraseña: ");
      leerCadena(contrasena);
      if(strcmp(contrasena,aux->pass)==0){
        return true;
      }
    }
  printf("No tiene más intentos, volviendo al menú principal\n");
  return false;
}

tipoUsuario* registrarUsuario(Map* usuarios){
  char usuario[30]="";
  char contrasena[30]="";
  int respuesta;
  
  printf("Ingrese el usuario: ");
  leerCadena(usuario);

  printf("Ingrese la contraseña: ");
  leerCadena(contrasena);

  tipoUsuario * aux = crearUsuario(usuario, contrasena);
  
  printf("Quiere guardar el usuario en el sistema?\n");
  printf("Ingrese 1 para Sí, 0 para No: ");
  scanf("%i",&respuesta);
  if(respuesta == 1){
    printf("Usuario ingresado al sistema.\n");
    insertMap(usuarios, aux->user, aux);
  }
  return aux;
}

tipoUsuario* cambiarUsuario(Map* usuarios, tipoUsuario* usuarioActual){
  char usuario[30] = "";
  char contrasena[30] = "";
  int contador = 1;

  tipoUsuario * aux = firstMap(usuarios);
  if(aux == NULL){
    printf("No hay ningún usuario ingresado.\n");
    return usuarioActual;
  }
  printf(" === LISTA DE USUARIOS === \n");
  while(aux != NULL){
    printf("%i - %s\n",contador,aux->user);
    contador++;
    aux = nextMap(usuarios);
  }
  printf(" ========================= \n");

  printf("Ingrese el usuario: ");
  leerCadena(usuario);
  aux = searchMap(usuarios, usuario);
  while(aux == NULL){
    printf("Usuario no encontrado, ingrese un usuario existente\n");
    printf("Ingrese el usuario: ");
    leerCadena(usuario);
    aux = searchMap(usuarios, usuario);
  }

  printf("Ingrese la contaseña: ");
  leerCadena(contrasena);

  if(verificarContrasena(aux,contrasena)==true){
    printf("Sesión iniciada correctamente\n");
    return aux;
  }
  else return usuarioActual;
}

tipoUsuario* manejarUsuarios(Map* usuarios, tipoUsuario* usuarioActual){
  char usuario[30] = "";
  char contrasena[30] = "";
  int contador = 1;

  tipoUsuario * aux = firstMap(usuarios);
  if(aux == NULL){
    printf("No hay ningún usuario ingresado.\n");
    return usuarioActual;
  }

  printf(" === LISTA DE USUARIOS === \n");
  while(aux != NULL){
    printf("%i - %s\n",contador,aux->user);
    contador++;
    aux = nextMap(usuarios);
  }
  printf(" ========================= \n");

  printf("Ingrese el usuario: ");
  leerCadena(usuario);
  aux = searchMap(usuarios, usuario);
  while(aux == NULL){
    printf("Usuario no encontrado, ingrese un usuario existente\n");
    printf("Ingrese el usuario: ");
    leerCadena(usuario);
    aux = searchMap(usuarios, usuario);
  }

  int respuesta;
  printf("Que desea hacer?\n");
  printf("1. Eliminar el usuario\n");
  printf("2. Cambiar la contraseña\n");
  scanf("%i",&respuesta);
  getchar();
  switch(respuesta){
    
    case 1:
      printf("Ingrese la contraseña: ");
      leerCadena(contrasena);
      if(verificarContrasena(aux,contrasena)== true){
        printf("Usuario eliminado correctamente\n");
        eraseMap(usuarios,aux);
        if(aux == usuarioActual) return NULL;
      }
      break;
    
    case 2:
      printf("Ingrese la contraseña: ");
      leerCadena(contrasena);
      if(verificarContrasena(aux,contrasena)== true){
        printf("Ingrese la nueva contraseña: ");
        leerCadena(contrasena);
        printf("Contraseña cambiada correctamente\n");
        strcpy(aux->pass,contrasena);
      }
      break;
  }
  return usuarioActual;
}