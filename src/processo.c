#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/processo.h"
#include "../includes/quadro.h"
#include "../includes/memoria.h"

Processo* cria_processo(int id_processo, int tamanho_memoria_fisica, int tamanho_memoria_logica, int tamanho_pagina) {
    int tamanho_processo;
    tamanho_processo = rand() % (tamanho_memoria_logica + 1);

    Processo *processo = (Processo*)malloc(sizeof(Processo));
    if (processo == NULL) {
        printf("Erro: Falha ao alocar memória para o processo.\n");
        exit(EXIT_FAILURE);
    }
    
    processo->id = id_processo;
    processo->tamanho = tamanho_processo;
    processo->numero_paginas = (tamanho_processo + tamanho_pagina - 1) / tamanho_pagina;

    int quadros_necessarios = processo->numero_paginas;
    int quadros_disponiveis = 0;
    Quadro *curr = quadros_livres;
    while (curr != NULL) {
        quadros_disponiveis++;
        curr = curr->next;
    }

    if (quadros_disponiveis < quadros_necessarios) {
        printf("Erro: Memória física insuficiente para alocar o processo.\n");
        free(processo);
        return NULL;
    }

    processo->tabela_paginas = (Pagina**)malloc(processo->numero_paginas * sizeof(Pagina*));
    if (processo->tabela_paginas == NULL) {
        printf("Erro: Falha ao alocar tabela de páginas para o processo.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < processo->numero_paginas; i++) {
        processo->tabela_paginas[i] = (Pagina*)malloc(sizeof(Pagina));
        if (processo->tabela_paginas[i] == NULL) {
            printf("Erro: Falha ao alocar memória para a página.\n");
            exit(EXIT_FAILURE);
        }
        processo->tabela_paginas[i]->id = i;
        int tamanho_restante = tamanho_processo - i * tamanho_pagina;
        processo->tabela_paginas[i]->memoria_usada = tamanho_restante < tamanho_pagina ? tamanho_restante : tamanho_pagina;
        processo->tabela_paginas[i]->memoria = (int*)malloc(tamanho_pagina * sizeof(int));
        if (processo->tabela_paginas[i]->memoria == NULL) {
            printf("Erro: Falha ao alocar memória para a página.\n");
            exit(EXIT_FAILURE);
        }
        
        for (size_t j = 0; j < tamanho_pagina / sizeof(int); j++) {
            processo->tabela_paginas[i]->memoria[j] = rand();
        }
        
        int numero_quadro_aleatorio = rand() % quadros_disponiveis-1;
        Quadro *curr = quadros_livres;
        for (int i = 0; i < numero_quadro_aleatorio; i++) {
            curr = curr->next;
        }
        processo->tabela_paginas[i]->numero_quadro = curr->numero;
        uso_quadro[curr->numero] += processo->tabela_paginas[i]->memoria_usada;
        remover_quadro_livre(curr->numero);
    }

    return processo;
}

void visualizar_tabela_paginas(Processo *processo) {
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-= Processo %d =-=-=-=-=-=-=-=-=-=-=-=\n", processo->id);
    printf("Tamanho do processo: %d bytes\n", processo->tamanho);
    printf("Número de páginas: %d\n", processo->numero_paginas);
    printf("\nMapeamento entre páginas e quadros:\n");
    for (int i = 0; i < processo->numero_paginas; i++) {
        printf("Página %d -> Quadro %d (Memória usada: %d bytes)\n", i, processo->tabela_paginas[i]->numero_quadro, processo->tabela_paginas[i]->memoria_usada);
    }
}
