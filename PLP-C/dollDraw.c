/*dollDraw.c -- funções pra o desenho do boneco da criptoforca na interface*/
#include <stdio.h>
#include "dollDraw.h"

//desenhos dos vários estágios da forca, de acordo com as vidas restantes
static void printDoll_5_lives();
static void printDoll_4_lives();
static void printDoll_3_lives();
static void printDoll_2_lives();
static void printDoll_1_lives();
static void printDoll_0_lives();

//desenho do final do jogo (derrota)
static void printDoll_dead();

static void printDoll_5_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####            \n");
	printf("||\t####            \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_4_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *o o*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_3_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *o o*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_2_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *o o*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##         |    \n");
	printf("||\t##        /|    \n");
	printf("||\t##       / |    \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_1_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *o o*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##         |    \n");
	printf("||\t##        /|\\  \n");
	printf("||\t##       / | \\ \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##              \n");
	printf("||\t##              \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_0_lives()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *o o*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##         |    \n");
	printf("||\t##        /|\\  \n");
	printf("||\t##       / | \\ \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##        /     \n");
	printf("||\t##       /      \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_dead()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####       *    \n");
	printf("||\t####      ***   \n");
	printf("||\t##       *X X*  \n");
	printf("||\t##       * ^ *  \n");
	printf("||\t##         *    \n");
	printf("||\t##         |    \n");
	printf("||\t##        /|\\   \n");
	printf("||\t##       / | \\  \n");
	printf("||\t##         |    \n");
	printf("||\t##         |    \n");
	printf("||\t##        / \\   \n");
	printf("||\t##       /   \\  \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

static void printDoll_saved()
{
	printf("\n||\n");
	printf("||\t##########***##  \n");
	printf("||\t####           * \n");
	printf("||\t#### *    ***    \n");
	printf("||\t##       *^ ^*   \n");
	printf("||\t## *    \\* - */  \n");
	printf("||\t##       \\ * /   \n");
	printf("||\t##    *   \\|/ *  \n");
	printf("||\t##         |     \n");
	printf("||\t##    *    |   * \n");
	printf("||\t##      *  |     \n");
	printf("||\t##         |     \n");
	printf("||\t##        / \\   \n");
	printf("||\t##       /   \\  \n");
	printf("||========-------__--__---===_--=======--__==\n");
}

void printDoll_state(int nextState)
{
	switch (nextState)
	{
	case 0:
		printDoll_5_lives();
		break;

	case 1:
		printDoll_4_lives();
		break;

	case 2:
		printDoll_3_lives();
		break;

	case 3:
		printDoll_2_lives();
		break;

	case 4:
		printDoll_1_lives();
		break;

	case 5:
		printDoll_0_lives();
		break;

	case 6:
		printDoll_dead();
		break;
	case 7:
		printDoll_saved();
		break;

	default:
		printf("Exception: Invalid state");
	}
}

void printTuring()
{
	printf("\n\n\tO===================================================O\n\t||....................-:/ooo///:-...................||\n\t||..................:oddyhmdhdmmmho---..............||\n\t||................/syddyymmmmNNMMMMNy:-.............||\n\t||..............:oo/:++osyhddmNMMMMMMN+-............||\n\t||.............:o+-.......-:::/+shmNNMMy-...........||\n\t||............-s:...........---:/++oohmN-...........||\n\t||............:/-............-:/+oooshdN/...........||\n\t||............::-://:------.--:/+oosyddm:...........||\n\t||............-:/+oyyhhs+/::+syhhhhhhddd-...........||\n\t||..........::-::/yhsos/-:+hmNNmmmmmmdmo............||\n\t||..........:.-------:----oyyyhsdmdddddsh/..........||\n\t||..........--o:-..--..---+yso+oossyhddyh+..........||\n\t||...........----...-.:o+yddyooossyhdhhyo...........||\n\t||............------.--:+shhyoossydddhys-...........||\n\t||.............----:/://++syhhyyyhddhs:.............||\n\t||.............-:::/o++osyhdddhhhddd/...............||\n\t||.--.........-:/::/:-:+yyyyyyyddddh-......--.......||\n\t||....-.-...---/++///:-://osyhdmmmm:...-.---.-.....-||\n\t||-----------/+++osssossyhddmmNNNmh-.---------...--.||\n\t||---------:+oo++osssydNMMMMMMNNNNh---------------.-||\n\t||------:///+oosooosyysydNMMMNNNNmds----------------||\n\t||-:::////+oosoosyyyysssshdmmddmmmNmd:--------------||\n\t||////++++osssysossyyyysossyhhymNmmmmdo+:-----------||\n\t||/+++++oossyyhysooshhhhyysssydmmmhddmmhhys+--------||\n\t||++/++++osyhhddhyssshdddhhyysyhmmhhddmmhhhhy:------||\n\t||ooosoosssyhhddddhhhdmmmddddhyyydmddddmmdhddy:-----||\n\t||sssoosyhhhhhddmmmmmmmdddmmddhyhhhmmdddmmdddmy:----||\n\t||oossssssshddddddmNNmmmmmmdmmdhhhhdmmmmmmmddddo--:-||\n\t||oooosyyyyyyhmmmddmmNNmmmmmmmmdhhhhddmmmNNmdddh/::-||\n\t||ssyyysssyyyhhhdmmdmmmNNmmmmmmdddhhhhdmmNNmddmmh:::||\n\tO===================================================O\n\n");
}

void printLogo()
{
printf("||\n||\n||\n||\t   ██████╗██████╗  ██╗██████╗ ████████╗ ██████╗ ███████╗ ██████╗ ██████╗  ██████╗██╗  ██╗\n||\t  ██╔════╝██╔══██╗███║██╔══██╗╚══██╔══╝██╔═████╗██╔════╝██╔═████╗██╔══██╗██╔════╝██║  ██║\n||\t  ██║     ██████╔╝╚██║██████╔╝   ██║   ██║██╔██║█████╗  ██║██╔██║██████╔╝██║     ███████║\n||\t  ██║     ██╔══██╗ ██║██╔═══╝    ██║   ████╔╝██║██╔══╝  ████╔╝██║██╔══██╗██║     ╚════██║\n||\t  ╚██████╗██║  ██║ ██║██║        ██║   ╚██████╔╝██║     ╚██████╔╝██║  ██║╚██████╗     ██║\n||\t   ╚═════╝╚═╝  ╚═╝ ╚═╝╚═╝        ╚═╝    ╚═════╝ ╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝     ╚═╝\n");

}