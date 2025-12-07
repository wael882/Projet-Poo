#ifndef MODECONSOLE_H
#define MODECONSOLE_H

#include <string>
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"

// Mode console du Game of Life : lit une grille depuis un fichier, execute des iterations et sauvegarde chaque etat.
class ModeConsole : public Afficheur {
public:
    // fichierEntree : chemin du fichier d'entree, iterations : nombre d'iterations a effectuer
    ModeConsole(const std::string& fichierEntree, int iterations);

    // Lance la simulation en mode console (sauvegarde les fichiers, affiche la grille finale)
    void executer();

    // Implementation de l'afficheur en console
    void afficher(const Grille& grille) override;

private:
    // Sauvegarde l'etat courant de la grille dans le dossier de sortie
    void sauvegarder(int iteration) const;

    Jeu m_jeu;
    std::string m_fichierEntree;
    std::string m_dossierSortie;
    int m_iterations;
};

// Fonction utilitaire : demande le fichier et le nombre d'iterations puis lance le mode console.
void lancerModeConsole();

#endif // MODECONSOLE_H
