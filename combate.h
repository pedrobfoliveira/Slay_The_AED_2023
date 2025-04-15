#ifndef COMBATE_H
#define COMBATE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "listade.h"
#include "pilha.h"
#include "monstros.h"
#include "mapa.h"


void executar_CartaJ (int i, carta *c, jogador *j, monstro *m){
	/* A ideia eh pegar o ID de cada carta e igualar a "i", assim navegando na listaD ate encontra a carta executada */
	switch (i){
		case 1:
			executa_Golpe (c, j, m);
			break;
			
		case 2:
			executa_Porrada (c, j, m);
			break;
			
		case 3:
			executa_Corte_Rapido (c, j, m);
			break;
			
		case 4:
			executa_Hemocinesia (c, j, m);
			break;
			
		case 5:
			executa_Ombrada (c, j, m);
			break;
		
		case 6:
			executa_Bloqueio (c, j, m);
			break;
		
		case 7:
			executa_Sobrevivente (c, j, m);
			break;
		
		case 8:
			executa_Destruidor (c, j, m);
			break;
			
		case 9:
			executa_Segundo_Folego(c, j, m);
			break;
			
		case 10:
			executa_Zap (c, j, m);
			break;
			
		case 11:
			executa_Esquivar_e_Atacar(c, j, m);
			break;
			
		case 12:
			executa_Onda_De_Ferro (c, j, m);
			break;
			
		case 13:
			executa_Bola_De_Fogo (c, j, m);
			break;
				
		case 14:
			executa_Memento (c, j, m);
			break;
	}
}

monstro selecionaMonstro (int i){ // Funcao que seleciona o monstro pro combate
	switch (i){
		case 1:
			{
			monstro goblin;
			goblin_ (&goblin);
			return goblin;
			}
		case 2:
			{
			monstro slime;
			slime_ (&slime);
			return slime;
			}
		case 3:
			{
			monstro coisa;
			o_coisa (&coisa);
			return coisa;
			}
		case 4:
			{	
			monstro feiticeiro;
			feiticeiro_ (&feiticeiro);
			return feiticeiro;
			}
		case 5:
			{
			monstro AED;
			AEDD (&AED);
			return AED;	
			}
		}
}

tp_fila filaMonstro (int i){
	switch (i){
		case 1:
			{
			tp_fila deckGoblin;
			criaFila (&deckGoblin, 1);
			return deckGoblin;
			}
		case 2:
			{
			tp_fila deckSlime;
			criaFila (&deckSlime, 2);
			return deckSlime;
			}
		case 3:
			{
			tp_fila deckCoisa;
			criaFila (&deckCoisa, 3);
			return deckCoisa;
			}
		case 4:
			{
			tp_fila deckFeiticeiro;
			criaFila (&deckFeiticeiro, 4);
			return deckFeiticeiro;
			}
		case 5:
			{
			tp_fila deckAED;
			criaFila (&deckAED, 5);
			return deckAED;
			}
		}
}

void gravar_no_arq (int i, FILE *f, int fase){
	f = fopen ("registro_combate.txt","a");
	switch (i){
		case 1:
			fprintf(f, "\nFase %d - Golpe", fase);
			break;
			
		case 2:
			fprintf(f, "\nFase %d - Porrada", fase);
			break;
			
		case 3:
			fprintf(f, "\nFase %d - Corte rapido", fase);
			break;
			
		case 4:
			fprintf(f, "\nFase %d - Hemocinesia", fase);
			break;
			
		case 5:
			fprintf(f, "\nFase %d - Ombrada", fase);
			break;
		
		case 6:
			fprintf(f, "\nFase %d - Bloqueio", fase);
			break;
		
		case 7:
			fprintf(f, "\nFase %d - Sobrevivente", fase);
			break;
		
		case 8:
			fprintf(f, "\nFase %d - Destruidor", fase);
			break;
			
		case 9:
			fprintf(f, "\nFase %d - Segundo folego", fase);
			break;
			
		case 10:
			fprintf(f, "\nFase %d - Zap", fase);
			break;
			
		case 11:
			fprintf(f, "\nFase %d - Esquivar e atacar", fase);
			break;
			
		case 12:
			fprintf(f, "\nFase %d - Onda de ferro", fase);
			break;
	}
	fclose(f);
}

