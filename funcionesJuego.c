#include "Map.h"
#include "list.h"
#include "juego.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFigura(Figura dibujo, int linea){
  
  switch(dibujo){
    case DIAMANTE:
      if(linea == 1) printf("                   ");
      if(linea == 2) printf("                   ");
      if(linea == 3) printf("   .     '     ,   ");
      if(linea == 4) printf("     _________     ");
      if(linea == 5) printf("  _ /_|_____|_\\ _  ");
      if(linea == 6) printf("    '. \\   / .'    ");
      if(linea == 7) printf("      '.\\ /.'      ");
      if(linea == 8) printf("        '.'        ");
      if(linea == 9) printf("                   ");
      if(linea == 10) printf("                   ");
      break;
    case CEREZA:
      if(linea == 1) printf("                   ");
      if(linea == 2) printf("  __.--~~.,-.__    ");
      if(linea == 3) printf(" `~-._.-(`-.__`-.  ");
      if(linea == 4) printf("         \\    `~~` ");
      if(linea == 5) printf("    .--./ \\        ");
      if(linea == 6) printf("   /#   \\  \\.--.   ");
      if(linea == 7) printf("   \\    /  /#   \\  ");
      if(linea == 8) printf("    '--'   \\    /  ");
      if(linea == 9) printf("            '--'   ");
      if(linea == 10) printf("                   ");
      break;
    case SIETE:
      if(linea == 1) printf("                   ");
      if(linea == 2) printf("    ___________    ");
      if(linea == 3) printf("   |______     |   ");
      if(linea == 4) printf("         /    /    ");
      if(linea == 5) printf("        /    /     ");
      if(linea == 6) printf("       /    /      ");
      if(linea == 7) printf("      /    /       ");
      if(linea == 8) printf("     /____/        ");
      if(linea == 9) printf("                   ");
      if(linea == 10) printf("                   ");
      break;
    case BAR:
      if(linea == 1) printf("                   ");
      if(linea == 2) printf("                   ");
      if(linea == 3) printf("_____  ___  ____   ");
      if(linea == 4) printf("| __ \\/ _ \\ | __ \\ ");
      if(linea == 5) printf("| |/ / /_\\ \\| |/ / ");
      if(linea == 6) printf("| __ \\  _  ||   /  ");
      if(linea == 7) printf("| |/ / | | || |\\ \\ ");
      if(linea == 8) printf("\\___/\\_| |_/\\_| \\_|");
      if(linea == 9) printf("                   ");
      if(linea == 10) printf("                   ");
      break;
    case CAMPANA:
      if(linea == 1) printf("         ██        ");
      if(linea == 2) printf("       ██  ██      ");
      if(linea == 3) printf("     ██      ██    ");
      if(linea == 4) printf("     ██      ██    ");
      if(linea == 5) printf("   ██          ██  ");
      if(linea == 6) printf("   ██          ██  ");
      if(linea == 7) printf(" ██              ██");
      if(linea == 8) printf(" ██████████████████");
      if(linea == 9) printf("         ██        ");
      if(linea == 10) printf("          ██       ");
      break;
  } 
}

void instrucciones() {
  char respuesta[30];

  printf("//////////////////INSTRUCCIONES//////////////////\n\n");
  
  printf("Bienvenido a las instrucciones de JackPotCherry\n");

  printf("-------------------------------------------------\n");
  
  printf("Objetivo del juego\n\n");
  
  printf("El objetivo esencial del juego es la diversión y el entretenimiento.\n\n");
  printf("El juego en sí consiste en una máquina 'tragamonedas' que contiene una cantidad de 5 símbolos\n");
  printf("posibles para su aparición, cada uno tiene un %% distinto de aparición.\n");
  printf("Los símbolos son: DIAMANTE, CEREZA, SIETE, BAR Y CAMPANA.\n\n");
  
  printf("-------------------------------------------------\n");
  
  printf("Hablando ya en base al objetivo que conlleva el juego nos encontramos con que el objetivo principal\n");
  printf("es el de obtener una combinación ganadora de símbolos al momento de hacer la apuesta.\n");
  printf("-------------------------------------------------\n");

  
  printf("Combinaciones ganadoras\n\n");
  
  printf("Las posibles formas ganadoras son: FILA, COLUMNA, DIAGONAL Y DIAGONAL INVERTIDA.\n");
  printf("Si se consigue una sucesión de los 3 simbolos iguales en alguna de las formas mencionadas se gana\n");
  printf("-------------------------------------------------\n\n");

  printf(" Ingresa cualquier caracter para volver al menú principal!\n");
  
  scanf("%c",&respuesta);
  return;
}


