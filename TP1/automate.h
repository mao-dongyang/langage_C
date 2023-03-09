#ifndef TP1_AUTOMATE_H
#define TP1_AUTOMATE_H

#endif //TP1_AUTOMATE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pile.h"

enum Etats {
    EtatDeb,
    EtatBalise
}; // énumération des différents états possibles d'avoir dans la fonction changeEtat 

void changeEtat( char c );
void getNextChar(FILE *file);


