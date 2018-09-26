#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dollDraw.h"
#include "cripto_functions.h"

struct gameConfig {
	int attemps;
	int currentLevel;
	word *currentWord;
}

struct gameConfig Match;

typedef struct Word {
	int level;
	char* text;
} word;

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
vector<word> words;
vector<word> exampleWords;
vector<cipherType> cipherTypes;

/*** prototypes ***/
void selectDifficulty(int level);
void resetMatch();
void clrscreen();
int userInput();

int userInput() {
	int selected;
	gets( selected );

	return selected;
}

void clrscreen() {
	system('clear');
}

void resetMatch() {
	Match.attemps = 0;
	Match.currentLevel = NULL;
	&Match.currentWord = NULL;
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

/*
void initGame() {
	int difficulty = selectDifficulty(userInput());
	startMatch(difficulty);
} >> "main"
*/ 

void startMatch(int level) {
	resetMatch();
	Match.level = level;
	&Match.currentWord = NULL; //???
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
