#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include "listase.h"

void imprimir_mapa (int fase){
	if (fase==1){
		printf(" Fase 1                                                \n\n");
		printf("                      -------                          \n");
		printf("                     |       |                       \n");
		printf("                     |   B   |                     \n");
		printf("                     |       |                      \n");
		printf("                      -------             \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---              \n");
		printf("                 | D |       | C |                 \n");
		printf("                  ---         ---           \n");
		printf("                       \\   /                       \n");
		printf("                        ---               \n");
		printf("                       | C |                 \n");
		printf("                        ---                          \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---           \n");
		printf("                 | D |       | C |                     \n");
		printf("                  ---         ---                   \n");
		printf("                       \\   /                      \n");
		printf("                        ---                      \n");
		printf("                    -->| C |                      \n");
		printf("                        ---                    \n\n");
	}
	if (fase==2){
		printf(" Fase 2                                               \n\n");
		printf("                      -------                          \n");
		printf("                     |       |                       \n");
		printf("                     |   B   |                     \n");
		printf("                     |       |                      \n");
		printf("                      -------             \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---              \n");
		printf("                 | D |       | C |                 \n");
		printf("                  ---         ---           \n");
		printf("                       \\   /                       \n");
		printf("                        ---               \n");
		printf("                       | C |                 \n");
		printf("                        ---                          \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---           \n");
		printf("                 | D |    -->| C |                     \n");
		printf("                  ---         ---                   \n");
		printf("                       \\   /                      \n");
		printf("                        ---                      \n");
		printf("                       | C |                      \n");
		printf("                        ---                    \n\n");		
	}
	if (fase==3){
		printf(" Fase 3                                              \n\n");
		printf("                      -------                          \n");
		printf("                     |       |                       \n");
		printf("                     |   B   |                     \n");
		printf("                     |       |                      \n");
		printf("                      -------             \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---              \n");
		printf("                 | D |       | C |                 \n");
		printf("                  ---         ---           \n");
		printf("                       \\   /                       \n");
		printf("                        ---               \n");
		printf("                    -->| C |                 \n");
		printf("                        ---                          \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---           \n");
		printf("                 | D |       | C |                     \n");
		printf("                  ---         ---                   \n");
		printf("                       \\   /                      \n");
		printf("                        ---                      \n");
		printf("                       | C |                      \n");
		printf("                        ---                    \n\n");
	}
	if (fase==4){
		printf(" Fase 4                                            \n\n");
		printf("                      -------                          \n");
		printf("                     |       |                       \n");
		printf("                     |   B   |                     \n");
		printf("                     |       |                      \n");
		printf("                      -------             \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---              \n");
		printf("                 | D |    -->| C |                 \n");
		printf("                  ---         ---           \n");
		printf("                       \\   /                       \n");
		printf("                        ---               \n");
		printf("                       | C |                 \n");
		printf("                        ---                          \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---           \n");
		printf("                 | D |       | C |                     \n");
		printf("                  ---         ---                   \n");
		printf("                       \\   /                      \n");
		printf("                        ---                      \n");
		printf("                       | C |                      \n");
		printf("                        ---                    \n\n");
	}
	if (fase==5){
		printf(" \\BOSS FINAL/                                            \n\n");
		printf("                      -------                          \n");
		printf("                     |       |                       \n");
		printf("                  -->|   B   |                     \n");
		printf("                     |       |                      \n");
		printf("                      -------             \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---              \n");
		printf("                 | D |       | C |                 \n");
		printf("                  ---         ---           \n");
		printf("                       \\   /                       \n");
		printf("                        ---               \n");
		printf("                       | C |                 \n");
		printf("                        ---                          \n");
		printf("                       /   \\                       \n");
		printf("                  ---         ---           \n");
		printf("                 | D |       | C |                     \n");
		printf("                  ---         ---                   \n");
		printf("                       \\   /                      \n");
		printf("                        ---                      \n");
		printf("                       | C |                      \n");
		printf("                        ---                    \n\n");
	}
}

