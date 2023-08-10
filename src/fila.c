#include "../includes/fila.h"
#include <stdlib.h>

int nextItem(int item) {
    if (item < (15 - 1))
        return item + 1;
    else
        return 0;
}

void create(TFila *f) {
	f->rear = f->front = 0;
}

int isfull(TFila *f) {
	if (nextItem(f->rear) == f->front)
		return 1;
	else
		return 0;
}

int isempty(TFila *f) {
	if (f->rear == f->front)
		return 1;
	else
		return 0;
}

void destroy(TFila *f) {
	f->front = f->rear;
}

void store(TFila *f, char x) {
	if (isfull(f)) {
		printf("overflow\n");
		abort();
	}
	
	f->vet[f->rear] = x;
	f->rear = nextItem(f->rear);
}

char retira(TFila *f) {
	char aux;
	
	if (isempty(f)) {
		printf("underflow\n");
		abort();
	}
	
	aux = f->vet[f->front];
	f->front = nextItem(f->front);
	return aux;
}