#include "Map.h"
#include "list.h"
#include "juego.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregarDinero(tipoUsuario* usuarioActual){
  int opcion;
  tipoHisto* registro = (tipoHisto *) malloc(sizeof(tipoHisto));
  registro->accion = AGREGAR_DINERO;

  printf(" == Cuanto dinero desea agregar? == \n");
  for(int i = 1; i < 10; i++){
    printf("-%i- %i \n",i,i*5000);
  }
  printf("-10- Otro monto\n");
  printf("Ingresa una opción: ");
  scanf("%i",&opcion);

  while(opcion <= 0 || opcion > 10){
    printf("Ingrese una opción válida: ");
    scanf("%i",&opcion);
  }

  if(opcion > 0 && opcion < 10){
    printf("Has ingresado %i a tu cuenta exitosamente.\n",opcion*5000);
    usuarioActual->dinero += opcion*5000;
    registro->cantidad = opcion*5000;
  }
  else{
    printf("Ingresa el monto que quieres ingresar: ");
    scanf("%i",&opcion);
    printf("Has ingresado %i a tu cuenta exitosamente.\n",opcion);
    usuarioActual->dinero += opcion;
    registro->cantidad = opcion;
  }
  
  pushFront(usuarioActual->historial, registro);
  menuBalance(usuarioActual);
}

void retirarDinero(tipoUsuario* usuarioActual){
  int opcion;
  tipoHisto* registro = (tipoHisto *) malloc(sizeof(tipoHisto));
  registro->accion = RETIRAR_DINERO;
  
  if(usuarioActual->dinero == 0){
    printf("No tienes dinero para retirar.\n");
    menuBalance(usuarioActual);
  }
  printf(" === Cuanto dinero desea retirar? === \n");
  for(int i = 1; i < 10; i++){
    printf("-%i- %i \n",i,i*5000);
  }
  printf("-10- Otro monto\n");
  printf("-11- Todo el dinero\n");
  printf("Ingresa una opción: ");
  scanf("%i",&opcion);

  while(opcion <= 0 || opcion > 11){
    printf("Ingrese una opción válida: ");
    scanf("%i",&opcion);
  }

  if(opcion > 0 && opcion < 10){
    if(opcion * 5000 > usuarioActual->dinero){
      printf("No puedes retirar más dinero del que tienes.\n");
      retirarDinero(usuarioActual);
    }
    printf("Has retirado %i a tu cuenta exitosamente.\n",opcion*5000);
    usuarioActual->dinero -= opcion*5000;
    registro->cantidad = opcion*5000;
  }
  else if (opcion == 10){
    printf("Ingresa el monto que quieres retirar: ");
    scanf("%i",&opcion);
    if(opcion > usuarioActual->dinero){
      printf("No puedes retirar más dinero del que tienes.\n");
      retirarDinero(usuarioActual);
    }
    printf("Has retirado %i de tu cuenta exitosamente.\n",opcion);
    usuarioActual->dinero -= opcion;
    registro->cantidad = opcion;
  }
  else{
    printf("Has retirado todo el dinero exitosamente.\n");
    registro->cantidad = usuarioActual->dinero;
    usuarioActual->dinero = 0;
  }
  pushFront(usuarioActual->historial, registro);
  menuBalance(usuarioActual);
}

void verHistorial(tipoUsuario* usuarioActual){
  int contador = 1;
  printf(" === HISTORIAL DE LA CUENTA === \n");
  
  tipoHisto *aux = firstList(usuarioActual->historial);
  while(aux != NULL){
    printf(" %i - ",contador);
    switch(aux->accion){
      case AGREGAR_DINERO:
        printf("Ingresaste %.2f\n",aux->cantidad);
        break;
      case RETIRAR_DINERO:
        printf("Retiraste %.2f\n",aux->cantidad);
        break;
      case APUESTA:
        printf("Apostaste %.2f\n",aux->cantidad);
        break;
      case GANANCIA:
        printf("Ganaste %.2f\n",aux->cantidad);
        break;
    }
    aux = nextList(usuarioActual->historial);
    contador++;
    if(contador == 11) break;
  }
  printf(" ============================== \n");
  menuBalance(usuarioActual);
}

void menuBalance(tipoUsuario* usuarioActual){
  if(usuarioActual==NULL){
    printf("No hay ningún usuario ingresado.\n");
    return;
  }
  
  int titulo = 0, opcion;
  if (titulo == 0) {
      printf("==============================================================\n");
      printf(" ===================== MENÚ DE BALANCE ===================== \n");
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
    printf("1. Ingresar dinero\n");
    printf("2. Retirar dinero\n");
    printf("3. Ver historial de movimientos\n");
    printf("4. Volver al Menú Principal\n");
    printf("==============================================================\n");
    printf("Ingresa una opción: ");

    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 4) {
      printf("Ingresa una opción válida: ");
      scanf("%d", &opcion);
    }
    getchar();
    //Ahora según opción haremos las opciones del menú
    switch (opcion) {
      case 1:
        agregarDinero(usuarioActual);
        break;
      case 2:
        retirarDinero(usuarioActual);
        break;
      case 3:
        verHistorial(usuarioActual);
        break;
      case 4:
        printf("Volviendo al menú principal...\n");
        return;
        break;
    }
}