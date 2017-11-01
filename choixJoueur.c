
#include "choixJoueur.h"

void changerJoueur(int* joueur) {
    if(*joueur == 1) {
        *joueur = 2;
        printf("Le joueur ROUGE joue maintenant.\n");
    } else if(*joueur == 2) {
        *joueur = 1;
        printf("Le joueur BLEU joue maintenant.\n");
    }
}
