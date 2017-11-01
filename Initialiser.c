#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Initialiser.h"


void initialiser_plateau(Plateau* p, int taille)
{
    int i;
    for (i = 1; i <= taille*taille; ++i)
    {
        (p[i]).couleur = Gris;
    }
}


void afficherPlateau(Plateau* hex, int taille) {
    int longueur_tab = (taille) * (taille);
    for (int i = 1; i <= longueur_tab; i++) {
            if (hex[i].couleur == Rouge) {
                printf(" R ");
            }
            else if (hex[i].couleur == Bleu) {
                printf(" B ");
            }
            else if (hex[i].couleur == Gris) {
                printf(" * ");
            }
            else {
                printf("ERROR AFFICHAGE!\n");
            }
            if((i%taille+1) == 1){
                printf("\n");
                for(int j = i/taille; j > 0; j--) {
                    printf("  ");
                }
            }
        
        }
}

