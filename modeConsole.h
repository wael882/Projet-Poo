<<<<<<< HEAD
#ifndef MODECONSOLE_H
#define MODECONSOLE_H

=======
#ifndef MODECONSOLE_H
#define MODECONSOLE_H

>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
#include <string>
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"

/**
 * Classe qui gère le mode console du Game of Life.
 * - lit une grille depuis un fichier
 * - exécute un certain nombre d'itérations
<<<<<<< HEAD
 * - sauvegarde chaque état dans un dossier
 */
class ModeConsole : public Afficheur
{
public:
    /**
     * @param fichierEntree  // chemin du fichier d'entrée pour initialiser la grille
     * @param iterations     //nombre d'itérations à effectuer
     */
    ModeConsole(const std::string &fichierEntree, int iterations);

=======
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

>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
    /// Lance la simulation en mode console (sauvegarde les fichiers, affiche la grille finale)
    void executer();

    /// Implémentation de l'afficheur en console
<<<<<<< HEAD
    void afficher(const Grille &grille) override;
=======
    void afficher(const Grille& grille) override;
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5

private:
    /// Sauvegarde l'état courant de la grille dans le dossier de sortie
    void sauvegarder(int iteration) const;
<<<<<<< HEAD
    Jeu m_jeu;
    std::string m_fichierEntree;
    std::string m_dossierSortie;
    int m_iterations;
};

/**
 * Fonction utilitaire pour garder la même interface qu'avant :
 * - demande à l'utilisateur le fichier d'entrée et le nombre d'itérations
 * - crée un ModeConsole et lance executer()
 */
void lancerModeConsole();

#endif // MODECONSOLE_H
=======

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
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
