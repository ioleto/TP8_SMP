/**
 * @file lion.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef LION_H
#define LION_H

#include "animal.h"
#include <iostream>

using namespace std;

class Lion : public Animal
{
    public:
        /* Constructeur */
        Lion(int maxX, int maxY);
        Lion(int maxX, int maxY, int a, int b);

        /* Destructeur */
        ~Lion();

        /* Méthodes */
        void setAttaque();
        void deplace(int maxX, int maxY);
};