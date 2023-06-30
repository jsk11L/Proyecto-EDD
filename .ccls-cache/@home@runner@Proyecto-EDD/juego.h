 #ifndef JUEGO_H
#define JUEGO_H
#include "Map.h"
#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct tipoUsuario tipoUsuario;

struct tipoUsuario{
  char user[30];
  char pass[30];
  float dinero;
  List* historial;
  float gananciasTotales;
  int dificultad;
  int modo;
  bool difM;
  bool difD;
  int bonus;
};

typedef enum Accion {
  AGREGAR_DINERO,
  RETIRAR_DINERO,
  APUESTA,
  GANANCIA
} Accion;

typedef enum Figura{
  BAR,
  CEREZA,
  SIETE,
  DIAMANTE,
  CAMPANA
} Figura;

typedef struct tipoHisto {
  Accion accion;
  float cantidad;
} tipoHisto;

typedef struct tipoResult {
  int valor;
  Figura dibujo;
} tipoResult;

void leerCadena(char cadena[31]);

int is_equal_string(void *key1, void *key2);

tipoUsuario* crearUsuario(char user[], char pass[]);

bool verificarContrasena(tipoUsuario* aux, char contrasena[]);

tipoUsuario* registrarUsuario(Map* usuarios);

tipoUsuario* cambiarUsuario(Map* usuarios, tipoUsuario* usuarioActual);

tipoUsuario* manejarUsuarios(Map* usuarios, tipoUsuario* usuarioActual);

void agregarDinero(tipoUsuario* usuarioActual);

void retirarDinero(tipoUsuario* usuarioActual);

void verHistorial(tipoUsuario* usuarioActual);

void menuBalance(tipoUsuario* usuarioActual);

void menuJuego(tipoUsuario* usuarioActual);

void jackpotCherry(tipoUsuario* usuarioActual);

void mostrarResultado(tipoUsuario* usuarioActual, tipoResult resultados[][3]);

void calcularResultado(tipoResult resultados[][3], float apuesta, tipoUsuario* usuarioActual);

float leerApuesta(tipoUsuario* usuarioActual, float lim1, float lim2);

void elegirDificultad(tipoUsuario* usuarioActual);

void extras(tipoUsuario* usuarioActual);

float calcularPremio(Figura dibujo, float apuesta, int dificultad);

void verificarDificultades(tipoUsuario* usuarioActual);

#endif /* JUEGO_H */