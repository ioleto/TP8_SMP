/**
 * @file pierre.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "pierre.hpp"

#define NAME_PIERRE "⛰ "    // "P"

/* Constructeur */

/**
 * @brief Construct a new Pierre:: Pierre object
 *        Crée une pierre à une position aléatoire
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = NAME_PIERRE;   
    this->setAttaque();
}

/**
 * @brief Construct a new Pierre:: Pierre object
 *        Crée une pierre aux coordonnées (a, b)
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 * @param a : abscisse de la pierre
 * @param b : ordonnée de la pierre
 */
Pierre::Pierre(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = NAME_PIERRE;
    this->setAttaque();
}

/* Destructeur */

/**
 * @brief Destroy the Pierre:: Pierre object
 * 
 */
Pierre::~Pierre()
{
    cout << "Destruction de la pierre" << endl;
}

/* Méthodes */

/**
 * @brief Set the Attaque object
 *        Crée une attaque aléatoire pour la pierre
 * 
 */
void Pierre::setAttaque()
{
    this->typeAttaque = Attaque(0);
}

/**
 * @brief La pierre ne se déplace pas
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
void Pierre::deplace(int maxX, int maxY)
{
    // La pierre ne bouge pas
}