#include <stdio.h>
#include <stdlib.h>
#include "../includes/memoria.h"
#include "../includes/quadro.h"

int uso_quadro[TAMANHO_MEMORIA_FISICA / TAMANHO_PAGINA] = {0};

void visualizar_memoria_fisica() {
    int total_frames = TAMANHO_MEMORIA_FISICA / TAMANHO_PAGINA;
    int memoria_usada = 0;
    
    for (int i = 0; i < total_frames; i++) {
        memoria_usada += uso_quadro[i];
    }

    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-= Memória física =-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Memória usada | %d bytes (%.2f%%)\n", memoria_usada, (float)memoria_usada / TAMANHO_MEMORIA_FISICA * 100);
    printf("Memória livre | %d bytes (%.2f%%)\n\n", TAMANHO_MEMORIA_FISICA - memoria_usada, (float)(TAMANHO_MEMORIA_FISICA - memoria_usada) / TAMANHO_MEMORIA_FISICA * 100);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Quadros =-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < total_frames; i++) {
        if (uso_quadro[i] > 0) {
            printf("Quadro %d | Ocupado | %d/%d bytes\n", i, uso_quadro[i], TAMANHO_PAGINA);
        } else {
            printf("Quadro %d | Livre   | %d/%d bytes\n", i, uso_quadro[i], TAMANHO_PAGINA);
        }
    }
}
