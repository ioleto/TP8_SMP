/**
 * @file animal.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "animal.hpp"

/* Constructeur */

/**
 * @brief Construct a new Animal:: Animal object
 *        Met vivant à true et place l'animal à une position aléatoire
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Animal::Animal(int maxX, int maxY)
{
    this->x = rand() % maxX;
    this->y = rand() % maxY;
    this->vivant = true;
}

/**
 * @brief Construct a new Animal:: Animal object
 *        Met vivant à true et place l'animal aux coordonnées (x, y)
 * 
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 * @param y : ordonnée de l'animal
 * @param x : abscisse de l'animal
 */
Animal::Animal(int maxX, int maxY, int y, int x)
{
    if(x > maxX)
        this->x = maxX;
    else if(x < 0)
        this->x = 0;
    else
        this->x = x;

    if(y > maxY)
        this->y = maxY;
    else if(y < 0)
        this->y = 0;
    else
        this->y = y;
}

/* Destructeur */

/**
 * @brief Destroy the Animal:: Animal object
 * 
 */
Animal::~Animal()
{
    cout << "Destruction de l'animal " << this->nom << endl;
}


/* Setters */

/**
 * @brief Set the Vivant object
 * 
 * @param v : true si l'animal est vivant, false sinon
 */
void Animal::setVivant(bool v)
{
    this->vivant = v;
}

/* Getters */

/**
 * @brief Get the Nom object
 * 
 * @return const string : nom de l'animal
 */
const string Animal::getNom()
{
    return this->nom;
}

/**
 * @brief Get the X object
 * 
 * @return const int : abscisse de l'animal
 */
const int Animal::getX()
{
    return this->x;
}

/**
 * @brief Get the Y object
 * 
 * @return const int : ordonnée de l'animal
 */
const int Animal::getY()
{
    return this->y;
}

/**
 * @brief Get the Vivant object
 * 
 * @return const bool : true si l'animal est vivant, false sinon
 */
const bool Animal::getVivant()
{
    return this->vivant;
}

/**
 * @brief Get the Attaque object
 * 
 * @return const Attaque : type d'attaque de l'animal
 */
const Attaque Animal::getAttaque()
{
    return this->typeAttaque;
}

/* Méthodes */

/**
 * @brief Attaque un autre animal
 * 
 * @param a : animal à attaquer
 * @return true si l'attaque a réussi, false sinon
 */
bool Animal::attaque(Animal &a)
{
    if(this->vivant && a.vivant)
    {
        this->setAttaque();
        a.setAttaque();

        cout << this->nom << this->typeAttaque.getNomAttaque() << " VS " << a.nom << a.typeAttaque.getNomAttaque() << " : ";
        if(this->typeAttaque.resoudreAttaque(a.typeAttaque))
        {
            cout << this->nom << endl;
            a.setVivant(false);
            return true;
        }
        else
        {
            cout << a.nom << endl;
            this->vivant = false;
            return false;
        }
    }
    else
    {
        cout << "Un des deux animaux est déjà mort !" << endl;
        return true;
    }
}
