#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define MAX_NAME_LENGTH 20
#define MAX_GOUSMAS 5


int acertos = 0;
// --------------------------- Estruturas --------------------------- //

typedef struct {
    char name[MAX_NAME_LENGTH];
} Player;

typedef struct {
    int fury;
} Gousma;

typedef struct {
    Gousma gousmas[MAX_GOUSMAS];
    int gousmaCount;
} GousmaPlayer;

// --------------------------- Funções Utilitárias --------------------------- //

void shuffle(int *array, int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// --------------------------- Jogo 1: Quiz de Nerdices --------------------------- //

void quizp1() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	srand(time(NULL));
    int questao, escolha;
    acertos = 0;
    questao = rand() % 3;
    system("cls");
    switch (questao) {
        case 0:
            printf("Qual é a sequência conhecida popularmente como Konami Code?\n1) CIMA CIMA BAIXO BAIXO ESQUERDA DIREITA ESQUERDA DIREITA B A\n2) BAIXO CIMA BAIXO BAIXO DIREITA ESQUERDA START\n3) BAIXO BAIXO DIREITA ESQUERDA MEIA LUA START\n4) BAIXO BAIXO CIMA CIMA DIREITA ESQUERDA DIREITA ESQUERDA START\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Ainda lembra das coisas então...\n");
				acertos ++;
				Sleep(2000);
				quizp2();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp1();
				break;
			}
            break;
        case 1:
            printf("Quais jogos a seguir são reconhecidos por sua dificuldade extrema?\n1) Pathologic e Contra\n2) Spelunky e Rain World\n3) Dark Souls e Ultrakill\n4) Todas as opções anteriores.\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nÉ... essa era uma complicada, já que os três jogos são de nichos bem diferentes. Parabéns!\n");
				acertos ++;
				Sleep(2000);
				quizp2();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp1();
				break;
			}
            break;
        case 2:
            printf("Qual foi o famoso jogo mais vendido da história?\n1) Pokémon\n2) Tetris\n3) Minecraft\n4) GTA V\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Muita gente ainda pensa que foi Tetris, mas Minecraft já passou Tetris faz tempo!\n");
				acertos ++;
				Sleep(2000);
				quizp2();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp2();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp1();
				break;
			}
            break;
    }
}

