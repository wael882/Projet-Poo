#ifndef GRILLE_H
#define GRILLE_H

<<<<<<< HEAD
#include <vector>
#include "Cellule.h"
#include "CelluleObstacleVivante.h"
#include "CelluleObstacleMorte.h"

class Grille
{
private:
    int nb_ligne;
    int nb_colonne;

    std::vector<std::vector<Cellule>> matr_grille;

public:
    Grille(int lignes, int colonnes);

    int getnblignes() const;
    int getnbcolonnes() const;

    Cellule &getCellule(int ligne, int colonne);
    const Cellule &getCellule(int ligne, int colonne) const;

    int compter_VoisinsVivants(int ligne, int colonne) const;

    void miseJour();
};

#endif
=======
#include <vector>
#include "Cellule.h"
#include "CelluleObstacleVivante.h"
#include "CelluleObstacleMorte.h"

class Grille {
private :  
    int nb_ligne;
    int nb_colonne;

    std::vector<std::vector<Cellule>> matr_grille;

public : 
    Grille(int lignes, int colonnes);

    int getnblignes () const; 
    int getnbcolonnes () const;

    Cellule& getCellule (int ligne, int colonne);
    const Cellule& getCellule(int ligne, int colonne) const;

    int compter_VoisinsVivants(int ligne, int colonne) const;

    void miseJour (); 
};






#endif
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
