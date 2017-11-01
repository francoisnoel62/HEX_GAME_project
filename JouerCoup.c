#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Initialiser.h"
#include "Lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#define LONGUEUR_CHAINE 4


void jouerCoup (int *positionX, int *positionY, Plateau* hex, int taille) {
    char userInput_X[LONGUEUR_CHAINE];
    char userInput_Y[LONGUEUR_CHAINE];
    
    do {
        //accueil
        printf("\n**************************************************\nVous devez choisir une case valide pour jouer !\n");
        printf("Choisissez ses coordonnes.\n");
        
        //saisie de la ligne
        printf("Quelle colonne de 1 à %i ?\n", taille);
        lire(userInput_X, sizeof(userInput_X));
        *positionX = (int)strtol(userInput_X, NULL, 10);
        
        //saisie de la colonne
        printf("Quelle ligne de 1 à %i ?\n", taille);
        lire(userInput_Y, sizeof(userInput_Y));
        *positionY = (int)strtol(userInput_Y, NULL, 10);
        
        int indice = *positionX + (*positionY-1)*(taille);
        
        //Structure de controle des valeurs dex coordonnees entrées par l'utilisateur.
        if((*positionX <= 0 || *positionX > taille) || (*positionY <= 0 || *positionY > taille)) {
            printf("********************************************\nVous avez entre de mauvaises coordonnes.\n");
            printf("Les coordonnes des cellules sont comprises entre 1 et %i.\n", taille);
            //sleep(1);
        } else if(hex[indice].couleur != Gris){
            printf("**************************************************\nImpossible. La case est déjà prise !! Try again...\n");
            printf("**************************************************\n");
            //sleep(1);
        } else {
            printf("Vous avez choisi la position : %i pour la colonne et %i pour la ligne.\n", *positionY, *positionX);
            printf("Cette position est libre, votre coup est enregistré. Bravo !\n\n");
            //sleep(1);
        }
    } while (*positionX <= 0 || *positionX > taille || *positionY <= 0 || *positionY > taille);
}
