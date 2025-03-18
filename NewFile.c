
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define NUM_BOXES 5 
#define NUM_NAMES 7
#define MAX_GOUSMAS 2 
#define MAX_FURY 5

int i, j, temp;
int playAgain;

const char *names[NUM_NAMES] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace"};

typedef struct { const char *name; int isPlaying; } Player;

void shuffle(int *array, int n) { for (i = n - 1; i > 0; i--) { j = rand() % (i + 1); temp = array[i]; array[i] = array[j]; array[j] = temp; } }

void initializeGame(int *buttonBox, int *snakeBox) { int positions[NUM_BOXES] = {0, 1, 2, 3, 4}; shuffle(positions, NUM_BOXES); *buttonBox = positions[0]; *snakeBox = positions[1]; }

void choosePlayer(Player *players, int *currentPlayerIndex) { *currentPlayerIndex = rand() % 2; printf("Jogador %s começará!\n", players[*currentPlayerIndex].name); }

void playRound(Player *player, int buttonBox, int snakeBox) { int choice; printf("%s, escolha uma caixa (1 a 5): ", player->name); scanf("%d", &choice); choice--; // Adjusting for 0-based index

if (choice == buttonBox) {
    printf("Parabéns %s! Você encontrou o botão e venceu o jogo!\n", player->name);
    player->isPlaying = 0;
} else if (choice == snakeBox) {
    printf("Que pena %s! Você encontrou a cobra e perdeu o jogo!\n", player->name);
    player->isPlaying = 0;
} else {
    printf("Caixa %d está vazia. O jogo continua!\n", choice + 1);
}
}

void jogo1() { printf("Pergunta e Resposta has been selected\n"); }