void verificar_carta_no_arq(){
    char nomeCarta[1000];
	printf("\nDigite a carta e a fase na qual voce deseja verificar se ela foi usada no seguinte molde:\nFase (numero da fase) - (nome da carta com a primeira letra maiusucla)\n");
    scanf(" %[^\n]s", nomeCarta);

    FILE *f = fopen("registro_combate.txt", "r");
    if (f == NULL) {
        printf("O arquivo de pesquisa não pôde ser aberto.\n");
        return;
    }
    char linha[1000];
    int encontrou = 0;
    while (fgets(linha, sizeof(linha), f) != NULL) {
        if (strstr(linha, nomeCarta) != NULL) {
       	 printf("\nCarta encontrada! Continue sua jogatina.\nDigite uma carta para jogar: ");
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Carta nao encontrada... Continue sua jogatina.\nDigite uma carta para jogar: ");
    }

    fclose(f);
}


int imprimir_CartasM (tp_fila *f){ // Funcao para imprimir carta. Recebe o endereco de uma fila de cartas como parametro
	carta e;
	int cartaN;
	
	remove_fila(f, &e);
	cartaN = e.ID; // Iguala variavel cartaN ao ID da carta do monstro
	printf ("\n");
	printf ("									  NOME: %s\n", e.nome);
	printf ("									  > Tipo: %c\n", e.tipo);
	printf ("									  > Valor: %d\n", e.valor);
	printf ("									  > Custo: %d\n", e.custo);
	printf ("									  > Descricao: %s\n\n", e.descricao);
	printf ("									  -------------------------------------------\n");
	insere_fila (f, e);
	return cartaN;
}

void imprimir_CartasJ (carta *e){
    	printf ("\n ----------------------------------------------------------------------------\n");
        printf ("| Nome: %s\n", e->nome);
		printf ("| Tipo: %c\n", e->tipo);
		printf ("| Valor: %d\n", e->valor);
		printf ("| Custo: %d\n", e->custo);
		printf ("| Descricao: %s\n", e->descricao);
    	printf (" ----------------------------------------------------------------------------\n\n");
}

int cartasBOSS (tp_fila *f){ // Funcao para imprimir carta. Recebe o endereco de uma fila de cartas como parametro
	carta e;
	int cartaN;
	
	remove_fila(f, &e);
	cartaN = e.ID; // Iguala variavel cartaN ao ID da carta do monstro
	if(cartaN == 18){
		printf ("\n");
		printf ("									AEDD parece estar carregando... algo se prepare\n\n");
		printf("%s","	                 :::=.                                      \n");
		printf("%s","	             .::.    =:.   .                                \n");
		printf("%s","	            .+          :..                                 \n");
		printf("%s","	           :+:::   :-: =*::                                 \n");
		printf("%s","	        .--...*+*##*%%@@@@@#=.                              \n");
		printf("%s","	     ::-:  .**#%%%%%@@@%@@@@@@.           ...               \n");
		printf("%s","	  .+:   .:=#%%%##%@@@@@%@@@@@%=: .:--     +.                \n");
		printf("%s","	  =:   +%*##%%%%@@%#*%@@%@@%@%:::.  =:::-:.                 \n");
		printf("%s","	  *    *-%%%%%%@%%+%#%-#@@@@%* :                      .:    \n");
		printf("%s","	 =:     #%%%###@#:**@@@%%%@%%*:-       ..              *=.: \n");
		printf("%s","	 +   :=-#%%%%%%#+%*=:@@%%%%%-      +*%##*+=*--.       .@ -=.\n");
		printf("%s","	:=    +#%%%%%@*-=*@#%%%@@@%      -%%%@@@%@%%%%%=.    .*@%%  \n");
		printf("%s","	 .:--=##:+:*.*@+:*-%@%%@@@@++*:=#*%@%%@@%@@@@%%#:   .+@%%:  \n");
		printf("%s","	       =.   :*=  :=+#@@@@@@@@@@@@@@@%++: - .+%%%%#**+@%%#   \n");
		printf("%s","	                 .#+=%%@@@@@@@@%@@%#.        :#@@@%@@%%%=   \n");
		printf("%s","	                 :   ==+***#**#**-  .            ..:..      \n");

	}
	else{
		printf ("\n");
		printf ("									Ele... vai... ???\n\n");
		printf("%s","	                 :::=.                                      \n");
		printf("%s","	             .::.    =:.   .                                \n");
		printf("%s","	            .+          :..                                 \n");
		printf("%s","	           :+:::   :-: =*::                                 \n");
		printf("%s","	        .--...*+*##*%%@@@@@#=.                              \n");
		printf("%s","	     ::-:  .**#%%%%%@@@%@@@@@@.           ...               \n");
		printf("%s","	  .+:   .:=#%%%##%@@@@@%@@@@@%=: .:--     +.                \n");
		printf("%s","	  =:   +%*##%%%%@@%#*%@@%@@%@%:::.  =:::-:.                 \n");
		printf("%s","	  *    *-%%%%%%@%%+%#%-#@@@@%* :                      .:    \n");
		printf("%s","	 =:     #%%%###@#:**@@@%%%@%%*:-       ..              *=.: \n");
		printf("%s","	 +   :=-#%%%%%%#+%*=:@@%%%%%-      +*%##*+=*--.       .@ -=.\n");
		printf("%s","	:=    +#%%%%%@*-=*@#%%%@@@%      -%%%@@@%@%%%%%=.    .*@%%  \n");
		printf("%s","	 .:--=##:+:*.*@+:*-%@%%@@@@++*:=#*%@%%@@%@@@@%%#:   .+@%%:  \n");
		printf("%s","	       =.   :*=  :=+#@@@@@@@@@@@@@@@%++: - .+%%%%#**+@%%#   \n");
		printf("%s","	                 .#+=%%@@@@@@@@%@@%#.        :#@@@%@@%%%=   \n");
		printf("%s","	                 :   ==+***#**#**-  .            ..:..      \n");
	}
	insere_fila (f, e);
	return cartaN;
}


int escolher (tp_listaD *mao, jogador *j, monstro *m, int fase, FILE *f){ // Essa funcao serve pro jogador visualizar e escolher qual carta vai usar
	int escolha;
	
	tp_no_lista *atu;
	carta e;
	printf ("\n Digite o ID da carta que voce gostaria de usar:");
	printf ("\n (0) para nao jogar nenhuma carta");
	printf ("\n (20) para consultar o historico de cartas \n\n");
	imprime_listaD (mao); 
	while (j->energiaAtual > 0){ // O jogador pode usar quantas cartas quiser, desde que tenha Energia para usar tal carta
		int verificacao = 0;
		scanf ("%d", &escolha);
		if (escolha == 20){
			verificar_carta_no_arq();
			scanf("%d", &escolha);
		}
		atu = mao->ini;
		if (escolha == 0){ // Se o jogador digitar "0", quer dizer que ele nao quer jogar nenhuma carta 
			printf ("\n\nVoce escolheu jogar nenhuma carta\n\n");
			return 0;
		}
		while (!verificacao && atu != NULL){
			if (escolha == atu->info.ID){ // Procura o ID da carta dentro da mao do jogador
				executar_CartaJ (escolha, &e, j, m);
				gravar_no_arq (escolha, f, fase);

				printf ("\n\n > Energia: %d/%d \n\n", j->energiaAtual, j->energiaMax);
				verificacao = 1; // Se ele encontrar a carta, ele sai do while
			}
			else {
				atu = atu->prox; // Se a carta nao estiver nessa posicao da listaDE, ele avanca na lista para encontrar
			}
		}// Se ele sair do while, quer dizer que nao encontrou a carta

		if (verificacao == 0){ // Nao foi possivel encontrar a carta na mao
			printf ("Carta nao encontrada\n");
		}
	}
}
			
void imprimir_Combate (jogador *j, monstro *m){ // Imprime a parte visual do combate, vida do jogador e do monstro, etc
	printf ("NOME DO JOGADOR: %s							NOME DO MONSTRO: %s\n", j->nome, m->nome);
	printf ("> Vida: %d/%d 								 > Vida: %d/%d\n", j->vidaAtual, j->vidaMax, m->vidaAtual, m->vidaMax);
	printf ("> Energia: %d/%d\n", j->energiaAtual, j->energiaMax);
	printf ("> Ataque base: %d 							 > Ataque base: %d \n", j->ataque, m->ataque); 
	printf ("> Defesa base: %d 							 > Defesa base: %d\n", j->defesa, m->defesa); 
	printf ("									 > Descricao: %s \n\n", m->descricao);
	printf ("								          O MONSTRO VAI USAR : \n");
}


void define_Jogador (jogador *j){ // Apenas uma funcao para definir os atributos do jogador antes do combate
	j->vidaMax = 20;
	j->vidaAtual = 20;
	j->energiaMax = 3;
	j->energiaAtual = 3;
	j->ataque = 0;
	j->defesa = 0;
}


int inicia_combate (jogador *j, monstro *m, tp_listaD *mao, deck *deckJ, tp_fila *deckM, int fase, int up, FILE *f){ // Reformulando a funcao do combate, ta QUASE funcionando
	system ("cls");
	f = fopen ("registro_combate.txt","a");
	
	deck descarte;
	inicializa_pilha(&descarte);
	carta cartaM; // carta do monstro
	int aux; // Variavel auxiliar pra carta
	
	carta cartaJ; // carta do jogador
	
	*m = (selecionaMonstro (fase)); // Seleciona o Monstro equivalente a Primeira Fase
	int turno = 1; // Define o turno em que o combate esta
	fclose(f);
	while (j->vidaAtual > 0 && m->vidaAtual > 0){ // Executa o combate enquanto o jogador ou o monstro tiverem mais do que "0" de vida
		system ("cls");
		printf("\nTurno: %d\n\n", turno);
		if (pilha_vazia (deckJ) == 1){
			criaDeck (deckJ, up);
			embaralhaDeck(deckJ);
		}	
		j->energiaAtual = 3;
		cavaCartas (deckJ, mao); // Cava Cartas para a mao do Jogador
		Sleep (500);
		imprimir_Combate (j, m);
		Sleep (500);
		
		aux = imprimir_CartasM (deckM); 
		cartaM = cartasFila (aux);
		
		if (cartaM.tipo == 'D'){ // Se a carta do Monstro for de Defesa, ela sera executada antes da carta do jogador
			executar_CartaM (aux, &cartaM, j, m);
			
			escolher (mao, j, m, fase, f);
		}
		else {
			escolher (mao, j, m, fase, f);
		
			executar_CartaM (aux, &cartaM, j, m);
		}
		
		m->ataque = 0;
		j->ataque = 0;
		j->defesa = 0;
		m->defesa = 0; 
		
		turno++; // Aumenta o turno
		descarteMao (mao, &descarte); // Descarta as cartas usadas no turno
	}
	fclose(f);
}


void dialogo_BOSS (jogador *j){
	printf ("...\n");
	sleep (2);
	system ("cls");
	printf ("????: Hehe...");
	Sleep (3000);
	printf ("Estou supreso que voce foi capaz de chegar ate aqui, %s", j->nome);
	Sleep (3050);
	system ("cls");
	printf ("%s: Mas...", j->nome);
	Sleep (2500);
	printf (" Quem eh voce?");
	Sleep (2500);
	system ("cls");
	printf ("????: Que bom que perguntou...\n");
	Sleep (3500);
	system ("cls");
	printf ("????: EU SOU...\n\n");
	Sleep (1500);
	printf("    ##     #######  ##### \n");
    printf("   ####     ##   #   ## ## \n");
    printf("  ##  ##    ## #     ##  ## \n");
    printf("  ##  ##    ####     ##  ## \n");
    printf("  ######    ## #     ##  ## \n");
    printf("  ##  ##    ##   #   ## ## \n");
    printf("  ##  ##   #######  ##### \n");
	Sleep (4000);
	system("cls");
	printf("PH NAO CONCORDOU COM ISSO");
}


int combate_BOSS (jogador *j, monstro *m, tp_listaD *mao, deck *deckJ, tp_fila *deckM, int up, int fase, FILE *f){
	system ("cls");
	f = fopen ("registro_combate.txt","a");
	
	deck descarte;
	inicializa_pilha(&descarte);
	carta cartaM; // carta do monstro
	int aux; // Variavel auxiliar pra carta
	
	carta cartaJ; // carta do jogador
	
	*m = (selecionaMonstro (5)); // Seleciona o Monstro equivalente a Primeira Fase
	dialogo_BOSS(j);
	int turno = 1; // Define o turno em que o combate esta
	fclose(f);
	while (j->vidaAtual > 0 && m->vidaAtual > 0){ // Executa o combate enquanto o jogador ou o monstro tiverem mais do que "0" de vida
		system ("cls");
		printf("\nTurno: %d\n\n", turno);	
		if (pilha_vazia (deckJ) == 1){
			criaDeck (deckJ, up);
			embaralhaDeck(deckJ);
		}	
		j->energiaAtual = 3;
		cavaCartas (deckJ, mao); // Cava Cartas para a mao do Jogador
		Sleep (500);
		imprimir_Combate (j, m);
		Sleep (500);
		
		aux = cartasBOSS (deckM); 
		cartaM = cartasFila (aux);
		
		if (cartaM.tipo == 'D'){ // Se a carta do Monstro for de Defesa, ela sera executada antes da carta do jogador
			executar_CartaM (aux, &cartaM, j, m);
			
			escolher (mao, j, m, fase, f);
		}
		else {
			escolher (mao, j, m, fase, f);
		
			executar_CartaM (aux, &cartaM, j, m);
		}
		
		m->ataque = 1;
		j->ataque = 0;
		j->defesa = 0;
		m->defesa = 3; 
		
		turno++; // Aumenta o turno
		descarteMao (mao, &descarte); // Descarta as cartas usadas no turno
	}
	fclose(f);
}

#endif
