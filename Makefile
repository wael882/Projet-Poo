# ==========================
#     VARIABLES
# ==========================

# Cible par défaut
all: jeu

# Compilateur
CXX = g++
# Flags de compilation
# Flags de compilation (+ include SFML pour éviter les erreurs d'en-têtes)
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Werror -I/usr/include/SFML

# Librairies SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# Sources du projet
SRCS = mainPrincipal.cpp \
       modeConsole.cpp \
       modeGraphique.cpp \
       Grille.cpp \
       Cellule.cpp \
       CellestVivante.cpp \
       CellestMorte.cpp \
       CelluleObstacleVivante.cpp \
       CelluleObstacleMorte.cpp \
       LecteurFichier.cpp \
       Jeu.cpp

# Exécutable
TARGET = jeu

# ==========================
#     REGLES
# ==========================

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(LDFLAGS) -o $(TARGET)

debug: CXXFLAGS += -O0 -U_FORTIFY_SOURCE
debug: $(TARGET)

clean:
	rm -f $(TARGET)
