# ==========================
#     VARIABLES
# ==========================

<<<<<<< HEAD
# Cible par defaut
=======
# Cible par défaut
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
all: jeu

# Compilateur
CXX = g++
# Flags de compilation
<<<<<<< HEAD
# Flags de compilation (+ include SFML pour eviter les erreurs d'entetes)
=======
# Flags de compilation (+ include SFML pour éviter les erreurs d'en-têtes)
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
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
<<<<<<< HEAD
       Jeu.cpp \
       test_unitaire.cpp

# Executable principal
TARGET = jeu

# Sources pour les tests unitaires
TEST_SRCS = mainTests.cpp \
            test_unitaire.cpp \
            Grille.cpp \
            Cellule.cpp \
            CellestVivante.cpp \
            CellestMorte.cpp \
            CelluleObstacleVivante.cpp \
            CelluleObstacleMorte.cpp

# Executable de tests unitaires
TEST_TARGET = tests

=======
       Jeu.cpp

# Exécutable
TARGET = jeu

>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
# ==========================
#     REGLES
# ==========================

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(LDFLAGS) -o $(TARGET)

<<<<<<< HEAD
$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET)

debug: CXXFLAGS += -O0 -U_FORTIFY_SOURCE
debug: $(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
=======
debug: CXXFLAGS += -O0 -U_FORTIFY_SOURCE
debug: $(TARGET)

clean:
	rm -f $(TARGET)
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