void quizp2() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int questao, escolha;
    questao = rand() % 3;
    system("cls");
  	switch (questao) {
        case 0:
            printf("EA é uma empresa famosa por..?\n1) Fazer jogos muito bugados, mas que de certa forma funcionam.\n2) Jogos com alta dificuldade e sem modo fácil.\n3) Microtransações excessivas em seus jogos, junto a outras políticas predatórias.\n4) Jogos de rpg com caminhos alternativos complexos e diversos finais.\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Ainda lembra das coisas então...\n");
				acertos ++;
				Sleep(2000);
				quizp3();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp2();
				break;
			}
            break;
        case 1:
            printf("Qual dos jogos a seguir é do gênero RPG?\n1) Call of Duty Black Ops 2\n2) Rain World\n3) FAITH: The Unholy Trinity\n4) Fallout New Vegas\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Talvez você tenha manipulado esse jogo desde o início.\n");
				acertos ++;
				Sleep(2000);
				quizp3();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp2();
				break;
			}
            break;
        case 2:
            printf("Dentre as opções, qual dos jogos tem a maior comunidade de modders?\n1) Inscryption\n2) Minecraft\n3) Helldivers\n4) Dead Cells\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Minecraft vive até hoje por causa do tanto de mods que tem.\n");
				acertos ++;
				Sleep(2000);
				quizp3();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp3();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp2();
				break;
			}
            break;
    }
}
void quizp3()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int questao, escolha;
    questao = rand() % 3;
    system("cls");
  	switch (questao) {
        case 0:
            printf("It's dangerous to go alone! Take this.\n1) The Legend of Zelda \n2) Super Mario World\n3) Street Fighter 2 Turbo\n4) Cyberpunk 2077\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Essa frase icônica é de Zelda!\n");
				acertos ++;
				Sleep(2000);
				quizp4();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp3();
				break;
			}
            break;
        case 1:
            printf("You were almost a Jill sandwich!\n1) Asleep\n2) Mullet Mad Jack\n3) ZOMBI\n4) Resident Evil\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Você deve ser um mestre das fechaduras!");
				Sleep(2000);
				printf("\nMestre dos quiz*\n");
				acertos ++;
				Sleep(2000);
				quizp4();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp3();
				break;
			}
            break;
        case 2:
            printf("Objection!\n1) Phoenix Wright: Ace Attorney \n2) Stranded Deep\n3) Danganronpa V3: Killing Harmony\n4) Don't Starve Together\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Não tenho nenhuma objeção a isso.\n");
				acertos ++;
				Sleep(2000);
				quizp4();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp4();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp3();
				break;
			}
            break;
    }
}
void quizp4()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int questao, escolha;
    questao = rand() % 3;
    system("cls");
  	switch (questao) {
        case 0:
            printf("The cake is a lie.\n1) Half Life\n2) Black Mesa\n3) Portal\n4) Bomberman\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou. Agora vamos continuar com os nossos testes...");
				acertos ++;
				Sleep(2000);
				printf("\nde novo e de novo e de novo e de novo");
				Sleep(2000);
				printf("\niremos testar para todo sempre. Você nunca irá sair daqui.");
				Sleep(2000);
				quizp5();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp4();
				break;
			}
            break;
        case 1:
            printf("I used to be an adventurer like you, then I took an arrow in the knee.\n1) Skyrim\n2) Terraria\n3) Assassins Creed Black Flag\n4) Far Cry 3\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nEu costumava acertar essas questões, assim como você... Até que levei uma flechada no joelho.");
				acertos ++;
				Sleep(3000);
				quizp5();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp5();
				break;
			}
            break;
        case 2:
            printf("Escreveu não leu, o pau comeu.\n1) Super Chicken Jumper\n2) Momodora: Moonlit Farewell\n3) Asleep\n4) Mullet Mad Jack\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou... Mas vai ter outra chance de se provar ainda.\n");
				Sleep(2000);
				quizp5();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nVocê acertou! Rapadura é doce, mas não é mole não!\n");
				acertos ++;
				Sleep(2000);
				quizp5();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp4();
				break;
			}
            break;
    }
}
void quizp5()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int questao, escolha;
    questao = rand() % 3;
    system("cls");
    Sleep(2000);
    printf("\nInvasão detectada.");
    Sleep(2000);
    printf(".");
    Sleep(2000);
    printf(".");
    Sleep(2000);
    printf("\nO seu dispositivo pode ter sido invadido por hackers. Execute o Windows Defender ou outro software de proteção o mais rápido possível.");
    Sleep(4000);
    printf("\nA dificuldade do jogo foi alterada.");
    Sleep(2000);
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
    Sleep(2000);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\nIniciando última questão. Dificuldade: Impossível\nValor: 2 Pontos");
    Sleep(5000);
    system("cls");
  	switch (questao) {
        case 0:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        	Sleep(1000);
        	printf("		BENDITA LIBERDADE! MINHA PERNA!\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\n\n      Qual é o nome do jogo?\n        1) Noita 2\n        2) Magicka 2: Learn to Spell Again!\n        3) Warhammer 40,000: Rogue Trader\n        4) Helldivers 2\n        5) Wall World\n        6) Celeste\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\n        VOCÊ ESTÁ FORA DE SEU UNIFORME, HELLDIVER! ONDE ESTÁ A SUA CAPA!?");
				Sleep(2000);
				printf("\n        NÃO TEM NENHUMA!? VOCÊ ESPERA QUE EU ACREDITE NISSO, SEU VERME!?");
				acertos += 2;
				Sleep(3000);
				resultado();
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp5();
				break;
			}
            break;
        case 1:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        	Sleep(1000);
        	printf("		Cheeki Breeki\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\n\n      Qual é o nome do jogo?\n        1) Pathologic 2\n        2) Iv Damke\n        3) Who is Lila?\n        4) Intravenous\n        5) Miside\n        6) S.T.A.L.K.E.R\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Não tá bem errado, mas tinha uma resposta bem melhor.\n");
				Sleep(3000);
				acertos ++;
				resultado();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n        Você errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\n        Good hunt, Stalker.\n");
				acertos += 2;
				Sleep(3000);
				resultado();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp5();
				break;
			}
            break;
        case 2:
        	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        	Sleep(1000);
        	printf("		STATUS UPDATE:\n");
        	Sleep(1000);
        	printf("		MACHINE ID:               V1\n");
        	Sleep(1000);
        	printf("		LOCATION:                 APPROACHING HELL\n");
        	Sleep(1000);
        	printf("		CURRENT OBJECTIVE:        FIND A WEAPON\n");
        	Sleep(1000);
        	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("		MANKIND IS DEAD\n");
            Sleep(1000);
            printf("		BLOOD IS FUEL\n");
            Sleep(1000);
            printf("		HELL IS FULL\n");
            Sleep(2000);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\n\n      Qual é o nome do jogo?\n        1) Doom Eternal\n        2) Quake\n        3) Ultrakill\n        4)Devil May Cry\n        5) Serious Sam\n        6) Wolfenstein\n");
            scanf("%i", &escolha);
            switch(escolha)
			{
			case 1:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nQuanto orgulho. Parabéns.\n");
				acertos += 2;
				Sleep(3000);
				resultado();
				break;
			case 4:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 5:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nVocê errou. Era esperado.\n");
				Sleep(2000);
				resultado();
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\nEin? Acho que isso não era uma opção. Vamo refazer isso aqui então.");
				Sleep(2000);
				quizp5();
				break;
			}
            break;
    }
}
void resultado()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);	
	int start;
	system("cls");
	printf("E era isso! Sua pontuação final foi: %i/5 acertos!", acertos);
	Sleep(3000);
	printf("\nDeseja jogar novamente?\n1) Jogar Novamente\n2) Retornar ao Menu Principal\n");
	scanf("%i", &start);
	switch(start)
	{
	case 1:
		quizp1();
		break;
	case 2:
		mainMenu();
		break;
	default:
		break;
	}
	
}

