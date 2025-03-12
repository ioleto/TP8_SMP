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

#include "attaque.hpp"
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

        /* Setters */
        void setVivant(bool v);
        virtual void setAttaque() = 0; // virtuelle pure

        /* Getters */
        const string getNom();
        const int getX();
        const int getY();
        const bool getVivant();
        const Attaque getAttaque();

        /* Méthodes */
        bool attaque(Animal &a);
        virtual void deplace(int maxX, int maxY) = 0; // virtuelle pure
};

#endif // ANIMAL_H