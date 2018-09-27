// Menu Functions
// Declarações para o Menu

void switchHelp(int option, char* word, char* correct);
void getHelp(char* word, char *correct);
void displayTitle();
void clrscreen();
void resetGame();
void renderMenu(char* correct, char* word);
char typeGuess(char guess);
bool usedCheck(char guess, char* word, char* correct, bool containsGuess);
int numErros();
void encryptWord(char* word, int option, char* category);