#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

using Plateau = vector<vector<int>>;

// Vous pouvez ajouter des fonctions à ce fichier si besoin est

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 *  fonction écrite par Victor Daviau
 **/
int tireDeuxOuQuatre() {
    int randint = rand() % 10;
    if (randint == 0) {
        return 4;
    }
    return 2;
}

/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 **/
Plateau plateauVide() {
    Plateau vide;
    vide = Plateau(4);
    for (int i = 0; i < 4; i++) {
        vide[i] = {0, 0, 0, 0};
    }
    return vide;
}

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 *  Fonction écrite par Victor Daviau
 **/
Plateau plateauInitial() {
    Plateau jeu = plateauVide();
    int case1 = rand() % 16;
    int case2 = case1;
    while (case2 == case1) {
        case2 = rand() % 16;
    }
    jeu[case1 / 4][case1 % 4] = tireDeuxOuQuatre();
    jeu[case2 / 4][case2 % 4] = tireDeuxOuQuatre();
    return jeu;
}

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau) {
    Plateau nouvellePlateau = plateauVide();

    for (int i = 0; i < 4; i++) {
        if (plateau[i][0] == plateau[i][1]) {
            nouvellePlateau[i][0] = plateau[i][0] * 2;
        } else {
            nouvellePlateau[i][0] = plateau[i][0]; 
        }

        for (int j = 1; j < 3; j++ ) {
            if (plateau[i][j] == plateau[i][j+1]) {
                nouvellePlateau[i][j] = plateau[i][j] * 2;
            } else {
                nouvellePlateau[i][j] = plateau[i][j+1]; 
            }
        }
    }

    return nouvellePlateau;
}

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau) {
    Plateau nouvellePlateau;
    nouvellePlateau = Plateau (4);
    nouvellePlateau = plateauVide();

    for (int i = 0; i < 4; i++) {
        if (plateau[i][2] == plateau[i][3]) {
            nouvellePlateau[i][3] = plateau[i][2] * 2;
        } else {
            nouvellePlateau[i][3] = plateau[i][2]; 
        }

        for (int j = 2; j >= 1; j-- ) {
            if (plateau[i][j-1] == plateau[i][j]) {
                nouvellePlateau[i][j] = plateau[i][j] * 2;
            } else {
                nouvellePlateau[i][j] = plateau[i][j-1]; 
            }
        }
    }

    return nouvellePlateau;
}

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau) {
    Plateau nouvellePlateau;
    nouvellePlateau = Plateau (4);
    nouvellePlateau = plateauVide();

    for (int i = 0; i < 4; i++) {
        if (plateau[0][i] == plateau[1][i]) {
            nouvellePlateau[0][i] = plateau[0][i] * 2;
        } else {
            nouvellePlateau[0][i] = plateau[0][i]; 
        }

        for (int j = 1; j < 3; j++ ) {
            if (plateau[j][i] == plateau[j+1][i]) {
                nouvellePlateau[j][i] = plateau[j][i] * 2;
            } else {
                nouvellePlateau[j][i] = plateau[j+1][i]; 
            }
        }
    }

    return nouvellePlateau;
}

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau) {
    Plateau nouvellePlateau;
    nouvellePlateau = Plateau (4);
    nouvellePlateau = plateauVide();

    for (int i = 0; i < 4; i++) {
        if (plateau[2][i] == plateau[3][i]) {
            nouvellePlateau[3][i] = plateau[2][i] * 2;
        } else {
            nouvellePlateau[3][i] = plateau[2][i]; 
        }

        for (int j = 2; j >= 1; j-- ) {
            if (plateau[j-1][i] == plateau[j][i]) {
                nouvellePlateau[j][i] = plateau[j][i] * 2;
            } else {
                nouvellePlateau[j][i] = plateau[j-1][i]; 
            }
        }
    }

    return nouvellePlateau;
}

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  directions : 1 -> Haut, 2 -> Droite, 3 -> Bas, 4 -> Gauche (au sense de l'horloge)
 *  @param plateau le plateau
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction) {
    if (direction == 1) {
        plateau = deplacementHaut(plateau);
    } else if (direction == 2) {
        plateau = deplacementDroite(plateau);
    } else if (direction == 3) {
        plateau = deplacementBas(plateau);
    } else {
        plateau = deplacementGauche(plateau);
    }

    int caseRandom = rand() % 16;

    while (plateau[caseRandom / 4][caseRandom % 4] != 0) {
        caseRandom = rand() % 16;
    }

    plateau[caseRandom / 4][caseRandom % 4] = tireDeuxOuQuatre();

    return plateau;
}

/** affiche un plateau
 * @param p le plateau
 **/
void dessine(Plateau p) {
    cout << "-----------------------------" << endl;
    for (int ligne = 0;  ligne < 4; ligne++) {
        for (int col = 0; col < 4; col++) {
            cout << '| ' << p[ligne][col];
            if (p[ligne][col] <= 8) {
                cout << "    ";
            } else if (p[ligne][col] <= 64 ) {
                cout << "   ";
            } else if (p[ligne][col] <= 512) {
                cout << "  ";
            } else {
                cout << " ";
            }
        }
        cout << '|' << endl;
        cout << "-----------------------------" << endl;
    }
}

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau) {
    throw runtime_error("A faire");
}

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau) {
    throw runtime_error("A faire");
}

/**teste les fonctions de ce fichier pour vérifier qu'elles fonctionnent correctement
 **/
void tests() {
    //tireDeuxOuQuatre
    //Lance 100 fois la fonction et vérifie que chaque résultat possible apparaît au moins une fois
    //Vérifie aussi que la fonction renvoie toujours 2 ou 4
    //Assez fiable mais peut planter par malchance (avec une probabilité autour de 3e-5)
    bool tireDeux, tireQuatre;
    tireDeux = false;
    tireQuatre = false;
    int tirage = 0;
    for (int i = 0; i < 100; i++) {
        tirage = tireDeuxOuQuatre();
        if (tirage == 2) {
            tireDeux = true;
        } else if (tirage == 4) {
            tireQuatre = true;
        } else {
            cout << "tireDeuxOuQuatre() a renvoyé " << tirage << endl;
            throw range_error("Erreur dans les tests : tireDeuxOuQuatre() doit toujours renvoyer 2 ou 4");}
    }
    if (not tireDeux) {throw runtime_error("Erreur dans les tests : tireDeuxOuQuatre() doit pouvoir renvoyer 2");}
    if (not tireQuatre) {throw runtime_error("Erreur dans les tests : tireDeuxOuQuatre() doit pouvoir renvoyer 4");}
}
