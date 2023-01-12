#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct fila 
{
	char vet[15];
	int front, rear;
} TFila;

typedef struct filaprior 
{
	TFila f1, f2, f3;
} TFilaPrior;

int next(int n)
{
	if (n < (15 - 1))
		return n + 1;
	else
		return 0;
}

void create(TFila * f)
{
	f->rear = f->front = 0;
}

int isfull(TFila * f)
{
	if (next(f->rear) == f->front)
		return 1;
	else
		return 0;
}

int isempty(TFila * f)
{
	if (f->rear == f->front)
		return 1;
	else
		return 0;
}

void destroy(TFila * f)
{
	f->front = f->rear;
}

void store(TFila * f, char x)
{
	if (isfull(f))
	{
		printf("overflow\n");
		abort();
	}
	
	f->vet[f->rear] = x;
	f->rear = next(f->rear);
}

char retira(TFila * f)
{
	char aux;
	
	if (isempty(f))
	{
		printf("underflow\n");
		abort();
	}
	
	aux = f->vet[f->front];
	f->front = next(f->front);
	return aux;
}

void createprior(TFilaPrior * fp)
{
	create(&fp->f1);
	create(&fp->f2);
	create(&fp->f3);

}

void incluiprior(TFilaPrior * fp, char elem, int prior)
{
	if (prior == 3)
		store(&fp->f3, elem);
	else if (prior == 2)
		store(&fp->f2, elem);
	else if (prior == 1)
		store(&fp->f1, elem);

}

char retiraprior(TFilaPrior * fp)
{
	if (!(isempty(&fp->f3)))
		return retira(&fp->f3);
	else if (!isempty(&fp->f2))
		return retira(&fp->f2);
	else if (!isempty(&fp->f1))
		return retira(&fp->f1);
}

int main(void)
{
	TFilaPrior fp;
	createprior(&fp);
	int numPac, estdPac;
	char pacInic;
	
	printf("Insira o numero de pacientes a serem atendidos: \n");
	scanf("%d", &numPac);
	
	for (int i = 0; i<numPac; i++) {
		printf("\nInsira a letra inicial do nome do paciente: ");
		scanf(" %c]", &pacInic);
		printf("\nESTADO DE SAUDE\n1 - Leve\n2 - Grave\n3 - CRITICO\nInsira a estado de saude do paciente: ");
		scanf("%d", &estdPac);
		if ((estdPac>3) || (estdPac<1)) {
			system("cls"); 
			i--;
			printf("Erro de Entrada - Operacao anterior cancelada\nNova Operacao:\n");
		}
		else incluiprior(&fp, pacInic, estdPac);
	}
	
	char pac;
	printf("\nORDEM DE ATENDIMENTO\n");
	for(int ord = 0; ord<numPac; ord++)
	{
		pac = retiraprior(&fp);
		printf("%d - %c \n", ord+1, pac);
	}
	return 0;
}
