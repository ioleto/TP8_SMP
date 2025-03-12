/**
 * @file ours.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef OURS_H
#define OURS_H

#include "animal.h"
#include <iostream>

using namespace std;

class Ours : public Animal
{
    public:
        /* Constructeur */
        Ours(int maxX, int maxY);
        Ours(int maxX, int maxY, int a, int b);

        /* Destructeur */
        ~Ours();

        /* Méthodes */
        void setAttaque();
        void deplace(int maxX, int maxY);
};