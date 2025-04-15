#include "combate.h"
#include "mapa.h"
#include "abstrato.h"

#include <unistd.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void imprimir_Monstro (monstro *m){ // Funcao para imprimir o monstro, com suas cartas embaixo. Recebe um endereco de monstro como parametro
	printf ("NOME DO MONSTRO: %s \n", m->nome);
	printf ("> Vida: %d/%d \n", m->vidaAtual, m->vidaMax);
	printf ("> Ataque base: %d \n", m->ataque);
	printf ("> Defesa base: %d \n", m->defesa);
	printf ("> Descricao: %s \n\n", m->descricao);
	printf ("C A R T A S : \n\n");
}

void imprimir_Jogador (jogador *j){ // So temos um personagem pro jogador, entao definimos seus atributos na mesma funcao que imprimimos
	define_Jogador (j);
	printf ("NOME DO JOGADOR: %s \n", j->nome);
	printf ("> Vida: %d/%d \n", j->vidaAtual, j->vidaMax);
	printf ("> Energia: %d/%d \n", j->energiaAtual, j->energiaMax);
	printf ("> Ataque base: %d \n", j->ataque); // O ataque base do jogador eh zero pois ele depende apenas das cartas
	printf ("> Defesa base: %d \n\n", j->defesa); // A defesa base do jogador eh zero pois ela depende apenas das cartas
	printf ("C A R T A S : \n");
}

void imprimir_DeckJ(deck *d){
	criaDeck (d, 14);
	embaralhaDeck (d);
	carta e;
	printf ("\n TODAS AS CARTAS DO JOGADOR EMBARALHADAS NUMA PILHA:\n\n"); // Mostrando todas as cartas do jogador
	//imprime_pilha (*d);
	while (!pilha_vazia (d)) {
		pop (d, &e);
    	printf ("\n ----------------------------------------------------------------------------\n");
        printf ("| Nome: %s\n", e.nome);
		printf ("| Tipo: %c\n", e.tipo);
		printf ("| Valor: %d\n", e.valor);
		printf ("| Custo: %d\n", e.custo);
		printf ("| Descricao: %s\n", e.descricao);
    	printf (" ----------------------------------------------------------------------------\n");
		Sleep (500);
	}
}

void imprimir_DeckM (tp_fila *f){ // Funcao para imprimir carta. Recebe o endereco de uma fila de cartas como parametro
	carta e;	
	remove_fila(f, &e);
	printf ("\n ----------------------------------------------------------------------------\n");
        printf ("| Nome: %s\n", e.nome);
		printf ("| Tipo: %c\n", e.tipo);
		printf ("| Valor: %d\n", e.valor);
		printf ("| Custo: %d\n", e.custo);
		printf ("| Descricao: %s\n", e.descricao);
    	printf (" ----------------------------------------------------------------------------\n");
		Sleep (500);
	insere_fila (f, e);
}

void impressao_monstros (){ // Essa funcao apenas serve para o usuario escolhe qual monstro ele quer imprimir
	int mon; // Esse "mon" aqui serve para uma "selecao aleatoria" do monstro para o inicio do combate
	printf ("Escolha qual Monstro voce quer imprimir:\n");
	printf (" (1) Goblin \n (2) Slime\n (3) O Coisa\n (4) Feiticeiro\n (5) ????\n");
	scanf ("%d", &mon); // Esse scanf serve apenas para a vizualizacao dos monstros e suas cartas
	system ("cls");
	switch (mon){
		case 1:
			{
			monstro goblin;
			goblin_ (&goblin);
			tp_fila deckGoblin;
			imprimir_Monstro (&goblin);
			criaFila (&deckGoblin, 1);
			for (int i = 0; i < 4; i++){
				imprimir_DeckM (&deckGoblin);
			}
			break;
			}
		case 2:
			{
			monstro slime;
			slime_ (&slime);
			tp_fila deckSlime;
			imprimir_Monstro (&slime);
			criaFila (&deckSlime, 2);
			for (int i = 0; i < 3; i++){
				imprimir_DeckM (&deckSlime);
			}
			break;
			}
		case 3:
			{
			monstro coisa;
			o_coisa (&coisa);
			tp_fila deckCoisa;
			imprimir_Monstro (&coisa);
			criaFila (&deckCoisa, 3);
			for (int i = 0; i < 3; i++){
				imprimir_DeckM (&deckCoisa);
			}
			break;
			}
		case 4:
			{
			monstro feiticeiro;
			feiticeiro_ (&feiticeiro);
			tp_fila deckFeiticeiro;
			imprimir_Monstro (&feiticeiro);
			criaFila (&deckFeiticeiro, 4);
			for (int i = 0; i < 5; i++){
				imprimir_DeckM (&deckFeiticeiro);
			}
			break;
			}
		case 5:
			{
			printf ("%s"," > Eu nao sei o que isso... E acho que nem voce vai querer saber...\n\n");
			printf("%s","                 :::=.                                      \n");
			printf("%s","             .::.    =:.   .                                \n");
			printf("%s","            .+          :..                                 \n");
			printf("%s","           :+:::   :-: =*::                                 \n");
			printf("%s","        .--...*+*##*%%@@@@@#=.                              \n");
			printf("%s","     ::-:  .**#%%%%%@@@%@@@@@@.           ...               \n");
			printf("%s","  .+:   .:=#%%%##%@@@@@%@@@@@%=: .:--     +.                \n");
			printf("%s","  =:   +%*##%%%%@@%#*%@@%@@%@%:::.  =:::-:.                 \n");
			printf("%s","  *    *-%%%%%%@%%+%#%-#@@@@%* :                      .:    \n");
			printf("%s"," =:     #%%%###@#:**@@@%%%@%%*:-       ..              *=.: \n");
			printf("%s"," +   :=-#%%%%%%#+%*=:@@%%%%%-      +*%##*+=*--.       .@ -=.\n");
			printf("%s",":=    +#%%%%%@*-=*@#%%%@@@%      -%%%@@@%@%%%%%=.    .*@%%  \n");
			printf("%s"," .:--=##:+:*.*@+:*-%@%%@@@@++*:=#*%@%%@@%@@@@%%#:   .+@%%:  \n");
			printf("%s","       =.   :*=  :=+#@@@@@@@@@@@@@@@%++: - .+%%%%#**+@%%#   \n");
			printf("%s","                 .#+=%%@@@@@@@@%@@%#.        :#@@@%@@%%%=   \n");
			break;
			}
		case 6: // Easter egg :)
			{
			system ("cls");
			imprimir_Soussa ();
			break;
			}
	}
}


