/**
 * @file attaque.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <iostream>

using namespace std;

class Attaque
{
    public:
        /* Constructeurs */
        Attaque();  // crée une attaque aléatoire
        Attaque(int a); // crée une attaque spécifique

        /* Destructeur */
        ~Attaque();

        /* Méthodes */
        const int getTypeAttaque();
        const bool resoudreAttaque(Attaque &a);
        const string getNomAttaque();        

    private:
        /* Variable */
        int type; // 0 :pierre, 1: Feuille, 2:Ciseaux
};