#ifndef TP1_PILE_H
#define TP1_PILE_H

#endif //TP1_PILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_PILLE 1024
#define TAILLE_CHAINE 1024


struct Pile{
    char stack[TAILLE_PILLE][TAILLE_CHAINE];
    int pos;
};

struct Pile* pileInit();
char* pilePop(struct Pile *pile);
void pilePush(struct Pile *pile, char *string);
char* pileTop(struct Pile *pile);
int pileSize(struct Pile *pile);