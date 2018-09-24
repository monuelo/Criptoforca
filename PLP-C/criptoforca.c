#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void printDoll_5_lives(void);
void printDoll_4_lives(void);
void printDoll_3_lives(void);
void printDoll_2_lives(void);
void printDoll_1_lives(void);
void printDoll_0_lives(void);
void printDoll_dead(void);

void printDoll_5_Lives(void)
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



int main(void) {



	switch (desenho) {
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
	}















	/*hhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysyyyyssssyyhhddddddmmmmddddhhhhyyysssssssyyyyyyyyyhhhhhhhhhhhhhh
		hhhyhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysssssshdmNNNNmmmmmmmmmmdddddmmmddddhysssssyyyyyyyyhhhhhhhhhhhhhh
		yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyssssssydmNNNmmNmmmmmmmddmdddddddmmmmmNNNNdyysyyyyyyyyhhhhhhhhhhhhhh
		yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysssssyhmmNNNNNNNNNNNNNmmmmmNNNmmmmmmmNNNNMMNdyyyyyyyyyhhhhhhhhhhhhhh
		yyyyyyyyyyyyyyyyyyyyyyyyyyyssssssssydNNNNNNNNNNNNNNNmmmmddddmmmmNNNNNNNNNNMMMdyyyyyyyyhhhhhhhhhhhhhh
		hyyyyyyyyyyyyyyyyyyyyyyyyssssssssydmNNMMMMNNNNNNNNNNmmmddddddddmmmNNNNNNMMMMMmyyyyyyyyyyhhhhhhhhhhhh
		yyyyyyyyyyyyyyyyyyyyyyyysssssssshmNMMMMMMMMMMMNNNNNNNmmddhdddmmmmmmNNMMMMMMMMNdyyyyyyyyyhyhhhhhhhhhh
		hhhhyyyyyyyyyyyyyyyyyyyyssssssymNMMMMMMMMMMMMMMNNNNmmddddddddmmmmNNNNNNMMNmmNNmdhyyyyyyyyyhhhhhhhhhh
		hhhhyyyyyyyyyyyyyyyyyyyysssssdNMMMMMMMMMMMMMMMNNNNNmmddddddddmmNNNNNMNMMNmdmdddddhyyyyyyyyyhhhhhhhhh
		hhhyyyyyyyyyyyyyyyyyyyyysssssNMMMMMMMMMMMMMMMMNNNNNmmdddddddmmNNNNNNMMMNdmmmhhdmmdhyyyyyyyyyhhyyhhhy
		hhhhhyyyyyyyyyyyyyyyyyyyssssyMMMMMMMMMMMMMMMMMMNNNNmmddddddddmNNNNNNNmdhhddddddmdddhsyyyyyyyyyyyhhyy
		hhhhhyyyyyyyyyyyyyyyyyyysssshMNMMMMMMMMMMMMMNNNNmmmdddhhhyyyyhhhddhhysoyyhhddhdddmmmyssyyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyyyyyyssssmNddmNNNmmmmddhyyysssssssoo++ +/////+++++///+syhdhhddmmNNdysyyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyyyyyyssssNmyyyyysoooooo++++++ +//////:::::::::::::::/+oyddhdddmNNNNyssyyyyyyyyyyyy
		hhyyyyyyyyyyyyyyyyyyyyyysssyNhsssoo++++////////////::::::::::::::::::///+yddddNmmNNNMysssyyyyyyyyyyy
		hhyyyyyyyyyyyyyyyyyyyyyssssymyssooo++ +////////////::::::::::::::::::////+sdmNmNNNNNMMysssyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyyyysssssshyyssoo++ +///////////::::::::::::::::::////+oshmNMMMMMMMNssssyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyysyssssssshmNmmmdhso + / +//////////::::::::::::::::////++oydNNNMMMMMMhssssyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyssysssssdNNNNNNMNNmhyo++ +/////////:::::::::::::::///++shmNNNMMMMMNyssssyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyyssssssNNNNNNNNNMMMNmhso++++ + ooosyyyyyyyssoo +///////+ohdmmNNNMNMdssyssyyyyyyyyyyy
		yyyyyyyyyyyyyyyysyysysssssmmmNNMMNMMMMMNNmyo++oshdmNNNNNmmmddhyyyso////++oydmmNNNNmyssssyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyysssssssssddhdmNNdmNNNNNNms +///+sydmmNNNmddddhhyyyyo+//+/+ydmmmNNNhssssyyyyyyyyyyyyy
		yyyyyyyyyyysyyyyyyyysssssshhyyyyyyyyyyhhdy + / ::: / +oydNNmNNNdhhdmhyyys++ + / +oddddmmhsoosssyyyyyyyyyyyyy
		yyyyyyyyyyysssssssssysssssyysoossosooooso + / :::::: / +osyyyhhshddddhsso++++ + sddhys++syyssyyyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyysysssssyyso + oo + oo++ + o//:::::::://+++ooo++++++oo+++++++yhsooyy+ohNNsssyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyysssssshso++++++++ + o / :::::::::::: :////////////////+++oyosyho+//odmsyyyyyyyyyyyyyy
		hyyyyyyyyyyyyyyyyyyysssssshyoo++++ + / +oo//::::::::::::::://///////////++++++hNMmd+/oysysyyyyyyyyyyyyy
		hyyyyyyyyyyyyyyyyyyssssssshhysooo++ + hmmyso++ + / : -:: / :::::::::::: ://///++++/+sshdh++ossyyyyyyyyyyyyyyy
		yyyyyyyyyyyyyyyyyyysssssssydhyssooooymNNmdhhdmdo / ::///::::::::::////+//+/+osoooo+osssssssssyyyyyyyyy
		yyyyyyyyyyyyyyyyyyyyyyssssydhyssoooosyhdmdhsooo + / :: :////::::::::///++//+++//+osoosyssssssyysyyyyyyyy
		hhyyyyyyyyyyyyyyyyyyysssssydhhysooooooossso +//:::::::////////////////////////+ssssyssssssssssyyyyyyy
		hhhhyyyyyhhyyyyyyyyysssssssddhhhddhyyys +////:::::::::://+//////////////++//+osssssssssssssssssyyyyyy
		hhhhhhyyhhhyyyyyyyyyysssssshdhhhdmmNNmNmdhhhso + / :: ://////++++++///////osssssssssssssssssssssssyyyyyy
		hhhhhhhhhhhyyyyyyyyyyssssssydhysysyddyyyyhhhyyyyyyyyo/////+++++//+++++ssssssssssssssssssssssyyyysyyy
		hhhhhhhhhyyhyyyyyyyyyyssssssdhysssyhdmmmdhyso++///+oo++///+++++++++++sssssssssssssssssssssssyyysssss
		hhhhhhhhyhhyyyyyyyyyyyssssssymhssossyyhhddhhso +//////++++/+++++++++osyssssssssssssssssssssssyyyyyyyy
		hhhhhhhhhhyyhhhhyyyyyysssssssmhys + oo++++++++ +///::////++++++++++++osdmyssssssssssssssssssssssyyyyyyy
		ddhhdhhhhhhyyyyhyyyyysssssssdMNdhsoo +///:::::::::::///+++++++++ooss/ymmyooossssssssssssssssssyyyyyyy
		ddddddhhhhhhhyyyyyyyyssssyhmMMdsmmdhso++//:::::::::///++++ooooooso/-ymmmhsooooossssssssssssssysyyyyy
		ddddddhhhhhhhhyyyyyssssymNMMMMy / ohmNmdhyyso +///////+++++ooooooo+/:-:ddmmmmdyysoosssssssssssssysyyyyy
		ddddhdhhhhhhhhyyyyyhdmNMMMMMMMh / ++ohNNNNmmdhyysoooooosssooooo + / :-- - oddmmmmmmmmdhysoossssssssssssyyyy
		dddddddhhhhhhhhdmNNMMMMMMMMMMMm///++sdNNNNNNNmmdhhhyyssooo++/:----:hddmmmmmmmmmmmmdhysoossssssssssyy
		dddhdddhhhhdmNNMMMMMMMMMMMMMMMNo////++ohmNNNNNmdhysooo+++/:-------ohhdmmmmmmmmmmmNNmmdyssoosssssssyy
		dddddmmmNNNMMMMMMMMMMMMMMMMMMMMy//////+++oydmNmdyyso+++:---------:ydhdmmmmmmmmmmmmNNNmmddhyyssssssss
		NNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMd//////////:/+yyhyyo+::-----------ohdddmmmmmmmmNmmmNNNNNmmmmdmmdhyyss
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo//////::::odmdddds/------------/hdddmmmmmmmmmNNmmmNNNNNNNmmmmmmmmdh
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNy///:::::+hmNMMNmmmmy:---------:yddddmmmmmmmmmNNNmmNNNNNNNNNmmmmmmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNd + ::::: / sddydMNmmdysys : --------odddddmmmmmmmmmNNNmmmNNNNNNNNNNNmmmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmo:::: + hmmddNNNmh / :: + yy + ------ + hdddmmmmmmmmmmmNNNmmmNNNNNNNNNNNmmmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNs / : / +ooyhdNNNNNh:: : / oyho---- / ydddmmmmmmmmmmmmNNNmNNmNNNNNNNNNNmmmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNm + oo / : / odNNNNNNy----:: + ho-- : ydddmmmmmmmmmmmmmNNNNNNNmNNNNNNNNNmmmmN
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNdmy///dMNNNmNNdy/----:/oo-odddmmmmmmmmNNmmmNNNNNNNmmNNNNNNNNNNmmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmyhyo + hMNMNNmmNmdd / ---- - / dhddmmmmmmmmmmmNNNmNNmmmNNmmNNNNNNNNNNNmmm
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNo + osdNNNNNmmNNddds---- : odmddmmmmmmmmmmmmNmmmmmmmmmmmmNNNNNNNNNNNNN
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMh//hNNNMNmmddmdddh---:/sdmdmmmmmmmmmmmmmNmNNNmmmmNNNNNNNNNNNNNNNNN
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMNosNNmNNmmmdddddmd / -- / symmmmmmmmmmmmmmNmNNNNNNNmmNNNNNmmNNNNNNNNNN
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMddNNmNNmdddddmmddo - : +ymmmmmmmmmmmmmmmmmNNNNNNNmmNNNNNNNmNNNNmmNNN
		MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNmmNmmdddmmmmmh::smmmmmmmmmmmmNmNmmNNNNNNmNNNmNNNNNNNmmmNNNNNN
		MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNmdddddddmdm++mmmmmmmmmmmmmNNmmmmNNNNNNNNNNNNNmmNNNmmNNNNNN
		MMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMNMNNNmmddmddmmyhNmmmmmmmmmmmmmNNNmmmmmNNNNNNNNNNNNNNNNNNNNNNN*/
