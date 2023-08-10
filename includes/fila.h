#ifndef FILA_H
#define FILA_H

#include <stdio.h>

typedef struct fila  {
	char vet[15];
	int front, rear;
} TFila;

void create(TFila *f);
int isfull(TFila *f);
int isempty(TFila *f);
void destroy(TFila *f);
void store(TFila *f, char x);
char retira(TFila *f);
int nextItem(int item);

#endif