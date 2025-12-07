#ifndef MODEGRAPHIQUE_H
#define MODEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include <string>
<<<<<<< HEAD
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"
=======
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5

/**
 * Classe qui gère le mode graphique du Game of Life avec SFML.
 * - charge une grille depuis un fichier
 * - exécute un certain nombre d'itérations
 * - affiche la grille dans une fenêtre SFML
 */
<<<<<<< HEAD
class ModeGraphique : public Afficheur
{
public:
=======
class ModeGraphique : public Afficheur
{
public:
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
    /**
     * @param fichierEntree   chemin du fichier de configuration de la grille
     * @param iterationsMax   nombre d'itérations à exécuter
     * @param tailleCellule   taille d'une cellule en pixels (défaut: 10)
     */
<<<<<<< HEAD
    ModeGraphique(const std::string &fichierEntree,
=======
    ModeGraphique(const std::string& fichierEntree,
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
                  int iterationsMax,
                  int tailleCellule = 10);

    /// Lance la boucle principale (ouvre la fenêtre, gère les événements, etc.)
    void executer();

private:
    /// Gère la file d'événements SFML (fermeture, clavier...)
    void gererEvenements();

    /// Met à jour la grille en fonction du temps et du nombre d'itérations
    void mettreAJour();

<<<<<<< HEAD
    /// Dessine la grille dans la fenêtre SFML
    void afficher(const Grille &grille) override;

    // Constantes de timing
    static constexpr float DELAY_INITIAL = 0.2f; // 200 ms
    static constexpr float DELAY_MIN = 0.05f;
    // Taille cible de la fenêtre (fixe) pour éviter les affichages trop petits
    static constexpr int WINDOW_WIDTH = 800; // zone grille
    static constexpr int WINDOW_HEIGHT = 800;
    static constexpr int INFO_PANEL_WIDTH = 200; // zone info à droite

    void initialiserOverlayTexte();

    Jeu m_jeu;
    int m_iterationsMax;
    int m_iterationCourante;
    int m_cellSize;
    bool m_pause;
    float m_delay;

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    sf::Font m_font;
    sf::Text m_overlayText;
};
=======
    /// Dessine la grille dans la fenêtre SFML
    void afficher(const Grille& grille) override;

private:
    // Constantes de timing
    static constexpr float DELAY_INITIAL = 0.2f; // 200 ms
    static constexpr float DELAY_MIN     = 0.05f;
    // Taille cible de la fenêtre (fixe) pour éviter les affichages trop petits
    static constexpr int   WINDOW_WIDTH  = 800;  // zone grille
    static constexpr int   WINDOW_HEIGHT = 800;
    static constexpr int   INFO_PANEL_WIDTH = 200; // zone info à droite

    void initialiserOverlayTexte();

    Jeu           m_jeu;
    int           m_iterationsMax;
    int           m_iterationCourante;
    int           m_cellSize;
    bool          m_pause;
    float         m_delay;

    sf::RenderWindow m_window;
    sf::Clock        m_clock;
    sf::Font         m_font;
    sf::Text         m_overlayText;
};
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5

/**
 * Fonction utilitaire pour garder la même interface qu'avant :
 * - demande à l'utilisateur le fichier d'entrée et le nombre d'itérations
 * - crée un ModeGraphique et lance executer()
 */
void lancerModeGraphique();

#endif // MODEGRAPHIQUE_H