void jogo2() { printf("Cobra na Caixa! has been selected\n");

srand(time(0));

Player players[2];
int buttonBox, snakeBox;
int currentPlayerIndex;

printf("Escolha um nome para o jogador 1:\n");
for (i = 0; i < NUM_NAMES; i++) {
    printf("%d. %s\n", i + 1, names[i]);
}
int choice;
scanf("%d", &choice);
players[0].name = names[choice - 1];
players[0].isPlaying = 1;

printf("Escolha um nome para o jogador 2:\n");
for (i = 0; i < NUM_NAMES; i++) {
    printf("%d. %s\n", i + 1, names[i]);
}
scanf("%d", &choice);
players[1].name = names[choice - 1];
players[1].isPlaying = 1;

choosePlayer(players, &currentPlayerIndex);

while (players[0].isPlaying && players[1].isPlaying) {
    initializeGame(&buttonBox, &snakeBox);
    playRound(&players[currentPlayerIndex], buttonBox, snakeBox);
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

printf("Deseja jogar novamente? (1 - Sim, 0 - Não): ");
scanf("%d", &playAgain);
if (playAgain) {
    jogo2();
} else {
    printf("Retornando ao menu principal...\n");
}
}

typedef struct { int fury; int active; } Gousma;

typedef struct { Gousma gousmas[MAX_GOUSMAS]; } GousmaPlayer;

void initializeGousmaPlayer(GousmaPlayer *player) { for (i = 0; i < MAX_GOUSMAS; i++) { player->gousmas[i].fury = 1; player->gousmas[i].active = 1; } }

void attack(GousmaPlayer *attacker, GousmaPlayer *defender, int attackerIndex, int defenderIndex) { if (attacker->gousmas[attackerIndex].active && defender->gousmas[defenderIndex].active) { defender->gousmas[defenderIndex].fury += attacker->gousmas[attackerIndex].fury;

    if (defender->gousmas[defenderIndex].fury > MAX_FURY) {
        defender->gousmas[defenderIndex].active = 0;
        printf("Gousma do jogador defensor se desintegrou!\n");
    }
}
}

void splitGousma(GousmaPlayer *player, int gousmaIndex, int furyToTransfer) { if (player->gousmas[gousmaIndex].active && player->gousmas[gousmaIndex].fury > furyToTransfer) { for (i = 0; i < MAX_GOUSMAS; i++) { if (!player->gousmas[i].active) { player->gousmas[i].fury = furyToTransfer; player->gousmas[i].active = 1; player->gousmas[gousmaIndex].fury -= furyToTransfer; break; } } } }

int checkDefeat(GousmaPlayer *player) { for (i = 0; i < MAX_GOUSMAS; i++) { if (player->gousmas[i].active) { return 0; } } return 1; }

void displayStatus(GousmaPlayer *player1, GousmaPlayer *player2) { printf("Status do Jogador 1:\n"); for (i = 0; i < MAX_GOUSMAS; i++) { if (player1->gousmas[i].active) { printf("Gousma %d: Furia %d\n", i + 1, player1->gousmas[i].fury); } else { printf("Gousma %d: Desintegrada\n", i + 1); } }

printf("Status do Jogador 2:\n");
for (i = 0; i < MAX_GOUSMAS; i++) {
    if (player2->gousmas[i].active) {
        printf("Gousma %d: Furia %d\n", i + 1, player2->gousmas[i].fury);
    } else {
        printf("Gousma %d: Desintegrada\n", i + 1);
    }
}
}

void jogo3() { printf("Gousma War has been selected\n");

GousmaPlayer player1, player2;
initializeGousmaPlayer(&player1);
initializeGousmaPlayer(&player2);

int choice;
while (1) {
    displayStatus(&player1, &player2);

    printf("Jogador 1, escolha sua ação (1: Atacar, 2: Dividir): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int attackerIndex, defenderIndex;
        printf("Escolha sua Gousma atacante (1 ou 2): ");
        scanf("%d", &attackerIndex);
        printf("Escolha a Gousma do adversário para atacar (1 ou 2): ");
        scanf("%d", &defenderIndex);
        attack(&player1, &player2, attackerIndex - 1, defenderIndex - 1);
    } else if (choice == 2) {
        int gousmaIndex, furyToTransfer;
        printf("Escolha a Gousma para dividir (1 ou 2): ");
        scanf("%d", &gousmaIndex);
        printf("Quantidade de fúria a transferir: ");
        scanf("%d", &furyToTransfer);
        splitGousma(&player1, gousmaIndex - 1, furyToTransfer);
    }

    if (checkDefeat(&player2)) {
        printf("Jogador 1 venceu!\n");
        break;
    }

    displayStatus(&player1, &player2);

    printf("Jogador 2, escolha sua ação (1: Atacar, 2: Dividir): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int attackerIndex, defenderIndex;
        printf("Escolha sua Gousma atacante (1 ou 2): ");
        scanf("%d", &attackerIndex);
        printf("Escolha a Gousma do adversário para atacar (1 ou 2): ");
        scanf("%d", &defenderIndex);
        attack(&player2, &player1, attackerIndex - 1, defenderIndex - 1);
    } else if (choice == 2) {
        int gousmaIndex, furyToTransfer;
        printf("Escolha a Gousma para dividir (1 ou 2): ");
        scanf("%d", &gousmaIndex);
        printf("Quantidade de fúria a transferir: ");
        scanf("%d", &furyToTransfer);
        splitGousma(&player2, gousmaIndex - 1, furyToTransfer);
    }

    if (checkDefeat(&player1)) {
        printf("Jogador 2 venceu!\n");
        break;
    }
}
}

void jogo4() { printf("Game has been shut down\n"); }

int main() { int escolha;

printf("       TUTTI GIOGO         \n");

while (1) {
    printf("Select your game:\n");
    printf("1. Pergunta e Resposta:\n");
    printf("2. Cobra na Caixa!:\n");
    printf("3. Gousma War:\n");
    printf("4. Sair:\n");
    printf("Type your game: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            jogo1();
            break;
        case 2:
            jogo2();
            break;
        case 3:
            jogo3();
            break;
        case 4:
            jogo4();
            return 0;
        
    }
}

return 0;
}