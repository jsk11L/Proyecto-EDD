#include "Map.h"
#include "list.h"
#include "juego.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  Map* usuarios = createMap(is_equal_string);
  
  tipoUsuario *usuarioActual = NULL;
   
  int opcion, titulo = 0;

  while (1) {
    if (titulo == 0) {
      printf("==============================================================\n");
      printf(" ====================== MENÚ PRINCIPAL ====================== \n");
      titulo++;
    }
    printf("==============================================================\n");
    printf(" Usuario Conectado : ");
    if(usuarioActual == NULL) printf("No hay ningún usuario conectado\n");
    else printf("%s\n",usuarioActual->user);
    printf(" Balance : ¥ ");
    if(usuarioActual == NULL) printf("NULL\n");
    else printf("%.2f\n",usuarioActual->dinero);
    printf("==============================================================\n");
    printf("Escoja una opción: \n");
    printf("1. Registrar usuario\n");
    printf("2. Cambiar de usuario\n");
    printf("3. Manejar usuarios\n");
    printf("4. Manejar balance\n");
    printf("5. Jugar\n");
    printf("6. Salir\n");
    printf("==============================================================\n");
    printf("Ingresa una opción: ");

    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 6) {
      printf("Ingresa una opción válida: ");
      scanf("%d", &opcion);
    }
    getchar();
    //Ahora según opción haremos las opciones del menú
    switch (opcion) {
    case 1:
      usuarioActual = registrarUsuario(usuarios);
      break;
    case 2:
      usuarioActual = cambiarUsuario(usuarios, usuarioActual);
      break;
    case 3:
      usuarioActual = manejarUsuarios(usuarios, usuarioActual);
      break;
    case 4:
      menuBalance(usuarioActual);
      break;
    case 5:
      menuJuego(usuarioActual);
      break;
    case 6:
      printf("Cerrando el juego...\n");
      return 0;
    }
  }
  return 0;
}