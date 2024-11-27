#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "modele.hpp"

using namespace std;
using Plateau = vector<vector<int>>;

string couleurDuTableau = "\x1b[38;5;94m";
string couleurNoir = "\x1b[38;5;0m";
string couleurBlanc = "\x1b[38;5;15m"; 
string couleurDuFond = "\x1b[48;5;250m";
string couleurCarreeVide = "\x1b[48;5;231m";
string couleurCarree2 = "\x1b[48;5;222m";
string couleurCarree4 = "\x1b[48;5;220m";
string couleurCarree6 = "\x1b[48;5;214m";
string couleurCarree8 = "\x1b[48;5;208m";
string couleurCarree16 = "\x1b[48;5;202m";
string couleurCarree32 = "\x1b[48;5;196m";
string couleurCarree64 = "\x1b[48;5;160m";
string couleurCarree128 = "\x1b[48;5;160m";
string couleurCarree256 = "\x1b[48;5;124m";
string couleurCarree512 = "\x1b[48;5;124m";
string couleurCarree1024 = "\x1b[48;5;88m";
string couleurCarree2048 = "\x1b[48;5;88m";
string couleurCarreePlus = "\x1b[48;5;52m";

// Toutes les fonctions associées aux déplacements ont été écrites par Parsa
// La plupart des autres fonctions, ainsi que tests(), ont été écrites et maintenues par Victor

/** fonction inverseVector (auxiliaire)
 *  @param inp un vecteur<int>
 *  @return inp mais avec l'ordre inverse
 */
vector<int> inverseVector(vector<int> inp) {
    vector<int> retVect;
    retVect = vector<int> (0);
    for (int i = inp.size() - 1; i >= 0; i--) {
        retVect.push_back( inp[i] );
    }

    return retVect;
}

/** fonction tourneGauche (auxiliaire)
 *  @param p un plateau
 *  @return p tourné de 90 degrés vers la gauche
 */
Plateau tourneGauche(Plateau p) {
    int lignes = p.size();
    int cols = p[0].size();
    vector<vector<int>> rotated(cols, vector<int>(lignes));

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[cols - j - 1][i] = p[i][j];
        }
    }

    return rotated;
}

/** fonction tourneDroite (auxiliaire)
 *  @param p un plateau
 *  @return p tourné de 90 degrés vers la droite
 */
