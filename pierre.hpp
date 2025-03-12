/**
 * @file pierre.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 12-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PIERRE_H
#define PIERRE_H

#include "animal.hpp"
#include <iostream>

using namespace std;

class Pierre : public Animal
{
public:
    /* Constructeur */
    Pierre(int maxX, int maxY);
    Pierre(int maxX, int maxY, int a, int b);

    /* Destructeur */
    ~Pierre();

    /* Méthodes */
    void setAttaque();
    void deplace(int maxX, int maxY);
};

#endif // PIERRE_H