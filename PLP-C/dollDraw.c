/*dollDraw.c -- funções pra o desenho do boneco da criptoforca na interface*/
#include <stdio.h>
#include "dollDraw.h"

void printDoll_5_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####            \n");
	printf("  ####            \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
}

void printDoll_4_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *o o*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
	printf("  ##              \n");
}

void printDoll_3_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *o o*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##              \n");
	printf("  ##              \n");
}

void printDoll_2_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *o o*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##         |    \n");
	printf("  ##        /|    \n");
	printf("  ##       / |    \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##              \n");
	printf("  ##              \n");
}

void printDoll_1_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *o o*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##         |    \n");
	printf("  ##        /|\\  \n");
	printf("  ##       / | \\ \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##              \n");
	printf("  ##              \n");
}

void printDoll_0_lives(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *o o*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##         |    \n");
	printf("  ##        /|\\  \n");
	printf("  ##       / | \\ \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##        /     \n");
	printf("  ##       /      \n");
}

void printDoll_dead(void)
{
	printf("\n\n");
	printf("  ##########***##  \n");
	printf("  ####       *    \n");
	printf("  ####      ***   \n");
	printf("  ##       *X X*  \n");
	printf("  ##       * ^ *  \n");
	printf("  ##         *    \n");
	printf("  ##         |    \n");
	printf("  ##        /|\\   \n");
	printf("  ##       / | \\  \n");
	printf("  ##         |    \n");
	printf("  ##         |    \n");
	printf("  ##        / \\   \n");
	printf("  ##       /   \\  \n");
}

void printDoll_state(int nextState)
{
	switch (nextState) {
	case 0: printDoll_5_Lives();
		break;

	case 1: printDoll_4_lives();
		break;

	case 2: printDoll_3_lives();
		break;

	case 3: printDoll_2_lives();
		break;

	case 4: printDoll_1_lives();
		break;

	case 5: printDoll_0_lives();
		break;

	case 6: printDoll_dead();
		break;

	default: printf("Exception: Invalid state");
	}
}
