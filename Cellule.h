#ifndef CELLULE_H
#define CELLULE_H
#include "EtatCellule.h"

#include <memory>


class Cellule {
private : 
    std::unique_ptr<EtatCellule> etat_actuel; 

public : 
    Cellule(std::unique_ptr<EtatCellule> etat_initial);

    bool estVivante() const;
    bool estObstacle() const;
    EtatType typeEtat() const;
    void changerEtat (std::unique_ptr<EtatCellule> nvEtat);
    void rendreVivante();
    void rendreMorte();
    void rendreObstacleVivante();
    void rendreObstacleMorte();
};




#endif 

