#ifndef CARTA_H
#define CARTA_H

#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <cstdlib>


// Biblioteca que armazena as Cartas do Jogador

// A - Ataque; E - Espacial; D - Defesa
// AED

// ATUALMENTE TEM 10 CARTAS

// Cartas de Ataque:

// 1
void define_Golpe (carta *golpe){ // Cada funcao representa uma carta, e quando chamada ela preenche a carta passada como parametro
	strcpy (golpe->nome, "Golpe"); // Nome da Carta
	golpe->tipo = 'A'; // Tipo da Carta (A/ E/ D)
	golpe->valor = 6; // Valor que sera atribuido na carta (Dano, Defesa, etc)
	golpe->custo = 1; // O custo da carta, apenas para o jogador (Carta de monstro nao tem custo)
	strcpy (golpe->descricao, "Marque o rosto dos inimigos com seu proprio punho. Causa 6 de dano.");
	// Descricao: Uma breve descricao fantasiosa que explica o que a carta faz
	golpe->ID = 1; // Atribuimos um ID para cada carta para facilitar sua execucao
}
int executa_Golpe (carta *golpe, jogador *j, monstro *m){ // Essa funcao sera chamada quando a carta Golpe for usada
	define_Golpe (golpe); // Define os valores da carta golpe
	if (j->energiaAtual < golpe->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", golpe->nome);
		j->energiaAtual = j->energiaAtual - golpe->custo; // Tira a Energia necessaria do jogador para executar a carta
		j->ataque = golpe->valor - m->defesa; // Aumenta o ataque do jogador igual ao valor da carta
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque; // Reduz a vida do monstro baseado no ataque
		// IMPORTANTE: Apos o ataque, precisa voltar o ataque do jogador a ZERO para evitar que se acumule
	}
	return 1;
}


