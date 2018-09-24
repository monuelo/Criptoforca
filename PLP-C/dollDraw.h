/*dollDraw.h -- constantes e declarações para dollDraw.c*/


//desenhos dos vários estágios da forca, de acordo com as vidas restantes
void printDoll_5_lives(void);
void printDoll_4_lives(void);
void printDoll_3_lives(void);
void printDoll_2_lives(void);
void printDoll_1_lives(void);
void printDoll_0_lives(void);

//desenho do final do jogo (derrota)
void printDoll_dead(void);

//chamada da função adequada para desenhar na tela
void printDoll_state(int nextState);
