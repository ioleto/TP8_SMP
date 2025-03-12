/**
 * @file loup.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef LOUP_H
#define LOUP_H

#include "animal.h"
#include <iostream>

using namespace std;

class Loup : public Animal
{
    public:
        /* Constructeur */
        Loup(int maxX, int maxY);
        Loup(int maxX, int maxY, int a, int b);

        /* Destructeur */
        ~Loup();

        /* Méthodes */
        void setAttaque();
        void deplace(int maxX, int maxY);
};