void jogo1() {
	//colorindo o console antes de tudo.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    int start;
    system("cls");
    printf("BEM VINDO!\nEsse será um desafio para testar o quão nerd você é! Deseja começar?\n1) Sim!\n2) Voltar para o menu principal.\n");
    scanf("%i", &start);
    switch(start)
	{
	case 1:
		quizp1();
		break;
	case 2:
		mainMenu();
		break;
	default:
		printf("Acho que você esbarrou no teclado. Vamo tentar de novo.");
		Sleep(2000);
		jogo1();
		break;
	}
}

// --------------------------- Jogo 2: Cobra na Caixa --------------------------- //

void initializeGame(int *buttonBox, int *snakeBox) {
    int positions[] = {1, 2, 3, 4, 5};
    shuffle(positions, 5);
    *buttonBox = positions[0];
    *snakeBox = positions[1];
}

void choosePlayer(Player *players, int *currentPlayerIndex) {
    *currentPlayerIndex = rand() % 2;
    printf("%s começa!\n", players[*currentPlayerIndex].name);
}

int playRound(Player *player, int buttonBox, int snakeBox) {
    int choice;
    printf("%s, escolha uma caixa (1-5): ", player->name);
    scanf("%d", &choice);
    
    if (choice == buttonBox) {
        printf("Parabéns, %s encontrou o botão! Você venceu!\n", player->name);
        return 1;
    } else if (choice == snakeBox) {
        printf("Que azar, %s encontrou a cobra! Você perdeu!\n", player->name);
        return -1;
    }
    return 0;
}

