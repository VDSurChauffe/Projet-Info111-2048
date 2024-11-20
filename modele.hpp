#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
using Plateau = vector<vector<int>>;

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
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
 **/
Plateau plateauInitial() {
    Plateau jeu = plateauVide();
    int case1 = rand() % 16;
    int case2 = rand() % 15;
    if (case2 >= case1) {case2++;}
    jeu[case1 / 4][case1 % 4] = tireDeuxOuQuatre();
    jeu[case2 / 4][case2 % 4] = tireDeuxOuQuatre();
    return jeu;
}

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau) {
    throw runtime_error("A faire");
}

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau) {
    throw runtime_error("A faire");
}

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau) {
    throw runtime_error("A faire");
}

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau) {
    throw runtime_error("A faire");
}

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le plateau
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction) {
    throw runtime_error("A faire");
}

/** affiche un plateau
 * @param p le plateau
 **/
string dessine(Plateau p) {
    throw runtime_error("A faire");
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
    for (vector<int> li: plateau) {
        for (int n: li) {
            if (n == 2048) {return true;}
        }
    }
    return false;
}
/**donne la puissance de 2 correspondant à une valeur de case 
 * @param n un entier puissance de 2
 * @return son log base 2
 **/
int logCase(int n) {
    int l = 0;
    while (n != 1) {
        l++;
        n /= 2;
    }
    return l;
}

/** donne le score correspondant à un plateau
 * @param jeu un plateau correspondant à l'état du jeu
 * @param nat le nombre de 4 apparus naturellement
 * @return le score du plateau
 **/
int scorePlateau(Plateau jeu, int nat) {
    //2 ne donne rien
    //4 résulte d'une fusion donc donne 4
    //8 provient de deux 4 + une fusion à 8 => 16 points
    //16 : deux 8 + 16 donc 48 points
    //en général une case n donne n(logCase(n)-1) points
    //on soustrait 4 pour chaque fois qu'une case 4 est apparue naturellement car ces 4 ne donnent pas de points d'eux-mêmes
    int total = 0;
    for (vector<int> li: jeu) {
        for (int n: li) {
            if (n >= 4) {
                total += n * (logCase(n)-1);
            }
        }
    }
    return total - 4 * nat;
}

/**teste les fonctions de ce fichier pour vérifier qu'elles fonctionnent correctement
 **/
void tests() {
    cout << "Lancement des tests automatiques. Si tout fonctionne, rien ne devrait s'afficher ici." << endl;

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

    //logCase
    int n = 2;
    for (int i = 1; i <= 11; i++) {
        if (logCase(n) != i) {
            throw logic_error("Erreur dans les tests : logCase(" + to_string(n) + ") devrait renvoyer " + to_string(i) + " mais a renvoyé " + to_string(logCase(n)));
        }
        n *= 2;
    }

    //plateauVide
    if (plateauVide() != Plateau({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}})) {
        throw logic_error("Erreur dans les tests : plateauVide() doit renvoyer un plateau vide 4x4");
    }

    //scorePlateau
    Plateau jeuTest = plateauVide();
    jeuTest[1][2] = 8;
    if (scorePlateau(jeuTest, 1) != 12) {throw logic_error("Erreur dans les tests : scorePlateau() ne renvoie pas le bon score pour un plateau presque vide");}
    jeuTest[1][2] = 2;
    jeuTest[2][2] = 2;
    if (scorePlateau(jeuTest, 0) != 0) {throw logic_error("Erreur dans les tests : scorePlateau() devrait renvoyer 0 pour un tableau ne contenant que des 2");}
    
    //plateauInitial
    Plateau testPlateau = plateauInitial();
    int total = 0;
    if (testPlateau.size() != 4) {throw range_error("Erreur dans les tests : plateauInitial() doit renvoyer un tableau de 4 lignes");}
    for (vector<int> li: testPlateau) {
        if (li.size() != 4) {throw range_error("Erreur dans les tests : plateauInitial() doit renvoyer un tableau de 4 colonnes");}
        for (int n: li) {total += n;}
    }
    if (not (total == 4 or total == 6 or total == 8)) {
        throw range_error("plateauInitial() devrait renvoyer un tableau de départ valide mais a renvoyé des valeurs invalides, avec une somme de " + to_string(total));
    }

    //Fonctions de déplacement : à faire

    //estTermine : à faire

    //estGagnant
    Plateau vide = plateauVide();
    Plateau gagnant = {{0, 2, 4, 8}, {4, 16, 256, 2048}, {1024, 512, 128, 64}, {2, 2, 8, 32}};
    if (estGagnant(vide) or not estGagnant(gagnant)) {
        throw runtime_error("Erreur dans les tests : estGagnant() doit identifier correctement les plateaux gagnants");
    }
}