void jackpotCherry(tipoUsuario* usuarioActual){
  tipoResult resultados[3][3];
  char respuesta[100];
  usuarioActual->bonus++;
  
  while(1){
    float apuesta = 0;
    printf("->Cuanto vas a apostar?\n");
    switch(usuarioActual->dificultad){
      case 1:
        printf("->Por tu dificultad, puedes apostar entre ¥100 y ¥500.\n");
        apuesta = leerApuesta(usuarioActual, 100, 500);
        break;
      
      case 2:
        printf("->Por tu dificultad, puedes apostar entre ¥500 y ¥2000.\n");
        apuesta = leerApuesta(usuarioActual, 500, 2000);
        break;
      
      case 3:
        printf("->Por tu dificultad, puedes apostar entre ¥2000 y ¥5000.\n");
        apuesta = leerApuesta(usuarioActual, 2000, 5000);
        break;
      
    }
    while(usuarioActual->bonus > 0){
      usuarioActual->bonus--;
      if(usuarioActual->bonus != 0){
        printf("\n\n RONDA BONUS ! \n\n");
      }
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          switch(usuarioActual->dificultad){
            case 1:
              resultados[i][j].valor = rand() % 340000;
              if(resultados[i][j].valor < 0) resultados[i][j].valor *= -1;
              break;        
            
            case 2:
              resultados[i][j].valor = rand() % 680000;
              if(resultados[i][j].valor < 0) resultados[i][j].valor *= -1;
              break; 
            
            case 3:
              resultados[i][j].valor = rand() % 1000000;
              if(resultados[i][j].valor < 0) resultados[i][j].valor *= -1;
              break; 
            
          }
        }
      }
      calcularResultado(resultados, apuesta, usuarioActual);
      if(usuarioActual->bonus != 0){
        printf("\n = RONDA BONUS  = \n");
        printf("No se te cobró dinero !\n\n");
        printf("Rondas bonus restantes : %i\n",usuarioActual->bonus);
        printf("Ingresa cualquier cáracter para continuar la secuencia: ");
        scanf("%s",&respuesta);
        getchar();
      }
    }
    
    int opcion = 0;
    printf("Quieres seguir jugando?\n");
    printf("1 para SÍ | 0 para NO :");
    scanf("%i",&opcion);
    if(opcion == 0) break;
    usuarioActual->bonus++;
  }
  menuJuego(usuarioActual);
}

float leerApuesta(tipoUsuario* usuarioActual, float lim1, float lim2){
  float apuesta = 0;
  tipoHisto* registro = (tipoHisto *) malloc(sizeof(tipoHisto));
  registro->accion = APUESTA;
  
  scanf("%f",&apuesta);
      while(1){
        if(apuesta < lim1 || apuesta > lim2){
          printf("Solo puedes apostar entre ¥%.2f y ¥%.2f.\n",lim1,lim2);
          printf("Ingresa otra cantidad: ");
        }
        else if(apuesta > usuarioActual->dinero){
          printf("No tienes el dinero para apostar esa cantidad.\n");
          printf("Ingresa otra cantidad: ");
        }
        if(apuesta < usuarioActual->dinero && apuesta >= lim1 && apuesta <= lim2){
          usuarioActual->dinero -= apuesta;
          registro->cantidad = apuesta;
          break;
        }
        scanf("%f",&apuesta);
      }
  pushFront(usuarioActual->historial, registro);
  return apuesta;
}

