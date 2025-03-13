/**
 * @file attaque.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 12-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "attaque.hpp"

/* Constructeurs */

/**
 * @brief Construct a new Attaque:: Attaque object
 *        Crée une attaque aléatoire
 */
Attaque::Attaque()
{
    this->type = rand() % 3;
}

/**
 * @brief Construct a new Attaque:: Attaque object
 * 
 * @param a : 0 :pierre, 1: Feuille, 2:Ciseaux
 */
Attaque::Attaque(int a)
{
    if(a > 2)
        this->type = 2;
    else if(a < 0)
        this->type = 0;
    else
        this->type = a;
}

/* Destructeur */

/**
 * @brief Destroy the Attaque:: Attaque object
 * 
 */
Attaque::~Attaque()
{
    // cout << "Destruction de l'attaque" << endl;
}

/* Méthodes */

/**
 * @brief Get the Type Attaque object
 * 
 * @return const int : 0 :pierre, 1: Feuille, 2:Ciseaux
 */
const int Attaque::getTypeAttaque()
{
    return this->type;
}

/**
 * @brief Resoud l'attaque contre une autre attaque
 * 
 * @param a : Attaque à comparer
 * @return const bool : true si victoire, false sinon
 */
const bool Attaque::resoudreAttaque(Attaque &a)
{
    if(this->type == a.getTypeAttaque())
        return rand() % 2 == 0; // 50% de chance de gagner
    else if(this->type == 0 && a.getTypeAttaque() == 1)
        return false;   // pierre vs feuille
    else if(this->type == 1 && a.getTypeAttaque() == 2)
        return false;   // feuille vs ciseaux
    else if(this->type == 2 && a.getTypeAttaque() == 0)
        return false;   // ciseaux vs pierre
    else
        return true;    // victoire
}

/**
 * @brief Get the Nom Attaque object
 * 
 * @return const string : Nom de l'attaque (Pierre, Feuille, Ciseaux)
 */
const string Attaque::getNomAttaque()
{
    switch(this->type)
    {
        case 0:
            return "💎";
        case 1:
            return "📜";
        case 2:
            return "🗡 ";
        default:
            return "Erreur";
    }
}