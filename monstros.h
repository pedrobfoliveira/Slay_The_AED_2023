#ifndef MONSTROS_H
#define MONSTROS_H

#include <stdio.h>
#include <string.h>
#include "filamonstro.h"
#define MAX 100

// A - Ataque; E - Espacial; D - Defesa
// AED
// Cartas de Ataque:

void golpe_De_Espada (carta *golpeDeEspada){
	strcpy (golpeDeEspada->nome, "Golpe de Espada");
	golpeDeEspada->tipo = 'A';
	golpeDeEspada->valor = 5;
	golpeDeEspada->custo = 0;
	strcpy (golpeDeEspada->descricao, "Realiza um corte com sua espada! Causa 5 de dano.");
	golpeDeEspada->ID = 1;
}
void executa_golpe_De_Espada (carta *golpeDeEspada, jogador *j, monstro *m){
	golpe_De_Espada (golpeDeEspada);
	printf ("\n\n %s usou %s", m->nome, golpeDeEspada->nome);
	m->ataque = m->ataque + golpeDeEspada->valor; // Alguns monstros podem ter mais ataque base do que outros
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}


void abraco_Grudento (carta *abracoGrudento){
	strcpy (abracoGrudento->nome, "Abraco Grudento");
	abracoGrudento->tipo = 'A';
	abracoGrudento->valor = 5;
	abracoGrudento->custo = 0;
	strcpy (abracoGrudento->descricao, "O monstro abraca o jogador com seu corpo grudento causando 5 de dano.");
	abracoGrudento->ID = 2;
}
void executa_abraco_Grudento (carta *abracoGrudento, jogador *j, monstro *m){
	abraco_Grudento (abracoGrudento);
	printf ("\n\n %s usou %s", m->nome, abracoGrudento->nome);
	m->ataque = m->ataque + abracoGrudento->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

void apunhalar_ (carta *apunhalar){
	strcpy (apunhalar->nome, "Apunhalar");
	apunhalar->tipo = 'A';
	apunhalar->valor = 8;
	apunhalar->custo = 0;
	strcpy (apunhalar->descricao, "Um golpe sorrateiro pelas costas do jogador! Nem mesmo eu vi essa! Causa 8 de dano.");
	apunhalar->ID = 3;
}
void executa_apunhalar (carta *apunhalar, jogador *j, monstro *m){
	apunhalar_ (apunhalar);
	printf ("\n\n %s usou %s", m->nome, apunhalar->nome);
	m->ataque = m->ataque + apunhalar->valor;
	m->ataque = m->ataque - j->defesa;
	if (m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}


void olhar_Devastador (carta *olharDevastador){
	strcpy (olharDevastador->nome, "Olhar Devastador");
	olharDevastador->tipo = 'A';
	olharDevastador->valor = 7;
	olharDevastador->custo = 0;
	strcpy (olharDevastador->descricao, "Apenas o encarando, a criatura consegue lhe atacar. Causa 7 de dano.");
	olharDevastador->ID = 4;
}
void executa_olhar_Devastador (carta *olharDevastador, jogador *j, monstro *m){
	olhar_Devastador (olharDevastador);
	printf ("\n\n %s usou %s", m->nome, olharDevastador->nome);
	m->ataque = m->ataque + olharDevastador->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0; 
	j->vidaAtual = j->vidaAtual - m->ataque;
}

// Cartas de Defesa:

void reflexos_Incriveis (carta *reflexosIncriveis){
	strcpy (reflexosIncriveis->nome, "Reflexos Incriveis");
	reflexosIncriveis->tipo = 'D';
	reflexosIncriveis->valor = 3;
	reflexosIncriveis->custo = 0;
	strcpy (reflexosIncriveis->descricao, "Seus reflexos impressionantes te ajudam a evitar dano de ataques eminentes. Aumenta Defesa em 3.");
	reflexosIncriveis->ID = 5;
}
void executa_reflexos_Incriveis (carta *reflexosIncriveis, jogador *j, monstro *m){
	reflexos_Incriveis (reflexosIncriveis);
	printf ("\n\n %s usou %s", m->nome, reflexosIncriveis->nome);
	m->defesa = m->defesa + reflexosIncriveis->valor;
	
}


void bloqueio_Estrategico (carta *bloqueioEstrategico){
	strcpy (bloqueioEstrategico->nome, "Bloqueio Estrategico");
	bloqueioEstrategico->tipo = 'D';
	bloqueioEstrategico->valor = 4;
	bloqueioEstrategico->custo = 0;
	strcpy (bloqueioEstrategico->descricao, "Usa sua propria arma para defender um golpe eminente. Ganhe 4 de Defesa.");
	bloqueioEstrategico->ID = 6;
}
void executa_bloqueio_Estrategico (carta *bloqueioEstrategico, jogador *j, monstro *m){
	bloqueio_Estrategico (bloqueioEstrategico);
	printf ("\n\n %s usou %s", m->nome, bloqueioEstrategico->nome);
	m->defesa = m->defesa + bloqueioEstrategico->valor;
	j->ataque = j->ataque - m->defesa;
}


void nao_Encoste (carta *naoEncoste){
	strcpy (naoEncoste->nome, "Nao Encoste");
	naoEncoste->tipo = 'D';
	naoEncoste->valor = 4;
	naoEncoste->custo = 0;
	strcpy (naoEncoste->descricao, "A criatura tem uma aparencia tao medonha que capaz de fazer os outros terem medo de toca-la. Defesa = 4");
	naoEncoste->ID = 7;
}
void executa_nao_Encoste (carta *naoEncoste, jogador *j, monstro *m){
	nao_Encoste (naoEncoste);
	printf ("\n\n %s usou %s", m->nome, naoEncoste->nome);
	m->defesa = m->defesa + naoEncoste->valor;
	j->ataque = j->ataque - m->defesa;
}

void armadura_Arcana (carta *armaduraArcana){
	strcpy (armaduraArcana->nome, "Armadura Arcana");
	armaduraArcana->tipo = 'D';
	armaduraArcana->valor = 6;
	armaduraArcana->custo = 0;
	strcpy (armaduraArcana->descricao, "A Criatura se envolve de mana, protegendo-se de um ataque. Ganha 6 de Defesa. Nao acumulavel");
	armaduraArcana->ID = 8;
}
void executa_armadura_Arcana (carta *armaduraArcana, jogador *j, monstro *m){
	armadura_Arcana (armaduraArcana);
	printf ("\n\n %s usou %s", m->nome, armaduraArcana->nome);
	m->defesa = armaduraArcana->valor; // Essa carta ignora a Defesa base do alvo quando usada.
	j->ataque = j->ataque - m->defesa;
}

// Cartas Especiais:

void absorver_Forcas (carta *absorverForcas){
	strcpy (absorverForcas->nome, "Absorver Forcas");
	absorverForcas->tipo = 'E';
	absorverForcas->valor = 5;
	absorverForcas->custo = 0;
	strcpy (absorverForcas->descricao, "Consegue absorver o poder do adversario, causando 5 de dano e recuperando 5 de vida");
	absorverForcas->ID = 9;
}
void executa_absorver_Forcas (carta *absorverForcas, jogador *j, monstro *m){
	absorver_Forcas (absorverForcas);
	printf ("\n\n %s usou %s", m->nome, absorverForcas->nome);
	m->ataque = absorverForcas->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
	m->vidaAtual = m->vidaAtual + absorverForcas->valor; // Soma o valor da carta na vida
	if (m->vidaAtual > m->vidaMax){
		m->vidaAtual = m->vidaMax; // Condicao para evitar que a Vida Atual do monstro seja maior do que sua Vida Max
	}
}


void quebra_Defesa (carta *quebraDefesa){
	strcpy (quebraDefesa->nome, "Quebra Defesa");
	quebraDefesa->tipo = 'E';
	quebraDefesa->valor = 4;
	quebraDefesa->custo = 0;
	strcpy (quebraDefesa->descricao, "Sua Defesa nao e nada para mim. Reduz a Defesa do Jogador para 0 e ataca causando 4 de dano.");
	quebraDefesa->custo = 0;
}
void executa_quebra_Defesa (carta *quebraDefesa, jogador *j, monstro *m){
	quebra_Defesa (quebraDefesa);
	printf ("\n\n %s usou %s", m->nome, quebraDefesa->nome);
	j->defesa = 0;
	m->ataque = m->ataque + quebraDefesa->valor;
	j->vidaAtual = j->vidaAtual - m->ataque;
}


void enfraquecer_ (carta *enfraquecer){
	strcpy (enfraquecer->nome, "Enfraquecer");
	enfraquecer->tipo = 'E';
	enfraquecer->valor = 2;
	enfraquecer->custo = 0;
	strcpy (enfraquecer->descricao, "Isso nem faz cocegas. PATETICO! Reduz o ataque do jogador em 2.");
	enfraquecer->ID = 11;
}
void executa_enfraquecer_ (carta *enfraquecer, jogador *j, monstro *m){
	enfraquecer_ (enfraquecer);
	printf ("\n\n %s usou %s", m->nome, enfraquecer->nome);
	j->ataque = j->ataque - enfraquecer->valor;
}


void choque_Eletrizante (carta *choqueEletrizante){
	strcpy (choqueEletrizante->nome, "Choque Eletrizante");
	choqueEletrizante->tipo = 'E';
	choqueEletrizante->valor = 6;
	choqueEletrizante->custo = 0;
	strcpy (choqueEletrizante->descricao, "Um raio de Energia que ao atingir o alvo causa 6 de dano e remove 1 de energia.");
	choqueEletrizante->ID = 12;
}
void executa_choque_Eletrizante (carta *choqueEletrizante, jogador *j, monstro *m){
	choque_Eletrizante (choqueEletrizante);
	printf ("\n\n %s usou %s", m->nome, choqueEletrizante->nome);
	m->ataque = m->ataque + choqueEletrizante->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
	j->energiaAtual = j->energiaAtual - 1;
}

void bocada (carta *bocada){
	strcpy (bocada->nome, "Bocada");
	bocada->tipo = 'A';
	bocada->valor = 6;
	bocada->custo = 0;
	strcpy (bocada->descricao, "Uma feroz mordida");
	bocada->ID = 13;
}

void executa_bocada (carta *Bocada, jogador *j, monstro *m){
	bocada (Bocada);
	m->ataque = m->ataque + Bocada->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

void golpe_de_Cauda (carta *golpeCauda){
	strcpy (golpeCauda->nome, "Golpe de Cauda");
	golpeCauda->tipo = 'A';
	golpeCauda->valor = 5;
	golpeCauda->custo = 0;
	strcpy (golpeCauda->descricao, "Um golpe rapido de cauda");
	golpeCauda->ID = 14;
}

void executa_golpe_de_Cauda (carta *golpeCauda, jogador *j, monstro *m){
	golpe_de_Cauda (golpeCauda);
	m->ataque = m->ataque + golpeCauda->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

void agarrao_de_Bobina(carta *agarraoBobina){
	strcpy (agarraoBobina->nome, "Agarrao de Bobina");
	agarraoBobina->tipo = 'E';
	agarraoBobina->valor = 4;
	agarraoBobina->custo = 0;
	strcpy (agarraoBobina->descricao, "A criatura carrega e agarra o inimigo a prendendo-a enquanto a rodeia, quebrando sua defesa, e termina com um choque");
	agarraoBobina->ID = 15;
}

void executa_agarrao_de_Bobina (carta *agarraoBobina, jogador *j, monstro *m){
	agarrao_de_Bobina (agarraoBobina);
	m->ataque = m->ataque + agarraoBobina->valor;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

void descarga_Eletrica (carta *descargaEletrica){
	strcpy (descargaEletrica->nome, "Descarga Eletrica");
	descargaEletrica->tipo = 'A';
	descargaEletrica->valor = 9;
	descargaEletrica->custo = 0;
	strcpy (descargaEletrica->descricao, "A criatura libera descarga eletrica acontece atingindo uma area ao seu redor");
	descargaEletrica->ID = 16;
}

void executa_descarga_Eletrica (carta *descargaEletrica, jogador *j, monstro *m){
	descarga_Eletrica (descargaEletrica);
	m->ataque = m->ataque + descargaEletrica->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

void enrolar(carta *enrolar){
	strcpy (enrolar->nome, "Enrolar");
	enrolar->tipo = 'D';
	enrolar->valor = 7;
	enrolar->custo = 0;
	strcpy (enrolar->descricao, "A criatura se enrola com seu proprio corpo para se defender");
	enrolar->ID = 17;
}

void executa_enrolar (carta *Enrolar, jogador *j, monstro *m){
	enrolar (Enrolar);
	m->defesa = m->defesa + Enrolar->valor;
	j->ataque = j->ataque - m->defesa;
}

void carregar (carta *Carregar){
	strcpy (Carregar->nome, "Carregar");
	Carregar->tipo = 'E';
	Carregar->valor = 2;
	Carregar->custo = 0;
	strcpy (Carregar->descricao, "A criatura parece estar... carregando algo?");
	Carregar->ID = 18;
}

void executa_carregar (carta *Caregar, jogador *j, monstro *m){
	enrolar (Caregar);
	m->defesa = m->defesa + Caregar->valor;
	j->ataque = j->ataque - m->defesa;
}

void descarga_eletrica_Massiva(carta *DEM){
	strcpy (DEM->nome, "Descarga Eletrica Massiva");
	DEM->tipo = 'E';
	DEM->valor = 15;
	DEM->custo = 0;
	strcpy (DEM->descricao, "A criatura esta carregada totalmente uma grande explosao eletrica vai acontecer");
	DEM->ID = 19;
}

void executa_descarga_eletrica_Massiva (carta *DEM, jogador *j, monstro *m){
	descarga_eletrica_Massiva (DEM);
	m->ataque = m->ataque + DEM->valor;
	m->ataque = m->ataque - j->defesa;
	if(m->ataque < 0)
		m->ataque = 0;
	j->vidaAtual = j->vidaAtual - m->ataque;
}

// Os Monstros sao funcoes que atribuem valores aos Struct do tipo Monstro, atribuindo seus valores a elas

carta cartasFila (); // Declaramos essas duas funcoes aqui em cima, mas por preferencia deixamos ambas no final do codigo
tp_fila criaFila ();

void goblin_ (monstro *goblin){ // Funcao que atribui valores para o Struct do tipo monstro
	strcpy (goblin->nome, "Goblin"); // Nome do Monstro
	goblin->vidaMax = 20; // Vida Maxima e a Atual do Monstro
	goblin->vidaAtual = 20;
	goblin->ataque = 0; // Ataque Base do Monstro (somente alguns monstros especiais tem ataque maior que 0)
	goblin->defesa = 0; // Defesa Base do Monstro (somente alguns monstros especiais tem ataque maior que 0)
	strcpy (goblin->descricao, "Um inimigo fragil e pequeno, porem ligeiro e esperto."); // Breve descricao do que o monstro faz	
// As cartas do Goblin sao: "Golpe de Espada", "Apunhalar", "Reflexos Incriveis", "Bloqueio Estrategico"
}


void slime_ (monstro *slime){
	strcpy (slime->nome, "Slime");
	slime->vidaMax = 25;
	slime->vidaAtual = 25;
	slime->ataque = 0;
	slime->defesa = 2; // O slime tem uma Defesa passiva de 2
	strcpy (slime->descricao, "Ele e grudento e molengo, as vezes nem sei se ele sente os golpes que recebe. Tem uma Defesa Passiva = 2");
// As cartas do Slime sao: "Abraco Grudento", "Absorver Forcas", "Nao Encoste"
}


void o_coisa (monstro *coisa){
	strcpy (coisa->nome, "O Coisa");
	coisa->vidaMax = 20;
	coisa->vidaAtual = 20;
	coisa->ataque = 0;
	coisa->defesa = 0;
	strcpy (coisa->descricao, "Uma criatura estranha cuja a aparencia nao pode ser bem descrita. Seus olhos encaram minha alma. Bizarro!");
// As cartas do O Coisa sao: "Olhar Devastador", "Nao Encoste" e "Quebra Defesa"
}


void feiticeiro_ (monstro *feiticeiro){
	strcpy (feiticeiro->nome, "Feiticeiro");
	feiticeiro->vidaMax = 30;
	feiticeiro->vidaAtual = 30;
	feiticeiro->ataque = 1;
	feiticeiro->defesa = 0;
	strcpy (feiticeiro->descricao, "Um homem que usa a arte da feiticaria para manipular a batalha. Todas suas cartas causam +1 de dano.");
// As cartas do Feiticeiro sao: "Absorver Forças", "Enfraquecer", "Choque Eletrizante", "Armadura Arcana", "Reflexos Incriveis"
}


// BOSS FINAL
void AEDD (monstro *AED){
	strcpy (AED->nome, "AED");
	AED->vidaMax = 40;
	AED->vidaAtual = 40;
	AED->ataque = 1;
	AED->defesa = 3;
	strcpy (AED->descricao, "Uma criatura... ou maquina, que lembra uma centipoda, esta constantemente realizando choques eletricos");
// As cartas do AED sao: "Bocada", "Golpe de Cauda", "Agarrao de Bobina", "Descarga Eletrica", "Enrolar", "Carregar", e "Descarga Massiva Eletrica"
}


carta cartasFila (int i){ // Um Switch que relaciona cada carta com um numero inteiro
	carta p; // p eh apenas um parametro para as cartas do tipo "carta" atribuirem seus valores
	switch (i){
		case 1:
			golpe_De_Espada (&p);
			break;
		
		case 2:
			abraco_Grudento (&p);
			break;

		case 3:
			apunhalar_ (&p);
			break;
		
		case 4: 
			olhar_Devastador (&p);
			break;

		case 5:
			reflexos_Incriveis (&p);
			break;

		case 6:
			bloqueio_Estrategico (&p);
			break;

		case 7:
			nao_Encoste (&p);
			break;
			
		case 8:
			absorver_Forcas (&p);	
			break;
		
		case 9:
			quebra_Defesa (&p);
			break;	
		case 10:
			enfraquecer_ (&p);
			break;
		case 11:
			choque_Eletrizante (&p);
			break;
		case 12:
			armadura_Arcana (&p);
			break;
		case 13:
			bocada (&p);
			break;
		case 14:
			golpe_de_Cauda (&p);
			break;
		case 15:
			agarrao_de_Bobina (&p);
			break;
		case 16:
			descarga_Eletrica (&p);
			break;
		case 17:
			enrolar (&p);
			break;
		case 18:
			carregar (&p);
			break;
		case 19:
			descarga_eletrica_Massiva (&p);
			break;
		}
    return p;
}

tp_fila criaFila (tp_fila *f, int m){ // Esta funcao cria uma fila de cartas pros monstros
	inicializa_fila (f);
	switch (m) // Cada monstro foi relacionado a um numero, assim como cada carta
	{
		case 1: // Cartas do Goblin
		{
			insere_fila (f, cartasFila (1)); // Golpe de Espada
			insere_fila (f, cartasFila (3)); // Apunhalar
			insere_fila (f, cartasFila (5)); // Reflexos Incriveis
			insere_fila (f, cartasFila (6)); // Bloqueio Estrategico
			break;
		}
		case 2: // Cartas do Slime
		{
			insere_fila (f, cartasFila (2)); // Abraco Grudento
			insere_fila (f, cartasFila (7)); // Nao Encoste
			insere_fila (f, cartasFila (8)); // Absorver Forcas
			break;
		}
		case 3: // Cartas do O Coisa
		{
			insere_fila (f, cartasFila (4)); // Olhar Devastador
			insere_fila (f, cartasFila (7)); // Nao Encoste
			insere_fila (f, cartasFila (9)); // Quebra Defesa
			break;
		}
		case 4: // Cartas do Feiticeiro
		{
			insere_fila (f, cartasFila (5)); // Reflexos Incriveis
			insere_fila (f, cartasFila (8)); // Absorver Forcas
			insere_fila (f, cartasFila (10)); // Enfraquecer
			insere_fila (f, cartasFila (11)); // Choque Eletrizante
			insere_fila (f, cartasFila (12)); // Armadura Arcana
			break;
		}
		case 5: // Cartas do AEDD
		{
			insere_fila (f, cartasFila (13));
			insere_fila (f, cartasFila (14));
			insere_fila (f, cartasFila (15));
			insere_fila (f, cartasFila (16));
			insere_fila (f, cartasFila (17));
			insere_fila (f, cartasFila (18));
			insere_fila (f, cartasFila (19));
			break;
		}
	}
}

void executar_CartaM (int i, carta *c, jogador *j, monstro *m){ // Funcao para execucao da carta do Monstro
	switch (i){
		case 1:
			{
				executa_golpe_De_Espada(c, j, m);
				break;
			}
		case 2:
			{
				executa_abraco_Grudento(c,j,m);
				break;
			}
		case 3:
			{
				executa_apunhalar(c,j,m);
				break;
			}
		case 4:
			{
				executa_olhar_Devastador(c,j,m);
				break;
			}
		case 5:
			{
				executa_reflexos_Incriveis(c,j,m);
				break;
			}
		case 6:
			{
				executa_bloqueio_Estrategico(c,j,m);
				break;
			}
		case 7:
			{
				executa_nao_Encoste(c,j,m);
				break;
			}
		case 8:
			{
				executa_armadura_Arcana(c,j,m);
				break;
			}
		case 9:
			{
				executa_absorver_Forcas(c,j,m);
				break;
			}
		case 10:
			{
				executa_quebra_Defesa(c,j,m);
				break;
			}
		case 11:
			{
				executa_enfraquecer_(c,j,m);
				break;
			}
		case 12:
			{
				executa_choque_Eletrizante(c,j,m);
				break;
			}
		case 13:
			{
				executa_bocada(c,j,m);
				break;
			}
		case 14:
			{
				executa_golpe_de_Cauda(c,j,m);
				break;
			}
		case 15:
			{
				executa_agarrao_de_Bobina(c,j,m);
				break;
			}
		case 16:
			{
				executa_descarga_Eletrica(c,j,m);
				break;
			}
		case 17:
			{
				executa_enrolar(c,j,m);
				break;
			}
		case 18:
			{
				executa_carregar(c,j,m);
				break;
			}
		case 19:
			{
				executa_descarga_eletrica_Massiva(c,j,m);
				break;
			}
	}
}

#endif
