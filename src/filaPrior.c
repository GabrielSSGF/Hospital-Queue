#include "../includes/filaPrior.h"
#include <stdlib.h>

void createListaPrior(TFilaPrior *fp) {
	create(&fp->f1);
	create(&fp->f2);
	create(&fp->f3);

}

void incluiListaPrior(TFilaPrior *fp, char elemento, int nivelPrioridade) {
	int alto = 3, medio = 2, baixo = 1;

	if (nivelPrioridade == alto)
		store(&fp->f3, elemento);
	else if (nivelPrioridade == medio)
		store(&fp->f2, elemento);
	else if (nivelPrioridade == baixo)
		store(&fp->f1, elemento);

}

char retiraListaPrior(TFilaPrior *fp) {
	if (!(isempty(&fp->f3)))
		return retira(&fp->f3);
	else if (!isempty(&fp->f2))
		return retira(&fp->f2);
	else if (!isempty(&fp->f1))
		return retira(&fp->f1);
}