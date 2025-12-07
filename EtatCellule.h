#ifndef ETATCELLULE_H
#define ETATCELLULE_H
#include <iostream>

// Types d'état pour identifier vivante/morte et les obstacles
<<<<<<< HEAD
enum class EtatType
{
=======
enum class EtatType {
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
    Vivante,
    Morte,
    ObstacleVivante,
    ObstacleMorte
};

<<<<<<< HEAD
class EtatCellule
{ // classe abstrait qui sert de base pour tous les Ǹtats possible d'une cellule (vivante ou morte)
public:
    virtual bool estVivante() const = 0; // cette méthode virtuelle indique si la cellule est vivante ou non
    virtual bool estObstacle() const { return false; }
    virtual EtatType type() const = 0;
    virtual ~EtatCellule() = default; // Destructeur
};

#endif
=======
class EtatCellule { //classe abstrait qui sert de base pour tous les Ǹtats possible d'une cellule (vivante ou morte)
public :
    virtual bool estVivante() const = 0; //cette mǸthode virtuelle indique si la cellule est vivante ou non
    virtual bool estObstacle() const { return false; }
    virtual EtatType type() const = 0;
    virtual ~ EtatCellule() = default; // Destructeur
};

#endif 
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
