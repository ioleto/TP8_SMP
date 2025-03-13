/**
 * @file ours.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 12-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "ours.hpp"

#define NAME_OURS "🐻" //"O"

/* Constructeur */

/**
 * @brief Construct a new Ours:: Ours object
 *        Crée un ours à une position aléatoire
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = NAME_OURS;
    this->setAttaque();
}

/**
 * @brief Construct a new Ours:: Ours object
 *        Crée un ours aux coordonnées (a, b)
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 * @param a : abscisse du ours
 * @param b : ordonnée du ours
 */
Ours::Ours(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = NAME_OURS;
    this->setAttaque();
}

/* Destructeur */

/**
 * @brief Destroy the Ours:: Ours object
 *
 */
Ours::~Ours()
{
    cout << "Destruction du ours" << endl;
}

/* Méthodes */

/**
 * @brief Set the Attaque object
 *        Crée une attaque aléatoire entre feuille 1 et ciseau 2 pour le ours
 *
 */
void Ours::setAttaque()
{
    this->typeAttaque = Attaque(1); // attaque seulement avec la feuille
}

/**
 * @brief Déplace le ours dans une des 8 directions suivantes
 * (2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2, -1)
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
void Ours::deplace(int maxX, int maxY)
{
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int direction = rand() % 8;

    this->x = (this->x + dx[direction] + maxX) % maxX;
    this->y = (this->y + dy[direction] + maxY) % maxY;
}