void jogo2() {
    Player players[2];
    int buttonBox, snakeBox, currentPlayerIndex, roundResult;
    
    printf("Jogador 1, insira seu nome: ");
    scanf("%s", players[0].name);
    printf("Jogador 2, insira seu nome: ");
    scanf("%s", players[1].name);
    
    initializeGame(&buttonBox, &snakeBox);
    choosePlayer(players, &currentPlayerIndex);
    
    while (1) {
        roundResult = playRound(&players[currentPlayerIndex], buttonBox, snakeBox);
        if (roundResult != 0) break;
        currentPlayerIndex = 1 - currentPlayerIndex;
    }
}

// --------------------------- Jogo 3: Gousma War --------------------------- //

void initializeGousmaPlayer(GousmaPlayer *player) {
    int i;
    player->gousmaCount = 2;
    for (i = 0; i < player->gousmaCount; i++) {
        player->gousmas[i].fury = 1;
    }
}

void attack(GousmaPlayer *attacker, GousmaPlayer *defender, int attackerIndex, int defenderIndex) {
    defender->gousmas[defenderIndex].fury++;
    printf("Ataque! A Gousma %d do oponente agora tem %d de fúria!\n", defenderIndex + 1, defender->gousmas[defenderIndex].fury);
}

void splitGousma(GousmaPlayer *player, int gousmaIndex, int furyToTransfer) {
    if (player->gousmaCount < MAX_GOUSMAS && player->gousmas[gousmaIndex].fury > furyToTransfer) {
        player->gousmas[gousmaIndex].fury -= furyToTransfer;
        player->gousmas[player->gousmaCount].fury = furyToTransfer;
        player->gousmaCount++;
        printf("Nova Gousma criada com %d de fúria!\n", furyToTransfer);
    }
}

int checkDefeat(GousmaPlayer *player) {
    int i;
    for (i = 0; i < player->gousmaCount; i++) {
        if (player->gousmas[i].fury < 5) return 0;
    }
    return 1;
}

void displayStatus(GousmaPlayer *player1, GousmaPlayer *player2) {
    int i;
    printf("\nEstado das Gousmas:");
    printf("\nJogador 1: ");
    for (i = 0; i < player1->gousmaCount; i++) {
        printf("[%d] ", player1->gousmas[i].fury);
    }
    printf("\nJogador 2: ");
    for (i = 0; i < player2->gousmaCount; i++) {
        printf("[%d] ", player2->gousmas[i].fury);
    }
    printf("\n");
}

void jogo3() {
    GousmaPlayer player1, player2;
    int turn = 0, attackerIndex, defenderIndex, action;
    
    initializeGousmaPlayer(&player1);
    initializeGousmaPlayer(&player2);
    
    while (1) {
        displayStatus(&player1, &player2);
        
        printf("Jogador %d, escolha uma ação (0 = Atacar, 1 = Dividir): ", turn + 1);
        scanf("%d", &action);
        
        if (action == 0) {
            printf("Escolha sua Gousma atacante: ");
            scanf("%d", &attackerIndex);
            printf("Escolha a Gousma do oponente para atacar: ");
            scanf("%d", &defenderIndex);
            attack(turn ? &player2 : &player1, turn ? &player1 : &player2, attackerIndex, defenderIndex);
        }
        
        if (checkDefeat(&player1) || checkDefeat(&player2)) {
            printf("Jogador %d perdeu!\n", checkDefeat(&player1) ? 1 : 2);
            break;
        }
        turn = 1 - turn;
    }
}

// --------------------------- Menu Principal --------------------------- //

void mainMenu() {
    int choice;
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    do {
        printf("\nTUTTI GIOGO\n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa!\n");
        printf("3 - Gousma War\n");
        printf("4 - Sair\n");
        printf("Escolha um jogo: ");
        scanf("%d", &choice);
        
        switch (choice) {
        	case 1:
        		jogo1();
        		break;
            case 2: 
				jogo2(); 
				break;
            case 3: 
				jogo3(); 
				break;
        }
	//While serve como botão de sair ao finalizar todas as ações.
    } while (choice != 4);
}

//Seta tudo que é de menor importância e então vai pro menu.
int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
    srand(time(NULL));
    mainMenu();
    return 0;
}
