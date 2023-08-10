#include <stdio.h>
#include <stdlib.h>
#include "includes/fila.h"
#include "includes/filaPrior.h"

int main(void) {
    TFilaPrior fp;
    createListaPrior(&fp);
    int quantidadePacientes, estadoPaciente;
    char inicialPaciente;

    printf("Insira o até 15 pacientes a serem atendidos: ");
    scanf("%d", &quantidadePacientes);
    getchar();

    for (int i = 0; i < quantidadePacientes; i++) {
        printf("\nInsira a letra inicial do nome do paciente: ");
        scanf(" %c", &inicialPaciente);
        getchar();
        
		printf("ESTADO DE SAUDE\n1 - Leve\n2 - Grave\n3 - CRITICO\nInsira o estado de saude do paciente: ");
        scanf("%d", &estadoPaciente);
        getchar();

        if ((estadoPaciente > 3) || (estadoPaciente < 1)) {
            i--;
            printf("Erro de Entrada - Operacao anterior cancelada\nNova Operacao:\n");
        }
        else
            incluiListaPrior(&fp, inicialPaciente, estadoPaciente);
    }

    char paciente;
    printf("\nORDEM DE ATENDIMENTO\n");
    for (int ordemAtendimento = 0; ordemAtendimento < quantidadePacientes; ordemAtendimento++) {
        paciente = retiraListaPrior(&fp);
        printf("%d - %c \n", ordemAtendimento + 1, paciente);
        fflush(stdout);
    }

    printf("Pressione qualquer tecla para sair...");
    getchar();
    return 0;
}