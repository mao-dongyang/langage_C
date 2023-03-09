#include "pile.h"

struct Pile* pileInit(){
    struct Pile *pile = malloc(sizeof(*pile));
    pile->pos = -1;
    return pile;
} // Initialisation de la pile


char* pilePop(struct Pile *pile){
    if(pile->pos == -1){
        printf("pilePop : ERROR PILE VIDE");
        return NULL;
    } // si pos = -1, cela signifie que la pile est vide, donc on ne peut pas retirer d'éléments de la pile
    pile->pos--; // on décrémente pos car on va retirer le dernier élément, donc la taille de la pile va diminuer
    return pile->stack[pile->pos+1]; // on retire le dernier élément
}

void pilePush(struct Pile *pile, char *string){
    if(pile->pos == TAILLE_PILLE){
        printf("pilePush : ERROR PILE PLEINE");
    } // si la taille de la pile est égale à la valeur dans pos, la pile est pleine, on ne peut donc pas ajouter d'éléments dedans
    else {
        pile->pos++;
        strcpy(pile->stack[pile->pos], string);
    } // sinon, on incrémente pos et on ajoute l'élément demandé grâce à la fonction strcpy
}

char* pileTop(struct Pile *pile){
    return pile->stack[pile->pos];
} // renvoie la dernière valeur de la pile

int pileSize(struct Pile *pile){
    return pile->pos;
} // retourne la taille actuelle de la pile