int main (){
	jogador j;
	deck deckJ;
	carta p;
	carta z;
	FILE *f, *F;
	tp_listaD mao;
	tp_listase *mapa; // Criar o mapa
	mapa = NULL;
	tp_listase *atu;
	int atalho;
	f = fopen ("registro_fase.txt","a");
	F = fopen("registro_combate.txt","a");
	int fase = 0; // Variavel equivalente a fase
	int up;
	int fim = 1;
	up = 11;
	criaDeck (&deckJ, up); // Cria um deck pro jogador
	embaralhaDeck (&deckJ); 

	monstro m;
	tp_fila deckM; // Cria uma lista de acoes/cartas do Monstro 

	int escolha = 0;
	sleep (1); // Os "sleeps" fazem pausas dramaticas :)
	printf ("Ola, seja bem-vindo...");
	sleep (2);
	printf ("Espera... Como posso te chamar?\n");
	scanf ("%[^\n]s", &j.nome);
	system ("cls");
	printf ("Pronto! \n");
	printf ("Ola %s, seja bem-vindo ao...\n\n", j.nome);
	sleep (2);
	while(fim == 1){
	system ("cls");
	printf("           ###                                ######   ##   ##  #######             ##     #######  ##### \n");
    printf("            ##                                # ## #   ##   ##   ##   #            ####     ##   #   ## ## \n");
    printf("  #####     ##      ####    ##  ##              ##     ##   ##   ## #             ##  ##    ## #     ##  ## \n");
    printf(" ##         ##         ##   ##  ##              ##     #######   ####             ##  ##    ####     ##  ## \n");
    printf("  #####     ##      #####   ##  ##              ##     ##   ##   ## #             ######    ## #     ##  ## \n");
    printf("      ##    ##     ##  ##    #####              ##     ##   ##   ##   #           ##  ##    ##   #   ## ## \n");
    printf(" ######    ####     #####       ##             ####    ##   ##  #######           ##  ##   #######  ##### \n");
    printf("                            #####\n");
    
    printf ("\n\n");
	sleep (3);
	printf ("Esta pronto para entrar nesse DUNGEON e INICIAR o combate? \n");
	printf ("(1) INICIAR \n(2) VER CONTEUDO \n(3) SAIR \n\n");
	int sim;
	scanf ("%d", &sim);
	switch (sim){
		case 1:
			break;
		case 2:
			system ("cls");
			printf ("Voce quer imprimir um jogador ou um monstro?\n");
			printf (" (1) Jogador \n (2) Monstro \n (3) Nao quero nada\n\n");
			scanf ("%d", &escolha);
			system ("cls");
	
			if (escolha == 1){
				imprimir_Jogador (&j);
				deck deckJogador;
				imprimir_DeckJ (&deckJogador);
		
				return 0;
			}
			if (escolha == 2){
				impressao_monstros ();
				return 0;
			}
			else {
				printf ("Puxa vida, entao ate a proxima :)");
			}
			break;
		case 3:
			return 0;
	}
	printf ("Boa sorte %s\n\n", j.nome);
	printf ("\n\nColoque tela Cheia para melhor experiencia\n\n");
	criar_mapa (&mapa); // Cria o mapa // Imprime o mapa em relacao a fase em que o Jogador esta (Nesse caso, o Comeco)
	define_Jogador (&j); // So pra definir o jogado soussa
	while (fase != 5){
		fase = (avanca_fase (&mapa, fase, f));
		if (fase==5){
			break;
		}
		if (fase==2 || fase==4){
			printf("\n\nVoce quer pegar um desvio?\n(0) NAO\n(1) SIM\n");
			scanf ("%d", &atalho);
		}
		if (atalho&&fase==2){
			system ("cls");
			atu=mapa;
			atu=atu->prox->desvio;
			printf ("Voce encontra uma fonte de agua magica.\nAo beber da fonte voce recupera sua forca.\n");
			imprimir_mapaD1();
			sleep(5);
			j.vidaAtual=20;
			fase = (avanca_fase (&mapa, fase, f));
			system ("cls");
		}
		if (fase==5){
			break;
		}
		if (atalho&&fase==4){
			system ("cls");
			atu=mapa;
			atu=atu->prox->prox->prox->desvio;
			printf ("Voce encontra uma fonte de agua magica.\nAo beber da fonte voce recupera sua forca.\n");
			imprimir_mapaD2();
			sleep(5);
			j.vidaAtual=20;
			fase = (avanca_fase (&mapa, fase, f));
			atalho=0;
			system ("cls");
		}
		if (fase==5){
			break;
		} 
		imprimir_mapa(fase);
		sleep (3);
		criaFila (&deckM, fase);
		
		inicia_combate (&j, &m, &mao, &deckJ, &deckM, fase, up, F); // Funcao que inicia o combate
		if (j.vidaAtual < 1) {
			system ("cls");
			printf ("Voce perdeu :( \nTente novamente!");
			return 0; // Jogo acabou, tente novamente
		}
		
		if (m.vidaAtual < 1) {
			system ("cls"); 
			printf("PARABENS!\n");
			sleep (1);
			printf ("Voce venceu :)\n\n");
			sleep (1);
			up++;
		}	
	}
	
	if(fase == 5){
		imprimir_mapa(5);
			sleep (3);
		criaFila (&deckM, 5);
		combate_BOSS (&j, &m, &mao, &deckJ, &deckM, up, fase, F);
		if (j.vidaAtual < 1) {
			system ("cls");
			printf ("Voce perdeu :( \nTente novamente!");
			return 0; // Jogo acabou, tente novamente
		}
		if (m.vidaAtual < 1) {
			system ("cls");
			sleep (1);
			printf ("Voce desfere o golpe final e assim finalizando seu inimigo, uma enorme euforia encobre voce e apenas uma coisa\n");
			printf ("consegue ser proferida de sua voz...\n\n");
			sleep (3);
			printf ("Dark.\n\n");
			sleep (2);
			system("cls");
			printf("-=+++==+++=.  -===-  -=+=-   :=====++++=.\n");
			printf("+@@@@@@@@@@@* :@@@@@- @@@@@- -@@@@@@@@@@@*\n");
			printf("=@@@@@@@@@@@= .@@@@@. @@@@@: *@@@@@@@@@@@:\n");
			printf("  .:%@@@@:..  .@@@@@  @@@@@: #@@@@*    .\n");
			printf("    %@@@@     :@@@@%::@@@@@. *@@@@=-----.\n");
			printf("    @@@@#     -@@@@@@@@@@@@  *@@@@@@@@@@#\n");
			printf("   .@@@@#     =@@@@@%#%@@@@. +@@@@******=\n");
			printf("   =@@@@#     =@@@@@- :@@@@. -@@@@-  .:.\n");
			printf("   #@@@@@     =@@@@@: -@@@@   @@@@@@@@@@@=\n");
			printf("   %@@@@@     -@@@@@. -@@@@   +@@@@@@@@@@+\n");
			printf("    :::..      .::-:   :--:     .:::::.\n");
			printf("  :::::::--.    .::.  .+*+:    .:::::.\n");
			printf("=@@@@@@@@@@@: :@@@@@= @@@@@. =@@@@@@@@@+.\n");
			printf("%@@@@@@@@@@  #@@@@@@.#@@@@- #@@@@@@@@@@@.\n");
			printf("@@@@@+:::--:  #@@@@@@*+@@@@- #@@@@--%@@@@#\n");
			printf("@@@@@         #@@@@@@@#@@@@- #@@@@. .@@@@@\n");
			printf("@@@@@@@@@@-  #@@@@@@@@@@@@- #@@@@.  #@@@@\n");
			printf("%@@@@%%@@@@-  *@@@@@@@@@@@@- *@@@@.  *@@@@\n");
			printf("*@@@@         *@@@@%%@@@@@@. +@@@@- .%@@@#\n");
			printf("-@@@@##@@@@#  +@@@@*-@@@@@@  =@@@@@@@@@@@.\n");
			printf(" %@@@@@@@@@@- =@@@@* %@@@@*  :@@@@@@@@@*.\n");
			printf("  -=++++==-.  :+**+- .++++    :=====-:\n");
		}
	}
	printf("Deseja voltar ao menu ou encerrar o jogo? Sim(1) Nao(0)");
	scanf("%d", fim);
	}
}