void elegirDificultad(tipoUsuario* usuarioActual){
  printf("- NIVELES DE DIFICULTAD -\n");
  printf("1 -> Fácil\n");
  printf("2 -> Medio\n");
  printf("3 -> Difícil\n");
  printf("4.-> Volver al menú\n\n");
  printf("Ingresa una opción: ");
  int opcion = 0;
  scanf("%i",&opcion);
  while(1){
    if(opcion < 1 || opcion > 4) printf("Ingresa una opción válida\n");
    else if (opcion == 2 && usuarioActual->difM == false) printf("No has desbloqueado la dificultad media!\n");
    else if (opcion == 3 && usuarioActual->difD == false) printf("No has desbloqueado la dificultad difícil!\n");
    else break;
    printf("Ingresa una opción: ");
    scanf("%i",&opcion);
  }

  if(opcion == 4) {
    menuJuego(usuarioActual);
  }

  printf("\n DIFICULTAD SELECCIONADA : %i\n",opcion);
  switch(opcion){
    case 1:
      printf("Fácil\n");
      break;
    case 2:
      printf("Medio\n");
      break;
    case 3:
      printf("Difícil\n");
      break;
  }
  usuarioActual->dificultad = opcion;
  menuJuego(usuarioActual);
}

void extras(tipoUsuario* usuarioActual){
  int opcion = 0;
  printf("========================================\n");
  printf("             MENU DE EXTRAS\n");
  printf("========================================\n");
  printf("1.- Mostrar dibujos al jugar\n");
  printf("2.- Mostrar nombre del dibujo resultante\n");
  printf("3.- Mostrar número randomizado obtenido\n");
  printf("4.- Volver al menú\n ");
  printf("Ingresa una opción: ");
  scanf("%i",&opcion);
  while(opcion > 4 || opcion < 1){
    printf("Ingrese una opción válida: ");
    scanf("%i",&opcion);
  }
  
  
  if(opcion == 4) {
    menuJuego(usuarioActual);
  }
  
  usuarioActual->modo = opcion;
  menuJuego(usuarioActual);
}

