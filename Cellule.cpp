#include "Cellule.h"
#include "CellestVivante.h"
#include "CellestMorte.h"
#include "CelluleObstacleVivante.h"
#include "CelluleObstacleMorte.h"

#include <utility>

Cellule::Cellule(std::unique_ptr<EtatCellule> etat_initial)
:etat_actuel(std::move(etat_initial)){};

bool Cellule::estVivante() const {
    return etat_actuel->estVivante();
}

void Cellule::changerEtat(std::unique_ptr<EtatCellule> nvEtat) {
    etat_actuel = std::move(nvEtat);
}

void Cellule::rendreVivante() {
    std::unique_ptr<EtatCellule> nouvelEtat = std::make_unique<CelluleVivante>();
    changerEtat(std::move(nouvelEtat));
}


void Cellule::rendreMorte() {
    std::unique_ptr<EtatCellule> nouvelEtat = std::make_unique<CelluleMorte>();
    changerEtat(std::move(nouvelEtat));
}

void Cellule::rendreObstacleVivante() {
    std::unique_ptr<EtatCellule> nouvelEtat = std::make_unique<CelluleObstacleVivante>();
    changerEtat(std::move(nouvelEtat));
}

void Cellule::rendreObstacleMorte() {
    std::unique_ptr<EtatCellule> nouvelEtat = std::make_unique<CelluleObstacleMorte>();
    changerEtat(std::move(nouvelEtat));
}

bool Cellule::estObstacle() const {
    return etat_actuel->estObstacle();
}

EtatType Cellule::typeEtat() const {
    return etat_actuel->type();
}
