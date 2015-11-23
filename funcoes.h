#ifndef FUNCOES
#define FUNCOES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>

void pontos();
void conteudo();
void turismo();
void teatro();

#include "main_conteudo.c"
#include "main_pontos.c"
#include "main_teatro.c"
#include "main_turismo.c"
#include "CrudTeatro.h"
#include "CrudTeatro.c"
#include "CrudTurismo.h"
#include "CrudTurismo.c"
#include "CrudPontosTuristicos.h"
#include "CrudPontosTuristicos.c"
#include "CrudConteudo.h"
#include "CrudConteudo.c"

int numeroInvalido(char* numero);
int stringEmBranco(char* informacao);



#endif
