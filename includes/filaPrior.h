#ifndef FILAPRIOR_H
#define FILAPRIOR_H

#include <stdio.h>
#include "fila.h"

typedef struct filaPrior  {
	TFila f1, f2, f3;
} TFilaPrior;

void createListaPrior(TFilaPrior *fp);
void incluiListaPrior(TFilaPrior *fp, char elemento, int nivelPrioridade);
char retiraListaPrior(TFilaPrior *fp);

#endif