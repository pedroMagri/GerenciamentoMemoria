#ifndef MEMORIA_H
#define MEMORIA_H

#include "processo.h"

#define TAMANHO_MEMORIA_FISICA 65536
#define TAMANHO_MEMORIA_LOGICA 32768
#define TAMANHO_PAGINA 4096

extern int uso_quadro[TAMANHO_MEMORIA_FISICA / TAMANHO_PAGINA];

void alocar_quadros(int tamanho_memoria_fisica, int tamanho_pagina);
void visualizar_memoria_fisica(Processo **processes, int num_processes);

#endif
