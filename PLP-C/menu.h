// Menu Functions
// Declarações para o Menu

_Bool usedCheck(char guess, char* word, char* correct, _Bool containsGuess);
void encryptWord(char *word, int option, char category[20]);
void switchHelp(int option, char* word, char* correct);
void renderMenu(char* correct, char* word);
void getHelp(char* word, char *correct);
char typeGuess(char guess);
void displayTitle();
void clrscreen();
void resetGame();
void throwLose();
void throwSave();
int numErros();