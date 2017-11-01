#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Initialiser.h"
#include "Lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#include "enregistrementCoupJoue.h"
#define LONGUEUR_CHAINE 3

//Cette fonction permet de valider et enregistrer le coup tenté par le joueur en cours.
//Elle fait intervenir la fonction "jouerCoup" directement à l'interieur
void enregistrerCoup (int* joueur, Plateau* hex, int taille, int indice) {
    int longueur_tableau = taille*taille;
    for(int i = 1; i <= longueur_tableau; i++) {
            if(i == indice) {
                if(*joueur == 1) {
                    hex[i].couleur = Rouge;
                } else if(*joueur == 2) {
                    hex[i].couleur = Bleu;
                } else {
                    printf("ERROR ENREGISTREMENT\n");
                }
            }
        }
    
}
