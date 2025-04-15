#ifndef FILAMONSTRO_H
#define FILAMONSTRO_H

#include <stdio.h>
#include <windows.h>
#include "struct.h"
#define MAX 100

/* FILA!
Fila segue a regra FIFO
First In First Out*/

/* Existem duas bibliotecas de fila, pois durante a divisao de tarefas e funcoes, o grupo fez diferentes alteracoes
nas suas bibliotecas, por isso, decidimos manter ambas versoes
fila.h e pilha.h foram usadas por Gabriel Lopo e Pedro Oliveira para fazer o deck do jogador

filamonstro.h e pilhamonstro.h foram usadas por Milton Kiefer, Joao Vitor e Pedro Henrique para fazer o deck dos monstros */

typedef struct{
	carta item[MAX]; // Agora o item eh do tipo carta
	int ini, fim;
// int man;
} tp_fila;

void jesus_cristo (){ // Amem senhor
	printf ("Pai nosso\nque estais no ceu, \n");
	printf ("santificado seja vosso nome, \n");
	printf ("venha nos a vosso reino, \n");
	printf("seja feita vossa vontade, \n");
	printf("Assim na terra como no ceu;");
	printf("\n\n");
	
	Sleep (3000);
	
	printf ("O pao nosso de cada dia nos dai hoje, \n");
	printf ("perdoai-nos as nossas ofensas \n");
	printf ("Assim como nos perdoamos \n");
	printf ("a quem nos tem ofendido, \n");
	printf ("e nao nos deixeis cair em tentaçao, \n");
	printf ("mas livrai-nos do Mal.\n");
	printf ("Amem");
	Sleep (3000);
	system ("cls");
}

void inicializa_fila (tp_fila *f){
	f->ini = f->fim = MAX - 1;
}

int fila_vazia (tp_fila *f){
	if (f->fim == f->ini) return 1;
	return 0;
}

int proximo (int pos){
	if (pos == MAX - 1) return 0;
	return ++pos; // Nesse caso ++pos incrementa primeiro e depois retorna
} // ++pos =! pos++

int fila_cheia (tp_fila *f){
	if (proximo (f->fim) == f->ini)
		return 1;
	return 0;
}

int insere_fila (tp_fila *f, carta e){
	if (fila_cheia (f))
		return 0; //Nao foi possivel adicionar a fila
	f->fim = proximo (f->fim);
	f->item [f->fim] = e;
	return 1;
}

int remove_fila (tp_fila *f, carta *e){
	if (fila_vazia(f))
		return 0; //Não foi possivel remover da fila
	f->ini = proximo (f->ini);
	*e = f->item [f->ini];
	return 1;
}

void imprime_fila (tp_fila f){
	carta e;
	while (!fila_vazia (&f)){ //enquanto a fila NAO estiver vazia
		remove_fila (&f, &e);
		printf ("%d ", e);
	}
}

int tamanho_fila (tp_fila *f){
	if (fila_vazia(f)) return 0;
	if (f->ini < f->fim) return f->fim - f->ini;
	return MAX - 1 - f->ini + f->fim + 1;
}

int tamanho_fila1 (tp_fila f){
	int cont = 0;
	carta e;
	while (!fila_vazia(&f)){
		remove_fila(&f,&e);
		cont++;
	}
	return cont;
}

#endif
