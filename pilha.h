#ifndef PILHA_H
#define PILHA_H
#include "cartas.h"
#include "struct.h"
#include "fila.h"
#include "listade.h"

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX 10

/* PILHAAAAAA!!
Pilha segue a regra FILO
First In Last Out*/

/* Existem duas bibliotecas de fila e pilha, pois durante a divisao de tarefas e funcoes, o grupo fez diferentes alteracoes
nas suas bibliotecas, por isso, decidimos manter ambas versoes

fila.h e pilha.h foram usadas por Gabriel Lopo e Pedro Oliveira para fazer o deck do jogador
filamonstro.h e pilhamonstro.h foram usadas por Milton Kiefer, Joao Vitor e Pedro Henrique para fazer o deck dos monstros */

// Nessa biblioteca, o struct se chama "deck" pois foi usado para a criacao do deck do jogador

typedef struct {
    int topo;
    carta item[MAX];
} deck;

void inicializa_pilha(deck* p) {
    p->topo = -1;
}

int pilha_vazia(deck* p) {
    if (p->topo == -1) return 1;
    return 0;
}

int pilha_cheia(deck* p) {
    if (p->topo == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int push(deck* p, carta e) {
    if (pilha_cheia(p) == 1) return 0;
    p->topo++;
    p->item[p->topo] = e;
    return 1;
}

int pop(deck* p, carta* e) {
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    p->topo--;
    return 1;
}

int top(deck* p, carta* e) {
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    return 1;
}

void imprime_pilha(deck p) {
    carta e;
    printf("\n");
    while (!pilha_vazia(&p)) {
        pop(&p, &e);
        printf("%s\n", e.nome);
    }
}

int altura_pilha(deck* p) {
    return p->topo + 1;
}

void retira_impares(deck* p) {
    deck paux;
    inicializa_pilha(&paux);
    carta e;

    while (!pilha_vazia(p)) {
        pop(p, &e);
        if (e.valor % 2 == 0) { // Se o valor for par
            push(&paux, e); // Pega a carta com valor par e joga na pilha auxiliar
        }
    }
    
    while (!pilha_vazia(&paux)) {
        pop(&paux, &e);
        push(p, e);
    }
}

int compara_pilhas(deck p1, deck p2) {
    carta e1, e2;
    if (altura_pilha(&p1) != altura_pilha(&p2))
        return 0;
    while (!pilha_vazia(&p1)) {
        pop(&p1, &e1);
        pop(&p2, &e2);
        if (e1.valor != e2.valor)
            return 0;
    }
    return 1;
}

int empilha_pilha(deck* p1, deck* p2) {
    deck paux; // pilha auxiliar
    inicializa_pilha(&paux);
    carta e;

    if (altura_pilha(p1) + altura_pilha(p2) > MAX)
        return 0;

    // desempilha p2
    while (!pilha_vazia(p2)) {
        pop(p2, &e);
        push(&paux, e);
    }

    // desempilha pilha auxiliar
    while (!pilha_vazia(&paux)) {
        pop(&paux, &e);
        push(p1, e);
    }
    return 1;
}

// Funcoes do jogo 

carta preencheCarta (int i){ // Atribui os valores das cartas a carta passada como parametro
	carta p;
	jogador j;
	switch (i){
		case 1:
			define_Golpe (&p);
			break;
		
		case 2:
			define_Porrada (&p);
			break;

		case 3:
			define_Corte_Rapido (&p);
			break;
		
		case 4: 
			define_Hemocinesia (&p);
			break;

		case 5:
			define_Ombrada (&p, &j);
			break;

		case 6:
			define_Bloqueio (&p);
			break;

		case 7:
			define_Sobrevivente (&p);	
			break;
			
		case 8:
			define_Segundo_Folego (&p);	
			break;
		
		case 9:
			define_Destruidor (&p);
			break;
				
        case 10: 
            define_Zap (&p);    
            break;
            
        case 11:
        	define_Esquivar_e_Atacar (&p);
        	break;
        	
        case 12:
        	define_Onda_De_Ferro (&p);
        	break;
        	
        case 13:
        	define_Bola_De_Fogo (&p);
        	break;
        	
        case 14:
        	define_Memento (&p);
        	break;
	}
			
    return p;
}


int criaDeck (deck *d, int up){ // Cria um deck para o jogador
	inicializa_pilha (d);
	//while (!pilha_cheia (d)){ // Quando a pilha estiver com 10 cartas, o deck esta pronto
	//	int i = (rand () % 11);  // Escolhe aleatoriamente numeros de (0 a 11) para escolher 10 cartas aleatorias entre 12
	//	i++; // Adiciona 1 em i para evitar que ele passe "0" pra funcao preenche carta;
	//	push (d, preencheCarta (i));
	//}
	if (up == 11){
		for(int i=1; i < 11; i++){
			push(d, preencheCarta (i));
		}
	}
	
	if (up == 12){
		#define MAX 11
		for(int i=1; i < 12; i++){
			push(d, preencheCarta (i));
		}
	}
	if (up == 13){
		#define MAX 12
		for(int i=1; i < 13; i++){
			push(d, preencheCarta (i));
		}
	}
	if (up == 14){
		#define MAX 13
		for(int i=1; i < 14; i++){
			push(d, preencheCarta (i));
		}
	}
	if (up == 15){
		#define MAX 14
		for(int i=1; i < 15; i++){
			push(d, preencheCarta (i));
		}
	}
	if (up == 16){
		#define MAX 15
		for(int i=1; i < 16; i++){
			push(d, preencheCarta (i));
		}
	}
	return 1;
}


int embaralhaDeck (deck *d){ // Embaralha as cartas que foram inseridas no deck criado
	deck aux1, aux2, aux3, aux4;
	carta e;
	inicializa_pilha (&aux1);
	inicializa_pilha (&aux2);
	inicializa_pilha (&aux3);
	inicializa_pilha (&aux4);
	
	srand (time (NULL));

	while(!pilha_vazia(d)){
		pop(d, &e);
		push(&aux1,e);
		if(!pilha_vazia(d)){

		pop(d,&e);
		push(&aux2,e);

		}

		if(!pilha_vazia(d)){
			pop(d,&e);
			push(&aux3, e);
		}
		if(!pilha_vazia(d)){
			pop(d,&e);
			push(&aux4, e);
		}
		}

	while(!pilha_cheia(d)){
		int valor;
		valor = rand() % 100;

		if(valor <= 25){
            if(!pilha_vazia(&aux1)){
			pop(&aux1, &e);
			push(d, e);
            }
		}else if(valor <= 50){
            if(!pilha_vazia(&aux2)){
			pop(&aux2, &e);
			push(d, e);

            }
		}else if(valor <= 75){
            if(!pilha_vazia(&aux3)){
			pop(&aux3, &e);
			push(d,e);

            }
		}else{
            if(!pilha_vazia(&aux4)){
			pop(&aux4, &e);
			push(d,e);


            }
		}
	}
    return 1;
}

// Essa funcao cava Cartas e coloca na mao do jogador que esta Alocada Dinamicamente
int cavaCartas (deck *p, tp_listaD *cartasNaMao){
    if (cartasNaMao->tamanho == 5) return 0; // Mao cheia
    while (cartasNaMao->tamanho < 5 && !pilha_vazia (p)){
        carta e;
        pop(p,&e);
        insere_listaD_no_fim (cartasNaMao, e);
    }
    return 1; // A funcao foi executada. Carta foi cavada
}

void descarteMao(tp_listaD *cartasNaMao, deck *descarte){
	tp_no_lista *atu;
	atu = cartasNaMao->ini;
	while(atu!=NULL){
		carta e;
		remove_listad(cartasNaMao, e);
		push(descarte, e);
		atu = atu->prox;
	}
}

carta descarte_da_mao(tp_listaD *mao, carta e){ // Recebe uma listaDE e uma carta como parametro para fazer o descarte
	remove_listad (mao, e);
	return e;
}




#endif
