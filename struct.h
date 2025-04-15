#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#define MAX 100

// Biblioteca dedicada para a criacao dos Structs, evitando possiveis erros mais
// pra frente :)

// Struct base para o jogador

typedef struct {
  char nome[30];
  int vidaMax;
  int vidaAtual;
  int energiaMax;
  int energiaAtual;
  int ataque;
  int defesa;
} jogador;

// Struct base para preencher os atributos do monstros

typedef struct {
  char nome[30];
  int vidaMax;
  int vidaAtual;
  int ataque;
  int defesa;
  char descricao[1000];
} monstro;

// Struct padrao de carta para ser usado como referencia, tanto pro jogador
// quanto para o monstro

// DETALHE IMPORTANTE: As acoes dos Monstros tambem sao cartas
typedef struct {
  char nome[60];
  char tipo;
  int valor;
  int custo;
  char descricao[1000];
  int ID;
} carta;

#endif