void imprimir_mapaD1 (){
	printf(" Descanso                                                \n\n");
	printf("                      -------                          \n");
	printf("                     |       |                       \n");
	printf("                     |   B   |                     \n");
	printf("                     |       |                      \n");
	printf("                      -------             \n");
	printf("                       /   \\                       \n");
	printf("                  ---         ---              \n");
	printf("                 | D |       | C |                 \n");
	printf("                  ---         ---           \n");
	printf("                       \\   /                       \n");
	printf("                        ---               \n");
	printf("                       | C |                 \n");
	printf("                        ---                          \n");
	printf("                       /   \\                       \n");
	printf("                  ---         ---           \n");
	printf("              -->| D |       | C |                     \n");
	printf("                  ---         ---                   \n");
	printf("                       \\   /                      \n");
	printf("                        ---                      \n");
	printf("                       | C |                      \n");
	printf("                        ---                    \n\n");
}

void imprimir_mapaD2 (){
	printf(" Descanso                                                \n\n");
	printf("                      -------                          \n");
	printf("                     |       |                       \n");
	printf("                     |   B   |                     \n");
	printf("                     |       |                      \n");
	printf("                      -------             \n");
	printf("                       /   \\                       \n");
	printf("                  ---         ---              \n");
	printf("              -->| D |       | C |                 \n");
	printf("                  ---         ---           \n");
	printf("                       \\   /                       \n");
	printf("                        ---               \n");
	printf("                       | C |                 \n");
	printf("                        ---                          \n");
	printf("                       /   \\                       \n");
	printf("                  ---         ---           \n");
	printf("                 | D |       | C |                     \n");
	printf("                  ---         ---                   \n");
	printf("                       \\   /                      \n");
	printf("                        ---                      \n");
	printf("                       | C |                      \n");
	printf("                        ---                    \n\n");
}


void criar_desvio (tp_listase **mapa, int n){ // n indica em qual no o desvio e criado
	tp_listase *descanso, *atu;
	descanso = aloca_listase ();
	atu=*mapa;
	while (atu->info != n){
		atu = atu->prox;
	}
	atu->desvio=descanso;
	descanso->info = 6;
	descanso->prox = atu->prox->prox;
}


void criar_mapa (tp_listase **mapa){ // Essa funcao e responsavel preencher o mapa
	// Usamos numeros para nos referir a fase que o jogador se encontra
	insere_listase_no_fim (mapa, 0); // Fase "0" eh o MENU
	insere_listase_no_fim (mapa, 1);
	insere_listase_no_fim (mapa, 2);
	insere_listase_no_fim (mapa, 3);
	insere_listase_no_fim (mapa, 4);
	insere_listase_no_fim (mapa, 5); // Fase 5 eh o BOSS
	insere_listase_no_fim (mapa, 10); // FINAL DO JOGO
	criar_desvio (mapa, 1);
	criar_desvio (mapa, 3);
}

int avanca_fase (tp_listase **mapa, int num, FILE *f){
	// Recebe uma lista como um mapa, e um numero que eh equivalente a fase atual
	tp_listase *atu;
	atu=*mapa;
	while(atu->info!=num){
		atu=atu->prox;
	}
	fprintf(f, "\nFase - %d", num);
	fclose(f);
	// avanca a fase
	
	return atu->prox->info; // Retorna o numero da nova Fase que o Jogador esta
}

void desvio1 (tp_listase **mapa){
	tp_listase *atu;
	atu=*mapa;
	atu=atu->desvio;
	printf ("%d", atu->info);
}

void desvio2 (tp_listase **mapa){
	tp_listase *atu;
	atu=*mapa;
	while(atu->info!=3){
		atu=atu->prox;
	}
	atu=atu->desvio;
	printf ("%d", atu->info);
}


#endif
