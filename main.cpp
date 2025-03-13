/*
 * Eloi Tourangin
 * TP8
 * Le but de ce TP est d’écrire les bases d’un mini jeu de vie artificielle.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "partie.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    
    Partie PartieTest(10, 10);
    while(PartieTest.getNbAnimaux() > 1)
    {
        PartieTest.tourDeJeu();
        PartieTest.afficherPlateau();
    }

    return 0;
}