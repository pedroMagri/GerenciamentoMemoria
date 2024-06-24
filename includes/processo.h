#ifndef PROCESSO_H
#define PROCESSO_H

#include "pagina.h"

typedef struct {
    int id; 
    int tamanho; 
    int numero_paginas; 
    Pagina **tabela_paginas; 
} Processo;

Processo* cria_processo(int id_processo, int tamanho_memoria_fisica, int tamanho_memoria_logica, int tamanho_pagina);
void visualizar_tabela_paginas(Processo *process);

#endif
