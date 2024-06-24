#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/processo.h"
#include "../includes/memoria.h"

Processo *processos[10];
int num_processos = 0;

int main() {
    srand(time(NULL));

    alocar_quadros(TAMANHO_MEMORIA_FISICA, TAMANHO_PAGINA);

    int option;

    while (true) {
        printf("\nEscolha uma opção:\n");
        printf("1. Visualizar memória\n");
        printf("2. Criar processo\n");
        printf("3. Visualizar tabela de páginas de um processo\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                visualizar_memoria_fisica();
                break;
            case 2: {
                int id_processo;
                bool duplicado;
                printf("Informe o número do processo: ");
                scanf("%d", &id_processo);
                for (int i = 0; i < num_processos; i++) {
                    if (processos[i]->id == id_processo) {
                        printf("Já existe um processo com o ID %d. Escolha outro ID.\n", id_processo);
                        duplicado = 1;
                    }
                }
                if (duplicado != 1) {
                    Processo *novo_processo = cria_processo(id_processo, TAMANHO_MEMORIA_FISICA, TAMANHO_MEMORIA_LOGICA, TAMANHO_PAGINA);
                    if (novo_processo != NULL) {
                        processos[num_processos] = novo_processo;
                        num_processos++;
                        printf("Processo %d criado com tamanho de %d bytes.\n", id_processo, novo_processo->tamanho);
                    }
                }
                duplicado = 0;
                break;
            }
            case 3: {
                int id_processo;
                printf("Informe o número do processo: ");
                scanf("%d", &id_processo);
                bool encontrado = false;
                for (int i = 0; i < num_processos; i++) {
                    if (processos[i]->id == id_processo) {
                        visualizar_tabela_paginas(processos[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Erro: Processo não encontrado.\n");
                }
                break;
            }
            case 4:
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
