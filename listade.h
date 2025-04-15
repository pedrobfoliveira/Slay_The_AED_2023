#ifndef LISTADE_H
#define LISTADE_H


#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "struct.h"

// Usada para alocar dinamicamente a mao do jogador

typedef struct tp_no_aux_lista{
    struct tp_no_aux_lista *ant;
    carta info;
    struct tp_no_aux_lista *prox;
}tp_no_lista;


typedef struct{
    tp_no_lista *ini;
    tp_no_lista *fim;
    int tamanho;
}tp_listaD;


tp_listaD *inicializa_listaD(){
    tp_listaD *lista = (tp_listaD*) malloc (sizeof(tp_listaD));
    lista -> ini = NULL;
    lista -> fim = NULL;
    lista -> tamanho = 0;
    return lista;
}

int listad_vazia(tp_listaD *lista){
    if(lista -> ini == NULL){
        return 1;
    }
    return 0;
}

tp_no_lista *aloca_lista(){
    tp_no_lista *pt;
    pt = (tp_no_lista*) malloc (sizeof(tp_no_lista));
    return pt;
}

int tamanho_listaD (tp_listaD *lista){
	int cont = 0;
	tp_listaD *atu;
	atu = lista;
	while (atu != NULL){
		cont++;
		atu->fim = atu->fim->prox;
	}
	return cont;
}

int insere_listaD_no_fim (tp_listaD *lista, carta e){
    tp_no_lista *novo;
    novo = aloca_lista();
    if(!novo) return 0;
    novo -> info = e;
    if(listad_vazia(lista)){
        novo -> prox = NULL;
        novo -> ant = NULL;
        lista -> ini = lista -> fim = novo;
    }else{
        novo -> prox = NULL;
        novo -> ant = lista -> fim;
        lista -> fim -> prox = novo;
        lista -> fim = novo;

    }
    lista->tamanho++;
    return 1;
}

int remove_listad (tp_listaD *lista, carta e) {
    tp_no_lista *atu;
    atu = lista->ini;

    if (atu == NULL) return 0;

    if (lista->ini == lista->fim) {
        lista->ini = lista->fim = NULL;
    } 
    else {
        if (lista->ini == atu) {
            lista->ini = atu->prox;
            atu->prox->ant = NULL;
        } else if (lista->fim == atu) {
            lista->fim = atu->ant;
            atu->ant->prox = NULL;
        } else {
            atu->prox->ant = atu->ant;
            atu->ant->prox = atu->prox;
        }
    }
    free(atu);
    lista->tamanho--;
    return 1;
}


tp_no_lista *busca_listaDe(tp_listaD *lista, carta e){
    tp_no_lista *atu;
    atu = lista -> ini;
    while ((atu != NULL) && (atu -> info.nome != e.nome)){
        atu = atu -> prox;
    }
    return atu;

}


void imprime_listaD(tp_listaD *lista) { 
// Como a biblioteca de listaDE vai ser usada para a mao do jogador, fizemos com que a funcao "imprime_listaD" imprime-se a mao do jogador
    tp_no_lista *atu;
    atu = lista->ini;
    while (atu!=NULL) {
    	Sleep (300);
    	printf ("(ID: %d)", atu->info.ID);
    	printf ("\n ----------------------------------------------------------------------------\n");
        printf ("| Nome: %s\n", atu->info.nome);
		printf ("| Tipo: %c\n", atu->info.tipo);
		printf ("| Valor: %d\n", atu->info.valor);
		printf ("| Custo: %d\n", atu->info.custo);
		printf ("| Descricao: %s\n", atu->info.descricao);
    	printf (" ----------------------------------------------------------------------------\n\n");
        atu = atu->prox;
    }
}


#endif
