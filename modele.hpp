#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;
using Plateau = vector<vector<int>>;


// Toutes les fonctions associées aux déplacements ont été écrites par Parsa
// La plupart des autres fonctions, ainsi que tests(), ont été écrites et maintenues par Victor

/** fonction inverseVector (auxiliaire)
 *  @param inp un vecteur<int>
 *  @return inp mais avec l'ordre inverse
 */
vector<int> inverseVector(vector<int> inp);

/** fonction tourneGauche (auxiliaire)
 *  @param p un plateau
 *  @return p tourné de 90 degrés vers la gauche
 */
Plateau tourneGauche(Plateau p);

/** fonction tourneDroite (auxiliaire)
 *  @param p un plateau
 *  @return p tourné de 90 degrés vers la droite
 */
Plateau tourneDroite(Plateau p);

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();

/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 **/
Plateau plateauInitial();

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau);

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau);

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  directions : 1 -> Haut, 2 -> Droite, 3 -> Bas, 4 -> Gauche (suivant le sens horaire)
 *  @param plateau le plateau
 *  @param direction un entier représentant la direction
 *  @return le plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction);

/** ajoute une case à un plateau
 * @param p un plateau, dont on suppose qu'il a au moins une case vide
 * @param k la valeur (2/4) de la case à ajouter
 * @return le plateau après apparition d'une case 2/4
 */
Plateau ajouteCase(Plateau p, int k);

/** affiche un plateau
 * @param p le plateau
 **/
void dessine(Plateau p);

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si le plateau est terminé, false sinon
 **/
bool estTermine(Plateau p);

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);

/**donne la puissance de 2 correspondant à une valeur de case 
 * @param n un entier puissance de 2
 * @return son log base 2
 **/
int logCase(int n);

/** donne le score correspondant à un plateau
 * @param jeu un plateau correspondant à l'état du jeu
 * @param nat le nombre de 4 apparus naturellement
 * @return le score du plateau
 **/
int scorePlateau(Plateau jeu, int nat);

/**détecte si un point se trouve dans un rectangle donné
 * @param x la position horizontale du point
 * @param y la position verticale du point
 * @param x_box la position horizontale du coin supérieur gauche du rectangle
 * @param y_box la position verticale du coin supérieur gauche du rectangle
 * @param w la longueur du rectange
 * @param h la hauteur du rectangle
 **/
bool collision(int x, int y, int x_box, int y_box, int w, int h);

/**calcule les dimensions en pixels d'un texte
 * @param ren le renderer SDL à utiliser
 * @param font la police à utiliser
 * @param text le texte dont on cherche les dimensions
 **/
int lenTexte(SDL_Renderer *ren, TTF_Font *font, string text);

/** affiche du texte sur la fenêtre de SDL
 * @param ren le renderer SDL à utiliser
 * @param col la couleur du texte à afficher
 * @param font la police à utiliser
 * @param text le texte à afficher
 * @param x la position horizontale du texte
 * @param y la position verticale du texte
 **/
void afficheTexte(SDL_Renderer *ren, SDL_Color col, TTF_Font *font, string text, int x, int y);

/** change la couleur active de SDL à une couleur donnée
 * @param ren le renderer SDL à utiliser
 * @param col la couleur à utiliser
 **/
void changeGUIColor(SDL_Renderer *ren, SDL_Color col);

/** dessine l'interface graphique du jeu selon l'état du plateau de jeu
 * @param ren le renderer SDL à utiliser
 * @param colset la palette de couleurs sous la forme d'un tableau de SDL_Color
 * @param theme le nom du thème à utiliser
 * @param font la police de caractères à utiliser pour le texte
 * @param font_title la police de caractères à utiliser pour le texte plus grand
 * @param jeu le plateau de jeu actuel
 * @param quatres le score actuel du jeu
 * @param max_score le record de score atteint
 **/
void dessineGUI(SDL_Renderer *ren, vector<SDL_Color> colset, string theme, TTF_Font *font, TTF_Font *font_title, Plateau jeu, int score, int max_score);

/**teste les fonctions de ce fichier pour vérifier qu'elles fonctionnent correctement
 **/
void tests();
