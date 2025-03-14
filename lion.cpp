/**
 * @file lion.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 12-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "lion.hpp"

#define NAME_LION "🦁" //"L"

/* Constructeur */

/**
 * @brief Construct a new Lion:: Lion object
 *        Crée un lion à une position aléatoire
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = NAME_LION;
    this->setAttaque();
}

/**
 * @brief Construct a new Lion:: Lion object
 *        Crée un lion aux coordonnées (a, b)
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 * @param a : abscisse du lion
 * @param b : ordonnée du lion
 */
Lion::Lion(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = NAME_LION;
    this->setAttaque();
}

/* Destructeur */

/**
 * @brief Destroy the Lion:: Lion object
 *
 */
Lion::~Lion()
{
    cout << "Destruction du lion" << endl;
}

/* Méthodes */

/**
 * @brief Set the Attaque object
 *        Crée une attaque aléatoire entre feuille 1 et ciseau 2 pour le lion
 *
 */
void Lion::setAttaque()
{
    this->typeAttaque = Attaque(rand() % 2 + 1); // 1 ou 2
}

/**
 * @brief Déplace le lion dans une des 4 directions (1,1), (1,-1), (-1,-1) ou (-1,1)
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
void Lion::deplace(int maxX, int maxY)
{
    this->x = (this->x + (rand() % 2 ? 1 : -1) + maxX) % maxX; // 1 ou -1
    this->y = (this->y + (rand() % 2 ? 1 : -1) + maxY) % maxY; // 1 ou -1
}