Plateau tourneDroite(Plateau p) {
    int lignes = p.size();
    int cols = p[0].size();
    vector<vector<int>> rotated(cols, vector<int>(lignes));

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][lignes - i - 1] = p[i][j];
        }
    }

    return rotated;
}

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
    // on prend case2 entre 0 et 14 et on incrémente si c'est >= case1 pour simuler le fait de prendre case2 dans [[0; 15]]\{case1}
    jeu[case1 / 4][case1 % 4] = tireDeuxOuQuatre();
    jeu[case2 / 4][case2 % 4] = tireDeuxOuQuatre();
    return jeu;
}

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau) {
    // initialiser nouveauPlateau
    Plateau nouveauPlateau;
    nouveauPlateau = Plateau (4);
    for (int i = 0; i < 4; i++) {
        nouveauPlateau[i] = vector<int> (0);
    }

    // deplacer
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (plateau[i][j] != 0) {
                nouveauPlateau[i].push_back(plateau[i][j]);
            }
        }

        while (nouveauPlateau[i].size() != 4) {
            nouveauPlateau[i].push_back(0);
        }
    }

    // fusionner
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (nouveauPlateau[i][j] == nouveauPlateau[i][j+1]) {
                nouveauPlateau[i][j] = nouveauPlateau[i][j] * 2;
                nouveauPlateau[i][j+1] = 0;
            }
        }
    }

    // initialiser nouveauPlateau2
    Plateau nouveauPlateau2;
    nouveauPlateau2 = Plateau (4);
    for (int i = 0; i < 4; i++) {
        nouveauPlateau2[i] = vector<int> (0);
    }

    // deplacer
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (nouveauPlateau[i][j] != 0) {
                nouveauPlateau2[i].push_back(nouveauPlateau[i][j]);
            }
        }

        while (nouveauPlateau2[i].size() != 4) {
            nouveauPlateau2[i].push_back(0);
        }
    }

    return nouveauPlateau2;
}

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau) {
    // initialiser nouveauPlateau
    Plateau nouveauPlateau;
    nouveauPlateau = Plateau (4);
    for (int i = 0; i < 4; i++) {
        nouveauPlateau[i] = vector<int> (0);
    }

    // deplacer
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (plateau[i][j] != 0) {
                nouveauPlateau[i].push_back(plateau[i][j]);
            }
        }

        nouveauPlateau[i] = inverseVector(nouveauPlateau[i]);
        while (nouveauPlateau[i].size() != 4) {
            nouveauPlateau[i].push_back(0);
        }
        nouveauPlateau[i] = inverseVector(nouveauPlateau[i]);
    }

    // fusionner
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j > 0; j--) {
            if (nouveauPlateau[i][j] == nouveauPlateau[i][j-1]) {
                nouveauPlateau[i][j] = nouveauPlateau[i][j] * 2;
                nouveauPlateau[i][j-1] = 0;
            }
        }
    }

    // initialiser nouveauPlateau2
    Plateau nouveauPlateau2;
    nouveauPlateau2 = Plateau (4);
    for (int i = 0; i < 4; i++) {
        nouveauPlateau2[i] = vector<int> (0);
    }

    // deplacer
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (nouveauPlateau[i][j] != 0) {
                nouveauPlateau2[i].push_back(nouveauPlateau[i][j]);
            }
        }

        nouveauPlateau2[i] = inverseVector(nouveauPlateau2[i]);
        while (nouveauPlateau2[i].size() != 4) {
            nouveauPlateau2[i].push_back(0);
        }
        nouveauPlateau2[i] = inverseVector(nouveauPlateau2[i]);
    }

    return nouveauPlateau2;
}

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau) {
    Plateau plateauTournee = tourneGauche(plateau);
    plateauTournee = deplacementGauche(plateauTournee);
    return tourneDroite(plateauTournee);
}

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau) {
    Plateau plateauTournee = tourneGauche(plateau);
    plateauTournee = deplacementDroite(plateauTournee);
    return tourneDroite(plateauTournee);
}

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  directions : 1 -> Haut, 2 -> Droite, 3 -> Bas, 4 -> Gauche (suivant le sens horaire)
 *  @param plateau le plateau
 *  @param direction un entier représentant la direction
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

    return plateau;
}

/** ajoute une case à un plateau
 * @param p un plateau, dont on suppose qu'il a au moins une case vide
 * @param k la valeur (2/4) de la case à ajouter
 * @return le plateau après apparition d'une case 2/4
 */
Plateau ajouteCase(Plateau p, int k) {
    int caseRandom = rand() % 16;
    while (p[caseRandom / 4][caseRandom % 4] != 0) {
        caseRandom = rand() % 16;
    }
    p[caseRandom / 4][caseRandom % 4] = k;
    return p;
}

/** affiche un plateau
 * @param p le plateau
 **/
void dessine(Plateau p) {
    cout << couleurDuTableau << "=====================================" << couleurNoir << endl;
    for (int ligne = 0;  ligne < 4; ligne++) {
        for (int col = 0; col < 4; col++) {
            if (p[ligne][col] == 0) {
                cout << couleurDuTableau << "|" << couleurDuFond << "        " << couleurDuFond << couleurNoir;
            } else {
                if (p[ligne][col] == 2) {
                    cout << couleurDuTableau << "|" << couleurCarree2 << couleurBlanc << " " << 2 << "      " << couleurDuFond << couleurNoir;
                } else if (p[ligne][col] == 4) {
                    cout << couleurDuTableau << "|" << couleurCarree4 << couleurBlanc << " " << 4 << "      " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 8) {
                    cout << couleurDuTableau << "|" << couleurCarree8 << couleurBlanc << " " << 8 << "      " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 16) {
                    cout << couleurDuTableau << "|" << couleurCarree16 << couleurBlanc << " " << 16 << "     " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 32) {
                    cout << couleurDuTableau << "|" << couleurCarree32 << couleurBlanc << " " << 32 << "     " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 64) {
                    cout << couleurDuTableau << "|" << couleurCarree64 << couleurBlanc << " " << 64 << "     " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 128) {
                    cout << couleurDuTableau << "|" << couleurCarree128 << couleurBlanc << " " << 128 << "    " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 256) {
                    cout << couleurDuTableau << "|" << couleurCarree256 << couleurBlanc << " " << 256 << "    " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 512) {
                    cout << couleurDuTableau << "|" << couleurCarree512 << couleurBlanc << " " << 512 << "    " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 1024) {
                    cout << couleurDuTableau << "|" << couleurCarree1024 << couleurBlanc << " " << 1024 << "   " << couleurDuFond << couleurNoir;
                }else if (p[ligne][col] == 2048) {
                    cout << couleurDuTableau << "|" << couleurCarree2048 << couleurBlanc << " " << 2048 << "   " << couleurDuFond << couleurNoir;
                } else {
                    cout << couleurDuTableau << "|" << couleurCarreePlus << couleurBlanc << " " << p[ligne][col] << "   " << couleurDuFond << couleurNoir;
                }
            }
        }
        cout << couleurDuTableau << '|' << couleurNoir << endl;
        cout << couleurDuTableau << "=====================================" << couleurNoir << endl;
    }
}

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si le plateau est terminé, false sinon
 **/
