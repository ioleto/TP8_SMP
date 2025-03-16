/**
 * @file partie.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 12-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "partie.hpp"
#include <cstring>

/* Constructeur */

/**
 * @brief Construct a new Partie:: Partie object
 *        Crée une partie avec une grille de taille maxX * maxY
 *        L’initialisation se fait avec 25% du plateau rempli,
 *        avec le même nombre d’animaux de chaque type,
 *        distribués de façon aléatoire sur le plateau.
 *
 * @param maxX : largeur de la grille
 * @param maxY : hauteur de la grille
 */
Partie::Partie(int maxX, int maxY)
{
    this->maxX = maxX;
    this->maxY = maxY;
    this->nbAnimaux = 0;

    // initialisation du tableau d'animaux
    for (int iy = 0; iy < maxY; iy++)
    {
        for (int ix = 0; ix < maxX; ix++)
        {
            this->tabAnimaux[ix][iy].clear();
        }
    }

    int animauxAplacer = (maxX * maxY) * 0.25;

    int loupAplacer = animauxAplacer / 4;
    int pierreAplacer = animauxAplacer / 4;
    int oursAplacer = animauxAplacer / 4;
    int lionAplacer = animauxAplacer / 4;

    for (loupAplacer; loupAplacer > 0; loupAplacer--)
    {
        Loup *l = new Loup(maxX, maxY);
        this->tabAnimaux[l->getX()][l->getY()].push_back(l);
        this->nbAnimaux++;
    }

    for (pierreAplacer; pierreAplacer > 0; pierreAplacer--)
    {
        Pierre *p = new Pierre(maxX, maxY);
        this->tabAnimaux[p->getX()][p->getY()].push_back(p);
        this->nbAnimaux++;
    }

    for (oursAplacer; oursAplacer > 0; oursAplacer--)
    {
        Ours *o = new Ours(maxX, maxY);
        this->tabAnimaux[o->getX()][o->getY()].push_back(o);
        this->nbAnimaux++;
    }

    for (lionAplacer; lionAplacer > 0; lionAplacer--)
    {
        Lion *l = new Lion(maxX, maxY);
        this->tabAnimaux[l->getX()][l->getY()].push_back(l);
        this->nbAnimaux++;
    }

    cout << "Début de la partie :" << endl
         << "   - Plateau de " << maxX << "x" << maxY << endl
         << "   - " << this->nbAnimaux << " animaux ont été placés." << endl;
}

/* Destructeur */

/**
 * @brief Destroy the Animal:: Animal object
 *
 */
Partie::~Partie()
{
    cout << "Destruction de la Partie " << endl;
}

/* Méthodes */

