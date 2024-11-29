#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include "modele.hpp"

using namespace std;

using Plateau = vector<vector<int>> ;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    //Teste automatiquement les fonctions de modele.hpp
    //Pour ce faire il suffit simplement de décommenter la ligne ci-dessous
    //tests();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow(
        "2048",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        500, 600,
        0
    );
    if (window == NULL) {return 1;}
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
    if (ren == NULL) {return 1;}
    SDL_Event event;
    bool win_running = true;

    int mode_interaction = 1;
    int score = 0;
    int quatresNaturels = 0;
    int tirage;
    Plateau plateauDuJeu = plateauInitial();
    Plateau plateauPrecedent = plateauVide();
    string commande = "";
    int arr_frames = 20;
    int frame_length = 10;
    int frameStart, frameTime;
    vector<SDL_Color> classic_set = {
        {255, 255, 255, 255},
        {127, 127, 127, 255},
        {191, 191, 191, 255},
        {255, 255, 255, 255},
        {255, 255, 191, 255},
        {255, 191, 127, 255},
        {255, 63, 31, 255},
        {255, 31, 31, 255},
        {255, 0, 0, 255},
        {127, 255, 63, 255},
        {127, 255, 93, 255},
        {192, 255, 63, 255},
        {255, 255, 0, 255},
        {127, 255, 0, 255},
        {0, 0, 0, 255}
    };

    while (win_running) {
        frameStart = SDL_GetTicks();
        if (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                win_running = false;
            }
        }
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frame_length) {
            SDL_Delay(frame_length - frameTime); //on ajoute un temps d'attente pour limiter le jeu à 100fps
        }
        dessineGUI(ren, classic_set, plateauDuJeu);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();

    while (true) {
        dessine(plateauDuJeu);

        if (
            ((commande == "w" or commande == "W") and mode_interaction == 1)
            or ((commande == "z" or commande == "Z") and mode_interaction == 2)
        ) {
            plateauDuJeu = deplacement(plateauDuJeu, 1);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (
            ((commande == "a" or commande == "A") and mode_interaction == 1)
            or ((commande == "q" or commande == "Q") and mode_interaction == 2)
        ) {
            plateauDuJeu = deplacement(plateauDuJeu, 4);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "s" or commande == "S") {
            plateauDuJeu = deplacement(plateauDuJeu, 3);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "d" or commande == "D") {
            plateauDuJeu = deplacement(plateauDuJeu, 2);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else {
            cout << "Commande saisie inconnue." << endl;
        }

        if (estTermine(plateauDuJeu) == true) {
            cout << "Partie terminée ! ";
            if (estGagnant(plateauDuJeu) == true) {
                cout << "Vous avez gagné !" << endl << endl << "Sortie du programme. Au revoir !";
            } else {
                cout << "Vous avez perdu !" << endl << endl << "Sortie du programme. Au revoir !";
            }
            break;
        } else {
            if (estGagnant(plateauDuJeu)) {
                cout << "Vous avez gagné ! Continuez pour atteindre le meilleur score possible !" << endl;
            }
            if (plateauPrecedent != plateauDuJeu) {
                tirage = tireDeuxOuQuatre();
                if (tirage == 4) {quatresNaturels++;}
                plateauDuJeu = ajouteCase(plateauDuJeu, tirage);
            }
        }
    }

    return 0;
}
