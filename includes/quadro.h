#ifndef QUADRO_H
#define QUADRO_H

typedef struct Quadro {
    int numero; 
    int espaco_usado;
    struct Quadro *next; 
} Quadro;

void alocar_quadros(int tamanho_memoria_fisica, int tamanho_pagina);
void remover_quadro_livre(int numero_quadro);
extern Quadro *quadros_livres;

#endif
