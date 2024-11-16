#include <vector>
#include <string>
using namespace std;

using Plateau = vector<vector<int>>;

// Vous pouvez ajouter des fonctions à ce fichier si besoin est

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre() {
    int randint = rand() % 10;
    if (randint == 0) {
        return 4;
    }
    return 2;
};

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
};

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 **/
Plateau plateauInitial() {
    Plateau jeu = plateauVide();
    int case1 = rand() % 16;
    int case2 = case1;
    while (case2 == case1) {
        case2 == rand() % 16;
    }
    jeu[case1 / 4][case1 % 4] = tireDeuxOuQuatre();
    jeu[case2 / 4][case2 % 4] = tireDeuxOuQuatre();
};

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau) {
    throw runtime_error("A faire");
};

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau déplacementDroite(Plateau plateau) {
    throw runtime_error("A faire");
};

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau déplacementHaut(Plateau plateau) {
    throw runtime_error("A faire");
};

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau déplacementBas(Plateau plateau) {
    throw runtime_error("A faire");
};

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le plateau
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 **/
Plateau déplacement(Plateau plateau, int direction {
    throw runtime_error("A faire");
};

/** affiche un plateau
 * @param p le plateau
 **/
string dessine(Plateau p) {
    throw runtime_error("A faire");
};

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTerminé(Plateau plateau) {
    throw runtime_error("A faire");
};

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau) {
    throw runtime_error("A faire");
};
