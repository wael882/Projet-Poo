#ifndef MODECONSOLE_H
#define MODECONSOLE_H

#include <string>
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"

/**
 * Classe qui gère le mode console du Game of Life.
 * - lit une grille depuis un fichier
 * - exécute un certain nombre d'itérations
 * - sauvegarde chaque état dans un dossier
 */
class ModeConsole : public Afficheur
{
public:
    /**
     * @param fichierEntree  chemin du fichier d'entrée pour initialiser la grille
     * @param iterations     nombre d'itérations à effectuer
     */
    ModeConsole(const std::string& fichierEntree, int iterations);

    /// Lance la simulation en mode console (sauvegarde les fichiers, affiche la grille finale)
    void executer();

    /// Implémentation de l'afficheur en console
    void afficher(const Grille& grille) override;

private:
    /// Sauvegarde l'état courant de la grille dans le dossier de sortie
    void sauvegarder(int iteration) const;

private:
    Jeu         m_jeu;
    std::string m_fichierEntree;
    std::string m_dossierSortie;
    int         m_iterations;
};

/**
 * Fonction utilitaire pour garder la même interface qu'avant :
 * - demande à l'utilisateur le fichier d'entrée et le nombre d'itérations
 * - crée un ModeConsole et lance executer()
 */
void lancerModeConsole();

#endif // MODECONSOLE_H
