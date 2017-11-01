#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Initialiser.h"
#include "Lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#include "enregistrementCoupJoue.h"


int main()
{
    char user_input[3];
    int joueur;
    int indice = 0;
    int positionX;
    int positionY;
    printf("Veuillez entrer la taille de la grille sur laquelle vous souhaitez jouer ->\n");
    lire(user_input, 4);
    int taille = (int)strtol(user_input, NULL, 10);
    int partie = 10;
    
    Plateau* hex = NULL;
    hex = (Plateau*)malloc((taille*taille) * sizeof(Plateau));
    initialiser_plateau(hex, taille);
    joueur = 1;
    
    while(partie != 0) {

        afficherPlateau(hex, taille);
        jouerCoup(&positionX, &positionY, hex, taille);
        indice = xy2int(positionX, positionY, taille);
        enregistrerCoup(&joueur, hex, taille, indice);

        
        partie--;
        
    }
    
    
    
    free(hex);
    
    return 0;
    
}

