/**
 * @file partie.h
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 12-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

 #ifndef PARTIE_H
 #define PARTIE_H
 
 #include "animal.hpp"
    #include "loup.hpp"
    #include "pierre.hpp"
    #include "ours.hpp"
    #include "lion.hpp"
    
 #include <vector>
 #include <iostream>

 #define MAX_PLATE_X 20
 #define MAX_PLATE_Y 20
 
 using namespace std;
 
 class Partie
 {
 private:
     int maxX;
     int maxY;
     // tableau bidirectionnel stockant des vecteur d'animaux
     vector<Animal *> tabAnimaux[MAX_PLATE_X][MAX_PLATE_Y];
     int nbAnimaux;
 
 public:
     /* Constructeur */
     Partie(int maxX, int maxY);
 
     /* Destructeur */
     ~Partie();
 
     /* Méthodes */
     void tourDeJeu();
     void afficherPlateau();
     int getNbAnimaux();
 };
 
 #endif // PARTIE_H