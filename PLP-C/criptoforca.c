#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dollDraw.h"



int main(void) {
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