bool estTermine(Plateau p) {
    for (int dir = 1; dir <= 4; dir++) {
        if (deplacement(p, dir) != p) {return false;}
    }
    return true;
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

    //Fonctions de déplacement
    Plateau plateauTestDeplace = {
        {0, 2, 2, 4}, 
        {2, 0, 8, 0}, 
        {2, 2, 8, 8}, 
        {4, 0, 8, 2}
    };
    string erreur = "Erreur dans les tests : les fonctions de déplacement ne déplacent pas correctement un tableau";
    Plateau expected = {{4, 4, 0, 0}, {2, 8, 0, 0}, {4, 16, 0, 0}, {4, 8, 2, 0}};
    if (deplacementGauche(plateauTestDeplace) != expected) {throw runtime_error(erreur);}
    expected = {{0, 0, 4, 4}, {0, 0, 2, 8}, {0, 0, 4, 16}, {0, 4, 8, 2}};
    if (deplacementDroite(plateauTestDeplace) != expected) {throw runtime_error(erreur);}
    expected = {{4, 4, 2, 4}, {4, 0, 16, 8}, {0, 0, 8, 2}, {0, 0, 0, 0}};
    if (deplacementHaut(plateauTestDeplace) != expected) {throw runtime_error(erreur);}
    expected = {{0, 0, 0, 0}, {0, 0, 2, 4}, {4, 0, 8, 8}, {4, 4, 16, 2}};
    if (deplacementBas(plateauTestDeplace) != expected) {throw runtime_error(erreur);}
    if (
        deplacement(plateauTestDeplace, 4) != deplacementGauche(plateauTestDeplace)
        or deplacement(plateauTestDeplace, 3) != deplacementBas(plateauTestDeplace)
        or deplacement(plateauTestDeplace, 2) != deplacementDroite(plateauTestDeplace)
        or deplacement(plateauTestDeplace, 1) != deplacementHaut(plateauTestDeplace)
    ) {throw runtime_error(erreur);}

    //estTermine
    Plateau nonTermine = {
        {2, 2, 4, 8},
        {4, 8, 16, 2},
        {2, 4, 8, 2},
        {4, 2, 2, 4},
    };
    Plateau termine = {
        {2, 4, 2, 4},
        {4, 2, 4, 2},
        {2, 8, 2, 8},
        {16, 32, 4, 2},
    };
    if (estTermine(nonTermine) or estTermine(plateauTestDeplace)) {
        throw runtime_error("Erreur dans les tests : estTermine() identifie comme perdu un plateau qui peut encore être déplacé");
    }
    if (not estTermine(termine)) {
        throw runtime_error("Erreur dans les tests : estTermine() n'identifie pas comme perdu un plateau qui ne peut plus être déplacé");
    }

    //estGagnant
    Plateau vide = plateauVide();
    Plateau gagnant = {{0, 2, 4, 8}, {4, 16, 256, 2048}, {1024, 512, 128, 64}, {2, 2, 8, 32}};
    if (estGagnant(vide) or not estGagnant(gagnant)) {
        throw runtime_error("Erreur dans les tests : estGagnant() doit identifier correctement les plateaux gagnants");
    }

    //dessine & ajouteCase
    dessine(jeuTest);
    jeuTest[0][3] = 16;
    dessine(jeuTest);
    jeuTest[3][3] = 1024;
    dessine(jeuTest);
    dessine(ajouteCase(jeuTest, tireDeuxOuQuatre()));
    dessine(ajouteCase(plateauInitial(), tireDeuxOuQuatre()));
}