// 2
void define_Porrada (carta *porrada){
	strcpy (porrada->nome, "Porrada!");
	porrada->tipo = 'A';
	porrada->valor = 8;
	porrada->custo = 2;
	strcpy (porrada->descricao, "Esmague a cabeca dos seus inimigos com uma porrada! Causa 8 de dano.");
	porrada->ID = 2;	
}
int executa_Porrada (carta *porrada, jogador *j, monstro *m){
	define_Porrada (porrada);
	if (j->energiaAtual < porrada->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", porrada->nome);
		j->energiaAtual = j->energiaAtual - porrada->custo;
		j->ataque = porrada->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// 3
void define_Corte_Rapido (carta *corteRapido){ 
	strcpy (corteRapido->nome, "Corte Rapido");
	corteRapido->tipo = 'A';
	corteRapido->valor = 4;
	corteRapido->custo = 1;
	strcpy (corteRapido->descricao, "Um golpe rapido com sua arma causando 4 de dano.");	
	corteRapido->ID = 3;
}
int executa_Corte_Rapido (carta *corteRapido, jogador *j, monstro *m){
	define_Corte_Rapido (corteRapido);
	if (j->energiaAtual < corteRapido->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", corteRapido->nome);
		j->energiaAtual = j->energiaAtual - corteRapido->custo;
		j->ataque = corteRapido->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// 4
void define_Hemocinesia (carta *hemocinesia){ // Perde 2 de vida, mas causa 15 de dano
	strcpy (hemocinesia->nome, "Hemocinesia");
	hemocinesia->tipo = 'A';
	hemocinesia->valor = 15;
	hemocinesia->custo = 3;
	strcpy (hemocinesia->descricao, "Aposte tudo! Sacrifique 2 pontos de Vida, mas em compensacao, cause 15 de dano!");
	hemocinesia->ID = 4;	
}
int executa_Hemocinesia (carta *hemocinesia, jogador *j, monstro *m){
	define_Hemocinesia (hemocinesia);
	if (j->energiaAtual < hemocinesia->custo || j->vidaAtual <= 2){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", hemocinesia->nome);
		j->energiaAtual = j->energiaAtual - hemocinesia->custo;
		j->ataque = hemocinesia->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		j->vidaAtual = j->vidaAtual - 2;
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// 5
void define_Ombrada (carta *ombrada, jogador *j){ 
	strcpy (ombrada->nome, "Ombrada");
	ombrada->tipo = 'A';
	ombrada->valor = j->defesa;
	ombrada->custo = 1;
	strcpy (ombrada->descricao, "Avance com tudo e derrubar o inimigo, causando dano igual a sua Defesa.");	
	ombrada->ID = 5;
}
int executa_Ombrada (carta *ombrada, jogador *j, monstro *m){
	define_Ombrada (ombrada, j);
	if (j->energiaAtual < ombrada->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", ombrada->nome);
		j->energiaAtual = j->energiaAtual - ombrada->custo;
		j->ataque = ombrada->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// Cartas de Defesa:

// 6
void define_Bloqueio (carta *bloqueio){
	strcpy (bloqueio->nome, "Bloqueio");
	bloqueio->tipo = 'D';
	bloqueio->valor = 4;
	bloqueio->custo = 1;
	strcpy (bloqueio->descricao, "Proteja-se de um golpe eminente aumentando sua Defesa em 4.");
	bloqueio->ID = 6;	
}
int executa_Bloqueio (carta *bloqueio, jogador *j, monstro *m){
	define_Bloqueio (bloqueio);
	if (j->energiaAtual < bloqueio->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", bloqueio->nome);
		j->energiaAtual = j->energiaAtual - bloqueio->custo;
		j->defesa = j->defesa + bloqueio->valor; // DEFESAS SAO ACUMULAVEIS!!
	}
	return 1;
}


// 7
void define_Sobrevivente (carta *sobrevivente){
	strcpy (sobrevivente->nome, "Sobrevivente");
	sobrevivente->tipo = 'D';
	sobrevivente->valor = 7;
	sobrevivente->custo = 2;
	strcpy (sobrevivente->descricao, "Voce eh duro na queda! Quase inquebravel. Sua Defesa aumenta 7.");
	sobrevivente->ID = 7;	
}
int executa_Sobrevivente (carta *sobrevivente, jogador *j, monstro *m){
	define_Sobrevivente (sobrevivente);
	if (j->energiaAtual < sobrevivente->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", sobrevivente->nome);
		j->energiaAtual = j->energiaAtual - sobrevivente->custo;
		j->defesa = j->defesa + sobrevivente->valor; // DEFESAS SAO ACUMULAVEIS!!
	}
	return 1;
}

// Cartas Especiais:

// 8
void define_Destruidor (carta *destruidor){
	strcpy (destruidor->nome, "Destruidor");
	destruidor->tipo = 'E';
	destruidor->valor = 9;
	destruidor->custo = 3;
	strcpy (destruidor->descricao, "Um Golpe ESMAGADOR que reduz a Defesa do inimigo para 0, em seguida causa 9 de dano.");
	destruidor->ID = 8;
}
int executa_Destruidor (carta *destruidor, jogador *j, monstro *m){
	define_Destruidor (destruidor);
	if (j->energiaAtual < destruidor->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", destruidor->nome);
		j->energiaAtual = j->energiaAtual - destruidor->custo;
		m->defesa = 0; // Essa carta reduz a Defesa do Inimigo para ZERO!
		j->ataque = destruidor->valor; // DEFESAS SAO ACUMULAVEIS!!
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// 9
void define_Segundo_Folego (carta *segundoFolego){
	strcpy (segundoFolego->nome, "Segundo Folego");
	segundoFolego->tipo = 'E';
	segundoFolego->valor = 8;
	segundoFolego->custo = 2;
	strcpy (segundoFolego->descricao, "Voce tem muito folego para conseguir lutar por tanto tempo. Recupere 8 de vida.");
	segundoFolego->ID = 9;
}
int executa_Segundo_Folego (carta *segundoFolego, jogador *j, monstro *m){
	define_Segundo_Folego (segundoFolego);
	if (j->energiaAtual < segundoFolego->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", segundoFolego->nome);
		j->energiaAtual = j->energiaAtual - segundoFolego->custo;
		j->vidaAtual = j->vidaAtual + segundoFolego->valor;
		if (j->vidaAtual > j->vidaMax){ // Esse "if" impede que a Vida Atual seja maior que a Vida Maxima
			j->vidaAtual = j->vidaMax;
		}
	}
	return 1;
}


// 10
void define_Zap (carta *zap){ // Essa carta tem 25% de chance de causar o dobro de dano
	strcpy (zap->nome, "Zap!");
	zap->tipo = 'E';
	zap->valor = 5;
	zap->custo = 2;
	strcpy (zap->descricao, "Eletrize seu oponente com um feitico de choque! Tem chance de dobrar o dano.");
	zap->ID = 10;
}
int executa_Zap (carta *zap, jogador *j, monstro *m){
	define_Zap (zap);
	if (j->energiaAtual < zap->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", zap->nome);
		j->energiaAtual = j->energiaAtual - zap->custo;
		srand ((unsigned) time(0));
		int aleatorio = (rand () % 3); // Escolhe numeros entre 0 e 3 (4 possiveis valores)
		if (aleatorio == 0){ // Se o valor for 0, nao havera dano dobrado
			j->ataque = zap->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		}
		else { // Se "aleatorio" for 1, 2 ou 3, havera dano dobrado
			j->ataque = zap->valor + zap->valor - m->defesa; // 75% de chance de Dobrar o dano
			if (j->ataque < 0){
			j->ataque = 0;
		}
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}

// 11
void define_Esquivar_e_Atacar (carta *EeA){
	strcpy (EeA->nome, "Esquivar e Atacar");
	EeA->tipo = 'E';
	EeA->valor = 7;
	EeA->custo = 3;
	strcpy (EeA->descricao, "Esquive-se aumentando a Defesa em 7 e contra-ataque causando 7 de dano!");
	EeA->ID = 11;
}
int executa_Esquivar_e_Atacar (carta *EeA, jogador *j, monstro *m){
	define_Esquivar_e_Atacar (EeA);
	if (j->energiaAtual < EeA->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", EeA->nome);
		j->energiaAtual = j->energiaAtual - EeA->custo;
		j->defesa = EeA->valor;
		j->ataque = EeA->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}


// 12
void define_Onda_De_Ferro (carta *ondaDeFerro){ // +5 de Ataque + 5 de Defesa
	strcpy (ondaDeFerro->nome, "Onda de Ferro");
	ondaDeFerro->tipo = 'E';
	ondaDeFerro->valor = 5;
	ondaDeFerro->custo = 2;
	strcpy (ondaDeFerro->descricao, "Ataque e Defesa ao mesmo tempo! Ganha 5 de Ataque e 5 de Defesa.");
	ondaDeFerro->ID = 12;
}
int executa_Onda_De_Ferro (carta *ondaDeFerro, jogador *j, monstro *m){
	define_Onda_De_Ferro (ondaDeFerro);
	if (j->energiaAtual < ondaDeFerro->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", ondaDeFerro->nome);
		j->energiaAtual = j->energiaAtual - ondaDeFerro->custo;
		j->defesa = ondaDeFerro->valor;
		j->ataque = ondaDeFerro->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}

// 13
void define_Bola_De_Fogo (carta *bolaDeFogo){
	strcpy (bolaDeFogo->nome, "Bola de Fogo");
	bolaDeFogo->tipo = 'E';
	bolaDeFogo->valor = 12;
	bolaDeFogo->custo = 3;
	strcpy (bolaDeFogo->descricao, "BOLA DE FOGO");
	bolaDeFogo->ID = 13; 
}

int executa_Bola_De_Fogo (carta *bolaDeFogo, jogador *j, monstro *m){
	define_Bola_De_Fogo (bolaDeFogo);
	if (j->energiaAtual < bolaDeFogo->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", bolaDeFogo->nome);
		j->energiaAtual = j->energiaAtual - bolaDeFogo->custo;
		j->ataque = bolaDeFogo->valor - m->defesa;
		if (j->ataque < 0){
			j->ataque = 0;
		}
		m->vidaAtual = m->vidaAtual - j->ataque;
	}
	return 1;
}

//14
void define_Memento (carta *memento){
	strcpy (memento->nome, "Memento");
	memento->tipo = 'E';
	memento->valor = 4;
	memento->custo = 3;
	strcpy (memento->descricao, "Voce canaliza sua energia e rouba a de seu inimigo para se recuperar");
	memento->ID = 14; 
}

int executa_Memento (carta *memento, jogador *j, monstro *m){
	define_Memento (memento);
	if (j->energiaAtual < memento->custo){
		printf ("\n\nVOCE NAO PODE USAR ESSA CARTA!\n\n");
		return 0;
	}
	else {
		printf ("\n\nVoce usou %s \n\n", memento->nome);
		j->energiaAtual = j->energiaAtual - memento->custo;
		j->vidaAtual = j->vidaAtual + memento->valor;
		if (j->vidaAtual > j->vidaMax){ // Esse "if" impede que a Vida Atual seja maior que a Vida Maxima
			j->vidaAtual = j->vidaMax;
		}
		j->defesa = j->defesa + memento->valor;
	}
	return 1;
}

void executar_Carta (int i, carta *c, jogador *j, monstro *m){
	switch (i) {
		case 1:
			{
				executa_Golpe (c, j, m);
				break;
			}
		case 2:
			{
				executa_Porrada (c, j, m);
				break;
			}
		case 3:
			{
				executa_Corte_Rapido (c, j, m);
				break;
			}
		case 4:
			{
				executa_Hemocinesia (c, j, m);
				break;
			}
		case 5:
			{
				executa_Ombrada (c, j, m);
				break;
			}
		case 6:
			{
				executa_Bloqueio (c, j, m);
				break;
			}
		case 7:
			{
				executa_Sobrevivente (c, j, m);
				break;
			}
		case 8:
			{
				executa_Destruidor (c, j, m);
				break;
			}
		case 9:
			{
				executa_Segundo_Folego (c, j, m);
				break;
			}
		case 10:
			{
				executa_Zap (c, j, m);
				break;
			}
		case 11:
			{
				executa_Esquivar_e_Atacar (c, j, m);
				break;
			}
		case 12:
			{
				executa_Onda_De_Ferro (c, j, m);
				break;
			}
		case 13:
			{
				executa_Bola_De_Fogo (c, j, m);
				break;
			}
		case 14:
			{
				executa_Memento (c, j, m);
				break;
			}
	}
}

#endif
