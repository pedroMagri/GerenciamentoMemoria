#include <stdio.h>
#include <stdlib.h>
#include "../includes/quadro.h"

Quadro *quadros_livres = NULL;

void alocar_quadros(int tamanho_memoria_fisica, int tamanho_pagina) {
    for (int i = tamanho_memoria_fisica / tamanho_pagina - 1; i >= 0; i--) {
        Quadro *novo_quadro = (Quadro*)malloc(sizeof(Quadro));
        if (novo_quadro == NULL) {
            printf("Falha ao alocar memória para o quadro!\n");
            exit(EXIT_FAILURE);
        }
        novo_quadro->numero = i;
        novo_quadro->espaco_usado = 0;
        novo_quadro->next = quadros_livres;
        quadros_livres = novo_quadro;
    }
}

void remover_quadro_livre(int numero_quadro) {
    Quadro *curr = quadros_livres;
    Quadro *prev = NULL;

    while (curr != NULL) {
        if (curr->numero == numero_quadro) {
            if (prev == NULL) {
                quadros_livres = curr->next;
            } else {
                prev->next = curr->next;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

