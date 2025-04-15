#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "struct.h"
#define MAXfila 6

/* Existem duas bibliotecas de fila e pilha, pois durante a divisao de tarefas e funcoes, o grupo fez diferentes alteracoes
nas suas bibliotecas, por isso, decidimos manter ambas versoes

fila.h e pilha.h foram usadas por Gabriel Lopo e Pedro Oliveira para fazer o deck do jogador
filamonstro.h e pilhamonstro.h foram usadas por Milton Kiefer, Joao Vitor e Pedro Henrique para fazer o deck dos monstros */

// Nessa biblioteca, o item se chama "tp_carta" ao inves de "tp_item"
typedef carta tp_carta;



typedef struct{
  tp_carta item[MAXfila];
  int ini , fim;
  int tam;
} tp_fila2; // Mudamos o nome do Struct de "tp_fila" para "tp_fila2" para evitarmos colisoes entre os codigos


void inicializa_fila(tp_fila2 *f){
  f->ini = f->fim = MAXfila-1;
  f->tam = 0;
}

int fila_vazia(tp_fila2 *f){
  if(f->ini == f->fim) return 1;
  return 0;
}

int proximo_fila (int pos){
  if (pos == MAXfila-1) return 0;
  return ++pos;
}

int fila_cheia (tp_fila2 *f){
  if(proximo_fila(f->fim)==f->ini)
    return 1;
  return 0;
}

int insere_fila (tp_fila2 *f , tp_carta e){
  if(fila_cheia(f))
    return 0; //Não foi possível adicionar na fila
  f->fim = proximo_fila(f->fim);
  f->item[f->fim]=e;
  f->tam++;
  return 1;
}

int remove_fila(tp_fila2 *f , tp_carta *e){
  if (fila_vazia(f))
    return 0; //Não foi possível remover a fila
  f->ini = proximo_fila(f->ini);
  *e = f->item[f->ini];
  f->tam--;
  return 1;
}

void imprime_fila (tp_fila2 f){
  tp_carta e;
  while(!fila_vazia(&f)){
    remove_fila(&f , &e);
    printf("\n%c" , e.tipo);
  }
}

//duas maneiras de inserir o tamanho da fila
int tamanho_fila(tp_fila2 *f){
  if (fila_vazia(f))return 0;
  if (f->ini < f->fim)return f->fim - f->ini;
  return MAXfila - 1 - f->ini + f->fim +1;
}

int tamanho_fila1(tp_fila2 f){
  int cont = 0;
  tp_carta e;
  while(!fila_vazia(&f)){
    remove_fila(&f , &e);
    cont++;
  }
  return cont;
}

/*
int tamanho_fila2(tp_fila *f){
  return f->tam;
}*/


#endif //FILA_H