void calcularResultado(tipoResult resultados[][3], float apuesta, tipoUsuario* usuarioActual){
  float premio = 0;
  float aux = 0;
  tipoHisto* registro = (tipoHisto *) malloc(sizeof(tipoHisto));
  registro->accion = GANANCIA;
  registro->cantidad = 0;
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      switch(usuarioActual->dificultad){
        case 1:
          if(resultados[i][j].valor < 340001 && resultados[i][j].valor > 300000){
            resultados[i][j].dibujo = CEREZA;
          }
          if(resultados[i][j].valor < 300001 && resultados[i][j].valor > 200000){
            resultados[i][j].dibujo = DIAMANTE;
          }
          if(resultados[i][j].valor < 200001 && resultados[i][j].valor > 130000){
            resultados[i][j].dibujo = SIETE;
          }
          if(resultados[i][j].valor < 130001 && resultados[i][j].valor > 0){
            resultados[i][j].dibujo = CAMPANA;
          }
          break;
        
        case 2:
          if(resultados[i][j].valor < 680001 && resultados[i][j].valor > 600000){
            resultados[i][j].dibujo = CEREZA;
          }
          if(resultados[i][j].valor < 600001 && resultados[i][j].valor > 400000){
            resultados[i][j].dibujo = SIETE;
          }
          if(resultados[i][j].valor < 400001 && resultados[i][j].valor > 200000){
            resultados[i][j].dibujo = BAR;
          }
          if(resultados[i][j].valor < 200001 && resultados[i][j].valor > 100000){
            resultados[i][j].dibujo = DIAMANTE;
          }
          if(resultados[i][j].valor < 100001 && resultados[i][j].valor > 0){
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

  mostrarResultado(usuarioActual, resultados);

  int contadorPremios = 0;
  
  printf("\n");
  for(int i = 0; i < 3; i++){
    if(resultados[i][0].dibujo == resultados[i][1].dibujo && resultados[i][0].dibujo == resultados[i][2].dibujo){
      printf("Premio en la línea numero %i!\n",i+1);
      aux = calcularPremio(resultados[i][0].dibujo, apuesta, usuarioActual->dificultad);
      premio += aux;
      contadorPremios++;
    }
    if(resultados[0][i].dibujo == resultados[1][i].dibujo && resultados[0][i].dibujo == resultados[2][i].dibujo){
      printf("Premio en la columna numero %i!\n",i+1);
      aux = calcularPremio(resultados[0][i].dibujo, apuesta, usuarioActual->dificultad);
      premio += aux;
      contadorPremios++;
    }
  }

  if(resultados[0][0].dibujo == resultados[1][1].dibujo && resultados[0][0].dibujo == resultados[2][2].dibujo){
    printf("Premio en la diagonal!\n");
    aux = calcularPremio(resultados[0][0].dibujo, apuesta*1.2, usuarioActual->dificultad);
    premio += aux;
    contadorPremios++;
  }

  if(resultados[0][2].dibujo == resultados[1][1].dibujo && resultados[0][2].dibujo == resultados[2][0].dibujo){
    printf("Premio en la anti-diagonal!\n");
    aux = calcularPremio(resultados[0][0].dibujo, apuesta*1.2, usuarioActual->dificultad);
    premio += aux;
    contadorPremios++;
  }
  
  printf("\n");
  printf("======================\n");
  printf("GANANCIAS: %10.2f\n",premio);
  printf("DINERO:    %10.2f\n", usuarioActual->dinero);
  printf("======================\n\n");

  usuarioActual->dinero += premio;
  if(usuarioActual->dificultad == 1 && contadorPremios > 2){
    printf("Obtuviste más de 2 premios! Obtienes %i ronda(s) bonus!\n",contadorPremios-2);
    usuarioActual->bonus += contadorPremios-2;
  }
  else if(usuarioActual->dificultad == 2 && contadorPremios > 3){
    printf("Obtuviste más de 3 premios! Obtienes %i ronda(s) bonus!\n",contadorPremios-3);
    usuarioActual->bonus += contadorPremios-3;
  }
  else if(usuarioActual->dificultad == 3 && contadorPremios > 4){
    printf("Obtuviste más de 4 premios! Obtienes %i ronda(s) bonus!\n",contadorPremios-4);
    usuarioActual->bonus += contadorPremios-4;
  }
  
  
  usuarioActual->gananciasTotales+= premio;
  verificarDificultades(usuarioActual);
  registro->cantidad = premio;

  if(registro->cantidad != 0) pushFront(usuarioActual->historial, registro);
}

void verificarDificultades(tipoUsuario* usuarioActual){

  if(usuarioActual->difM == false && usuarioActual->gananciasTotales > 10000){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=\n");
    printf("            ¡DIFICULTAD MEDIA DESBLOQUEADA!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=\n");
    usuarioActual->difM = true;
  }

  if(usuarioActual->difD == false && usuarioActual->gananciasTotales > 50000){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=\n");
    printf("           ¡DIFICULTAD DIFICIL DESBLOQUEADA!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=\n");
    usuarioActual->difD = true;
  }
  
}

float calcularPremio(Figura dibujo, float apuesta, int dificultad){
  float multiplicador = 1;
  float difD = 1;
  switch(dibujo){
    case CEREZA:
      multiplicador = 7;
      break;
    case BAR:
      multiplicador = 3;
      break;
    case SIETE:
      multiplicador = 2;
      break;
    case CAMPANA:
      multiplicador = 1.4;
      break;
    case DIAMANTE:
      multiplicador = 1.2;
      break;
  }
  switch(dificultad){
    case 1:
      difD = 1.2;
      break;
    case 2:
      difD = 1.5;
      break;
    case 3:
      difD = 1.8;
      break;
  }
  float premio = apuesta * multiplicador * difD;
  return premio;
}  

void mostrarResultado(tipoUsuario* usuarioActual, tipoResult resultados[][3]){
  int modo = usuarioActual->modo;
  char texto[30];  
  switch(modo){
    case 1:
      printf("| =================== | =================== | =================== |\n");
      for(int i = 0; i < 3; i++){
        for(int linea = 1; linea < 11; linea++){
          printf("| ");
          printFigura(resultados[i][0].dibujo, linea);
          printf(" | ");
          printFigura(resultados[i][1].dibujo, linea);
          printf(" | ");
          printFigura(resultados[i][2].dibujo, linea);
          printf(" |\n");
        }
        printf("| =================== | =================== | =================== |\n");
      }
      break;
    case 2:
      for(int i = 0; i < 3; i++){
        printf("| ======== | ======== | ======== |\n");
        for(int j = 0; j < 3; j++){
          printf("| ");
          switch(resultados[i][j].dibujo){
            case CEREZA:
              strcpy(texto,"CEREZA");
              break;
            case BAR:
              strcpy(texto,"BAR");
              break;
            case SIETE:
              strcpy(texto,"SIETE");
              break;
            case DIAMANTE:
              strcpy(texto,"DIAMANTE");
              break;
            case CAMPANA:
              strcpy(texto,"CAMPANA");
              break;
          }
          printf("%8s ",texto);
        }
        printf("|\n| ======== | ======== | ======== |\n");
      }
      break;
    case 3:
      printf("| ======== | ======== | ======== |\n");
      for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < 3; j++){
          printf(" %8i |",resultados[i][j].valor);
        }
        printf("\n| ======== | ======== | ======== |\n");
      }
      break;
  }
}

