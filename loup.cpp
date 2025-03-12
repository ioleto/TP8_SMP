/**
 * @file loup.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "loup.hpp"

#define NAME_LOUP "L"

/* Constructeur */

/**
 * @brief Construct a new Loup:: Loup object
 *        Crée un loup à une position aléatoire
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = NAME_LOUP;
    this->setAttaque();
}

/**
 * @brief Construct a new Loup:: Loup object
 *        Crée un loup aux coordonnées (a, b)
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 * @param a : abscisse du loup
 * @param b : ordonnée du loup
 */
Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = "Loup";
    this->setAttaque();
}

/* Destructeur */

/**
 * @brief Destroy the Loup:: Loup object
 * 
 */
Loup::~Loup()
{
    cout << "Destruction du loup" << endl;
}

/* Méthodes */

/**
 * @brief Set the Attaque object
 *        Crée une attaque aléatoire pour le loup
 * 
 */
void Loup::setAttaque()
{
    this->typeAttaque = Attaque();
}

/**
 * @brief Déplace le loup aléatoirement sur la grille
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
void Loup::deplace(int maxX, int maxY)
{
    this->x = rand() % maxX;
    this->y = rand() % maxY;
}