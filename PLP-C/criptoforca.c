#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dollDraw.h"
#include "cripto_functions.h"



struct gameConfig {
	int attemps;
	int currentLevel;
	char* currentWord;
};

struct gameConfig Match;

typedef struct cipherType {
	char* type;
	char* description;
} cipherType;

enum level {
	RASGADO = 1,
	FACIL,
	MEDIO,
	ENIGMA
};

/*** vectors ***/
char* words[0];
char* exampleWords[0];
cipherType cipherTypes[0];

/*** prototypes ***/
void selectDifficulty(int level);
void resetMatch();
void clrscreen();
int userInput();

int userInput() {
	int selected;
	scanf("%d", &selected);
	return selected;
}

void clrscreen() {
	system("clear");
}

void resetMatch() {
	Match.attemps = 0;
	Match.currentLevel = (int) NULL;
	Match.currentWord =  NULL;
}


// Verificar a necessidade deste método...
void selectDifficulty(int level) {
	switch (level) {
		case RASGADO:
			// TODO
			break;
		case FACIL:
			// TODO
			break;
		case MEDIO:
			// TODO
			break;
		case ENIGMA:
			// TODO
			break;
		default:
			// TODO
			break;
	}
}

void getHelp(){
	
	int opc;

	printf("\n\n Selecione uma Dica: ");
			printf("\n\n [1] - Revelar categoria: ");
			printf("\n\n [2] - Revelar uma letra: ");
			printf("\n\n [3] - Ajuda dos Universitários: ");
			printf("\n\n [4] - Quantidade de vogais: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &opc);

}


/*** Dicas ***/

void revealCategory() {
	// TODO	
}

void revealWord() {
	// TODO
}

void undergradHelp() {
	// todo
}

void vowelsNumber() {
	// TODO
}


void countVowelNumber() {
	// TODO
}


void switchHelp(int option) {
	switch(option){
		case 1:
			revealCategory();
		case 2:
			revealWord();
		case 3:
			undergradHelp();
		case 4:
			vowelsNumber();
		default:
			return switchHelp(option);
	}
}

/*
void initGame() {
	int difficulty = selectDifficulty(userInput());
	startMatch(difficulty);
} >> "main"
*/ 

void startMatch(int level) {
	resetMatch();
	Match.currentLevel = level;
}

int main(void) {
	srand(time(NULL));
	//printDoll_state(int state);
	
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
}