void menuJuego(tipoUsuario* usuarioActual){
  if(usuarioActual==NULL){
    printf("No hay ningún usuario ingresado.\n");
    return;
  }
  if(usuarioActual->dinero < 100){
    printf("No tienes dinero suficiente para jugar.\n");
    return;
  }
  int titulo = 0, opcion;
  if (titulo == 0) {
      printf("==============================================================\n");
      printf(" ====================== JACKPOT CHERRY ====================== \n");
      titulo++;
    }
    printf("==============================================================\n");
    printf(" Usuario Conectado : ");
    printf("%s\n",usuarioActual->user);
    printf(" Balance : ¥ ");
    printf("%.2f\n",usuarioActual->dinero);
    printf(" Dificultad Seleccionada : ");
    switch(usuarioActual->dificultad){
      case 1:
        printf("Fácil\n");
        break;
      case 2:
        printf("Medio\n");
        break;
      case 3:
        printf("Difícil\n");
        break;
    }
    printf(" Modo : %i\n",usuarioActual->modo);
    printf("==============================================================\n");
    printf("Escoja una opción: \n");
    printf("1. Jugar\n");
    printf("2. Elegir dificultad\n");
    printf("3. Extras\n");
    printf("4. Volver\n");
    printf("==============================================================\n");
    printf("Ingresa una opción: ");

    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 7) {
      scanf("%d", &opcion);
    }
    getchar();
    //Ahora según opción haremos las opciones del menú
    switch (opcion) {
      case 1:
        jackpotCherry(usuarioActual);
        break;
      case 2:
        elegirDificultad(usuarioActual);
        break;
      case 3:
        extras(usuarioActual);
        break;
      case 4:
        printf("Volviendo al menú principal...\n");
        return;
        break;
    }
}