void Partie::tourDeJeu()
{
    int nbAnimauxsurCase = 0;

    vector<Animal *> tabTEMPAnimaux[maxX][maxY];

    // initialisation du tableau temporaire d'animaux
    for (int iy = 0; iy < maxY; iy++)
    {
        for (int ix = 0; ix < maxX; ix++)
        {
            tabTEMPAnimaux[ix][iy].clear();
        }
    }

    // On parcourt le tableau d'animaux pour les déplacer
    for (int iy = 0; iy < this->maxY; iy++)
    {
        for (int ix = 0; ix < this->maxX; ix++)
        {
            nbAnimauxsurCase = this->tabAnimaux[ix][iy].size();
            if (nbAnimauxsurCase)
            {
                // On parcourt les animaux de la case
                for (int ia = 0; ia < nbAnimauxsurCase; ia++)
                {
                    // On récupère l'animal
                    Animal *a = this->tabAnimaux[ix][iy][ia];

                    // On récupère les coordonnées de l'animal
                    int x = a->getX();
                    int y = a->getY();

                    // DEBUG On affiche les coordonnées de l'animal
                    // cout << a->getNom() << " en (" << x << ", " << y << "),";

                    // On deplace l'animal
                    a->deplace(this->maxX, this->maxY);

                    // On récupère les nouvelles coordonnées de l'animal
                    x = a->getX();
                    y = a->getY();

                    // DEBUG On affiche les nouvelles coordonnées de l'animal
                    // cout << " déplacé en (" << x << ", " << y << ")" << endl;

                    // On ajoute l'animal dans le tableau temporaire
                    tabTEMPAnimaux[x][y].push_back(a);
                }
                // On vide la case actuelle après avoir déplacé tous les animaux
                this->tabAnimaux[ix][iy].clear();
            }
        }
    }

    // On copie le tableau temporaire dans le tableau d'animaux
    for (int iy = 0; iy < this->maxY; iy++)
    {
        for (int ix = 0; ix < this->maxX; ix++)
        {
            // this->tabAnimaux[ix][iy] = tabTEMPAnimaux[ix][iy];
            tabAnimaux[ix][iy].assign(tabTEMPAnimaux[ix][iy].begin(), tabTEMPAnimaux[ix][iy].end());
        }
    }

    string survivor = "";

    // On parcourt le tableau d'animaux pour vérifier les attaques
    for (int iy = 0; iy < this->maxY; iy++)
    {
        for (int ix = 0; ix < this->maxX; ix++)
        {
            nbAnimauxsurCase = this->tabAnimaux[ix][iy].size();

            if (nbAnimauxsurCase > 1)
            {
                // cout << nbAnimauxsurCase << " animaux sur la case (" << ix << ", " << iy << ")" << endl;
                // On parcourt les animaux de la case
                while (nbAnimauxsurCase > 1)
                {
                    // On récupère l'animal
                    Animal *a = this->tabAnimaux[ix][iy].front();
                    Animal *b = this->tabAnimaux[ix][iy].back();

                    // On attaque l'animal
                    if (a->attaque(*b))
                    {
                        // On supprime l'animal attaqué
                        this->tabAnimaux[ix][iy].pop_back();
                        survivor = a->getNom();
                        // this->nbAnimaux--;
                    }
                    else
                    {
                        // On supprime l'animal attaquant
                        this->tabAnimaux[ix][iy].erase(this->tabAnimaux[ix][iy].begin());
                        survivor = b->getNom();
                        // this->nbAnimaux--;
                    }

                    nbAnimauxsurCase = this->tabAnimaux[ix][iy].size();
                }
            }
        }
    }

    // Vérification supplémentaire pour mettre à jour le nombre d'animaux
    int nbAnimauxReel = 0;
    for (int iy = 0; iy < this->maxY; iy++)
    {
        for (int ix = 0; ix < this->maxX; ix++)
        {
            nbAnimauxReel += this->tabAnimaux[ix][iy].size();
        }
    }
    this->nbAnimaux = nbAnimauxReel;

    // On compte le nombre d'animaux vivants
    cout << "Il reste " << this->nbAnimaux << (this->nbAnimaux == 1 ? " animal" : " animaux") << " en vie" << endl;

    if (this->nbAnimaux == 1)
    {
        cout << "Le " << survivor << " a gagné !" << endl;
    }
}

void Partie::afficherPlateau()
{
    cout << "|";
    for (int iy = 0; iy < this->maxY; iy++)
    {
        for (int ix = 0; ix < this->maxX; ix++)
        {
            cout << "▬▬▬▬|";
        }
        cout << endl;
        cout << "|";

        for (int ix = 0; ix < this->maxX; ix++)
        {
            if (this->tabAnimaux[ix][iy].size() > 0)
            {
                cout << " " << this->tabAnimaux[ix][iy][0]->getNom() << " |";
            }
            else
            {
                cout << "    |";
            }
        }
        cout << endl;
        cout << "|";
    }
    for (int ix = 0; ix < this->maxX; ix++)
    {
        cout << "▬▬▬▬|";
    }
    cout << endl
         << endl;
}

int Partie::getNbAnimaux()
{
    return this->nbAnimaux;
}