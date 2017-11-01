#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "initialiser.h"
#include "testVoisin.h"

void init_Test_Voisin(Plateau* hex, int joueur, int taille)
// on crÈe la variable permettant de vÈrifier qu'on teste pas 2 fois la mÍme case dans une mÍme chaÓne
// et on teste si une des cases du haut est bleue ou une des cases de gauche est rouge.
// si oui, on lance la fonction de test des voisins
{
    (hex[6]).couleur = Bleu; (hex[7]).couleur = Bleu; (hex[17]).couleur = Bleu; // ligne permettant de tester la fonction
    int i, resultat = 0;
    
    int* memoire = NULL;
    memoire = (int*)malloc(((taille*taille)/2) * sizeof(int));   // On alloue ‡ la mÈmoire une taille de la moitiÈ des cases possibles du tableau (pas possible pour une couleur d'avoir plus que la moitiÈ des cases occupÈes)
    init_Memoire(memoire, taille);
    
    
    switch (joueur) // si joueur rouge, on teste les cases de gauche. Si joueur bleu, on teste celle du haut
    {
        case 1:
            for (i = 0; i < taille - 1; ++i)
            {
                if ((hex[i]).couleur == Bleu)
                {
                    resultat = test_Voisin(hex, i, taille, memoire);
                    printf(" la case %d est bleue\n", i); // ligne permettant de tester la fonction
                }
            }
            
            
            break;
        case 2:
            for (i = 0; (i * taille) < (taille * taille) - taille + 1 ; ++i)
            {
                if ((hex[i]).couleur == Rouge)
                {
                    resultat = test_Voisin(hex, i, taille, memoire);
                }
            }
    }
    if (resultat == 1)
    {
        printf("Victory\n");
    }
    else
    {
        printf ("Pas Cool\n");
    }
    free(memoire);
    
}


int test_Voisin(Plateau* hex, int case_testee, int taille, int* memoire)
{
    if (detecter_Fin (hex, case_testee, taille) == true)
    {
        return 1;
    }
    
    else
    {
        int y = 0;
        affecter_Memoire(memoire, case_testee, taille);
        
        y = (case_testee - taille);                    // Test 1 en haut ‡ gauche
        if (!(y < 0))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee - taille + 1);              // Test 2 en haut ‡ droite
        if (!(y < 0) && !(y % taille == taille - 1))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee - 1);                        // Test 3 ‡ gauche
        if (!(y % taille == 0))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + 1);                        // Test 4 ‡ droite
        if (!(y % taille == taille - 1))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + taille - 1);              // Test 5 en bas ‡ gauche
        if (!(y > taille * taille) && !(y % taille == 0))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + taille);                    // Test 6 en bas ‡ droite
        if (!(y > taille * taille))
        {
            if ((hex[y]).couleur == (hex[case_testee]).couleur)
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
    }
    
    
    
    return 0;
}


void init_Memoire (int* memoire, int taille) // On met toutes les valeurs du tableau mÈmoire ‡ - 1 (pas ‡ 0, dans la mesure o˘ on ne sait pas si notre jeu commence ‡ 0 ou ‡ 1)
{
    int i  = 0;
    for (i=0; i < (taille*taille) / 2 ; i++)
    {
        memoire[i] = -1;
    }
}

void affecter_Memoire (int* memoire, int case_testee, int taille) // On remplace la premiËre case inocuppÈe du tableau par la valeur de la case testÈe
{
    int i, j = 0;
    for (i=0; i < (taille*taille) / 2 && j == 0 ; i++)
    {
        if (memoire[i] == -1)
        {
            memoire[i] = case_testee;
            ++j;
        }
    }
}




void desaffecter_Memoire (int* memoire, int taille) // On remplace la derniËre valeur de mÈmoire du tableau par -1
{
    int i, j = 0;
    for (i=0; i < (taille*taille) / 2 && j == 0; i++)
    {
        if (memoire[i] == -1)
            memoire[i-1] = -1;
        ++j;
    }
}

bool detecter_Fin(Plateau* hex, int case_testee, int taille)
// on dÈtecte si la couleur de la case ‡ tester est bleue ou rouge.
// si elle est bleue, on teste s'il s'agit de
{
    int i = 0;
    int j = 0;
    if((hex[i]).couleur == Rouge)
    {
        for (i=0;i<taille;i++)
        {
            j = (taille*(i+1)) - 1;
            if(case_testee==j)
            {
                return true;
            }
        }
    }
    else if ((hex[i]).couleur == Bleu)
    {
        for(i=0; i<taille; i++)
        {
            j=(taille*taille) - (taille + 1) + i;
            if(case_testee==j)
            {
                return true;
            }
        }
    }
    return false;
    
}

bool deja_Tester(int* memoire, int voisin)
{
    int i;
    for (i = 0; memoire[i] != -1; ++i)
    {
        if (memoire[i] == voisin)
            return true;
    }
    return false;
}


