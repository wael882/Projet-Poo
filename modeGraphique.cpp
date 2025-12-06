#include "modeGraphique.h"
#include <iostream>
#include <vector>

// =======================
//      CONSTRUCTEUR
// =======================

ModeGraphique::ModeGraphique(const std::string& fichierEntree,
                             int iterationsMax,
                             int tailleCellule)
    : m_jeu(LecteurFichier::charger(fichierEntree)),
      m_iterationsMax(iterationsMax),
      m_iterationCourante(0),
      m_cellSize(tailleCellule),
      m_pause(false),
      m_delay(DELAY_INITIAL),
      m_window(),
      m_clock()
{
    // Calcule une taille de cellule pour remplir une fenêtre fixe
    const int cols = m_jeu.grille().getnbcolonnes();
    const int rows = m_jeu.grille().getnblignes();
    if (cols > 0 && rows > 0) {
        int cellSizeAuto = std::min(WINDOW_WIDTH / cols, WINDOW_HEIGHT / rows);
        if (cellSizeAuto <= 0) {
            cellSizeAuto = 1;
        }
        m_cellSize = cellSizeAuto;
    }

    // Largeur totale = zone grille + panneau d'info
    m_window.create(sf::VideoMode(WINDOW_WIDTH + INFO_PANEL_WIDTH, WINDOW_HEIGHT),
                    "Game of Life - Mode graphique");

    initialiserOverlayTexte();
}

// =======================
//       METHODES PUBLIQUES
// =======================

void ModeGraphique::executer()
{
    while (m_window.isOpen()) {
        gererEvenements();
        mettreAJour();
        afficher(m_jeu.grille());
    }
}

// =======================
//       METHODES PRIVEES
// =======================

void ModeGraphique::gererEvenements()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        // Fermeture de la fenêtre
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }

        // Gestion des touches
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                m_window.close();
            }
            // Espace = pause / reprise
            if (event.key.code == sf::Keyboard::Space) {
                m_pause = !m_pause;
            }
            // Flèche haut -> plus rapide
            if (event.key.code == sf::Keyboard::Up) {
                m_delay -= 0.05f;
                if (m_delay < DELAY_MIN) {
                    m_delay = DELAY_MIN;
                }
            }
            // Flèche bas -> plus lent
            if (event.key.code == sf::Keyboard::Down) {
                m_delay += 0.05f;
            }
        }
    }
}

void ModeGraphique::mettreAJour()
{
    // Mise à jour de la grille selon delay, tant qu'on n'a pas dépassé
    // le nombre d'itérations demandées
    if (!m_pause
        && m_iterationCourante < m_iterationsMax
        && m_clock.getElapsedTime().asSeconds() >= m_delay)
    {
        m_jeu.tick();
        ++m_iterationCourante;
        m_clock.restart();
    }
}

void ModeGraphique::afficher(const Grille& grille)
{
    m_window.clear(sf::Color::Black);

    // Panneau d'info à droite
    sf::RectangleShape infoPanel(
        sf::Vector2f(static_cast<float>(INFO_PANEL_WIDTH),
                     static_cast<float>(WINDOW_HEIGHT)));
    infoPanel.setFillColor(sf::Color(20, 20, 20));
    infoPanel.setPosition(static_cast<float>(WINDOW_WIDTH), 0.f);
    m_window.draw(infoPanel);

    sf::RectangleShape cell(
        sf::Vector2f(static_cast<float>(m_cellSize),
                     static_cast<float>(m_cellSize)));

    // Dessin des cellules
    for (int i = 0; i < grille.getnblignes(); ++i) {
        for (int j = 0; j < grille.getnbcolonnes(); ++j) {

            const auto type = grille.getCellule(i, j).typeEtat();
            switch (type) {
                case EtatType::Vivante:
                    cell.setFillColor(sf::Color::Green);
                    break;
                case EtatType::Morte:
                    cell.setFillColor(sf::Color::Black);
                    break;
                case EtatType::ObstacleVivante:
                    cell.setFillColor(sf::Color(0, 120, 215)); // bleu
                    break;
                case EtatType::ObstacleMorte:
                    cell.setFillColor(sf::Color(200, 70, 70)); // rouge atténué
                    break;
            }

            cell.setPosition(static_cast<float>(j * m_cellSize),
                             static_cast<float>(i * m_cellSize));
            m_window.draw(cell);
        }
    }

    // Dessin du quadrillage en blanc
    sf::Vertex line[2];
    int width  = grille.getnbcolonnes() * m_cellSize;
    int height = grille.getnblignes()   * m_cellSize;

    // Lignes horizontales
    for (int i = 0; i <= grille.getnblignes(); ++i) {
        float y = static_cast<float>(i * m_cellSize);
        line[0] = sf::Vertex(sf::Vector2f(0.f,    y), sf::Color::White);
        line[1] = sf::Vertex(sf::Vector2f(static_cast<float>(width),  y),
                             sf::Color::White);
        m_window.draw(line, 2, sf::Lines);
    }

    // Lignes verticales
    for (int j = 0; j <= grille.getnbcolonnes(); ++j) {
        float x = static_cast<float>(j * m_cellSize);
        line[0] = sf::Vertex(sf::Vector2f(x, 0.f),           sf::Color::White);
        line[1] = sf::Vertex(sf::Vector2f(x, static_cast<float>(height)),
                             sf::Color::White);
        m_window.draw(line, 2, sf::Lines);
    }

    // Overlay texte : numéro d'itération, dans le panneau
    if (m_font.getInfo().family != "") {
        m_overlayText.setString(
            "Iteration : " + std::to_string(m_iterationCourante) +
            " / " + std::to_string(m_iterationsMax));
        m_window.draw(m_overlayText);
    }

    m_window.display();
}

void ModeGraphique::initialiserOverlayTexte()
{
    // Fallback multi-plateforme pour trouver une police
    const std::vector<std::string> candidates = {
        "fonts/sansation.ttf", // convention SFML
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", // Linux
        "/usr/share/fonts/truetype/freefont/FreeSans.ttf",
        "C:/Windows/Fonts/arial.ttf" // Windows
    };

    for (const auto& path : candidates) {
        if (m_font.loadFromFile(path)) {
            break;
        }
    }

    if (m_font.getInfo().family == "") {
        std::cerr << "Avertissement : aucune police trouvée pour l'overlay.\n";
        return;
    }

    m_overlayText.setFont(m_font);
    m_overlayText.setCharacterSize(18);
    m_overlayText.setFillColor(sf::Color::White);
    m_overlayText.setOutlineColor(sf::Color::Black);
    m_overlayText.setOutlineThickness(1.f);
    // Position dans le panneau d'info
    m_overlayText.setPosition(static_cast<float>(WINDOW_WIDTH + 10), 10.f);
}

// =======================
//  FONCTION UTILITAIRE
// =======================

void lancerModeGraphique()
{
    std::cout << "=== MODE GRAPHIQUE ===\n";

    // On demande le fichier d'entrée
    std::string fichierEntree;
    std::cout << "Entrez le fichier d'entree : ";
    std::cin >> fichierEntree;

    // L'utilisateur choisit le nombre d'itérations
    int iterations = 0;
    std::cout << "Nombre d'iterations : ";
    std::cin >> iterations;

    ModeGraphique mode(fichierEntree, iterations);
    mode.executer();
}
