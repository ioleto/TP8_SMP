/**
 * @file animal.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include "attaque.h"
#include <iostream>

using namespace std;

class Animal
{
    protected:
        string nom;
        int x;  // abscisse de l'animal
        int y;  // ordonnée de l'animal
        bool vivant;
        Attaque typeAttaque;

    public:
        /* Constructeur */
        Animal(int maxX, int maxY);
        Animal(int maxX, int maxY, int a, int b);

        /* Destructeur */
        ~Animal();

        /* Méthodes */
        const string getNom();
        const int getX();
        const int getY();
        const bool getVivant();
        void setVivant(bool v);
        const Attaque getAttaque();
        bool Attaque(Animal &a);
        virtual void setAttaque() = 0; // virtuelle pure
        virtual void deplace(int maxX, int maxY) = 0; // virtuelle pure
};