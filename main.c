#include "Map.h"
#include "list.h"
#include "juego.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  /*Map* usuarios = createMap(is_equal_string);
  
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
  }*/
  tipoResult resultados[3][3];
  int dificultad = 2;
  int contadorG = 0;
  int contadorP = 0;
  int contadorB = 0;
  int contadorPremios = 0;
  bool gano = false;
  for(int vez = 0; vez < 10000; vez++){
    contadorPremios = 0;
    gano = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          resultados[i][j].valor = rand() % 680000;
          if(resultados[i][j].valor < 0) resultados[i][j].valor *= -1;
        }
      }
    
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        switch(dificultad){
          case 1:
            if(resultados[i][j].valor < 340001){
              resultados[i][j].dibujo = CEREZA;
            }
            if(resultados[i][j].valor < 300001){
              resultados[i][j].dibujo = SIETE;
            }
            if(resultados[i][j].valor < 200001){
              resultados[i][j].dibujo = BAR;
            }
            if(resultados[i][j].valor < 100001){
              resultados[i][j].dibujo = DIAMANTE;
            }
            if(resultados[i][j].valor < 50001){
              resultados[i][j].dibujo = CAMPANA;
            }
            break;
          
          case 2:
            if(resultados[i][j].valor < 680001){
              resultados[i][j].dibujo = CEREZA;
            }
            if(resultados[i][j].valor < 600001){
              resultados[i][j].dibujo = SIETE;
            }
            if(resultados[i][j].valor < 400001){
              resultados[i][j].dibujo = BAR;
            }
            if(resultados[i][j].valor < 200001){
              resultados[i][j].dibujo = DIAMANTE;
            }
            if(resultados[i][j].valor < 100001){
              resultados[i][j].dibujo = CAMPANA;
            }
            break;
          
          case 3:
            if(resultados[i][j].valor < 1000001){
              resultados[i][j].dibujo = CEREZA;
            }
            if(resultados[i][j].valor < 889001){
              resultados[i][j].dibujo = BAR;
            }
            if(resultados[i][j].valor < 650001){
              resultados[i][j].dibujo = SIETE;
            }
            if(resultados[i][j].valor < 292001){
              resultados[i][j].dibujo = CAMPANA;
            }
            if(resultados[i][j].valor < 146001){
              resultados[i][j].dibujo = DIAMANTE;
            }
            break;
          }
        }
      }
    
    for(int i = 0; i < 3; i++){
      if(resultados[i][0].dibujo == resultados[i][1].dibujo && resultados[i][0].dibujo == resultados[i][2].dibujo){
        contadorPremios++;
        gano = true;
      }
      if(resultados[0][i].dibujo == resultados[1][i].dibujo && resultados[0][i].dibujo == resultados[2][i].dibujo){
        contadorPremios++;
        gano = true;
      }
    }
  
    if(resultados[0][0].dibujo == resultados[1][1].dibujo && resultados[0][0].dibujo == resultados[2][2].dibujo){
      contadorPremios++;
      gano = true;
    }
  
    if(resultados[0][2].dibujo == resultados[1][1].dibujo && resultados[0][2].dibujo == resultados[2][0].dibujo){
      contadorPremios++;
      gano = true;
    }

    if(gano == true) contadorG++;
    else contadorP++;
    if(contadorPremios > 2) contadorB++;
  }

  printf("DE 10000 TIRADAS: \n");
  printf("GANASTE : %i VECES\n",contadorG);
  printf("PERDISTE : %i VECES\n",contadorP);
  printf("OBTUVISTE RONDAS BONUS : %i VECES\n",contadorB);
  
  return 0;
}