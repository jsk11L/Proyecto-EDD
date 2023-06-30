#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>

tipoUsuario* crearUsuario(char user[], char pass[]) {
  tipoUsuario * new = (tipoUsuario *)malloc(sizeof(tipoUsuario));
  assert(new != NULL);
  strcpy(new->user,strdup(user));
  strcpy(new->pass,strdup(pass));
  new->dinero = 0;
  return new;
}