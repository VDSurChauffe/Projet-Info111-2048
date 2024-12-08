#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_ttf.h>
#include "modele.hpp"

using namespace std;
using Plateau = vector<vector<int>>;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    //Teste automatiquement les fonctions de modele.hpp
    //Pour ce faire il suffit simplement de décommenter la ligne ci-dessous
    //tests();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL init failed: " << SDL_GetError();
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow(
        "2048",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        500, 600,
        0
    );
    if (window == NULL) {
        cout << "Window init failed: " << SDL_GetError();
        return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
    if (ren == NULL) {
        cout << "Renderer init failed: " << SDL_GetError();
        return 1;
    }
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    SDL_Event event;
    bool win_running = true;
    if (TTF_Init() != 0) {
        cout << SDL_GetError();
    }
    TTF_Font *font_small = TTF_OpenFont("./Clear Sans/ClearSans-Bold.ttf", 18);
    TTF_Font *font_title = TTF_OpenFont("./Clear Sans/ClearSans-Bold.ttf", 72);
    if (font_small == NULL) {cout << SDL_GetError();}
    int quatresNaturels = 0;
    int tirage;
    int score;
    int max_score = 0;
    vector<int> arr_frames = {0, 0, 0, 0};
    Plateau plateauDuJeu = plateauInitial();
    Plateau plateauPrecedent = plateauVide();
    quatresNaturels = scorePlateau(plateauDuJeu, quatresNaturels) / 4;
    //on met à jour la variable des 4 pour éviter d'avoir 4-8 points en trop si le plateau de départ contient des 4
    const Uint8* keyboard;
    int mouse_x = 0, mouse_y = 0;
    bool restart_fait = false;

    const int frame_length = 10;
    int frameStart, frameTime;

    vector<SDL_Color> classic_set = {
        {255, 255, 255, 255}, //Arrière-plan du jeu
        {127, 127, 127, 255}, //Couleur du plateau
        {191, 191, 191, 255}, //Couleur des cases vides
        {63, 63, 63, 255}, //Couleur du texte
        {255, 255, 255, 127}, //Couleur de superposition pour les parties perdues
        {255, 255, 255, 255}, //Couleurs de 2 à 2048
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
        {0, 0, 0, 255} //Couleur choisie au-delà de 2048
    };

    while (win_running) {
        frameStart = SDL_GetTicks();

        if (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                win_running = false;
            }
            if (event.type == SDL_MOUSEMOTION) {
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (collision(mouse_x, mouse_y, 55, 120, 135, 35) and not restart_fait) {
                    restart_fait = true;
                    plateauDuJeu = plateauInitial();
                    plateauPrecedent = plateauVide();
                    score = scorePlateau(plateauDuJeu, 0);
                    quatresNaturels = score / 4;
                    score = 0;
                }
            }
            if (event.type == SDL_MOUSEBUTTONUP) {
                restart_fait = false;
            }
        }

        keyboard = SDL_GetKeyboardState(NULL);
        plateauPrecedent = plateauDuJeu;
        if (keyboard[SDL_SCANCODE_W] or keyboard[SDL_SCANCODE_UP]) {
            if (arr_frames[0] != 0) {arr_frames[0]--;}
            else {
                plateauDuJeu = deplacement(plateauDuJeu, 1);
                arr_frames[0] = 50;
            }
        } else {arr_frames[0] = 0;}
        if (keyboard[SDL_SCANCODE_A] or keyboard[SDL_SCANCODE_LEFT]) {
            if (arr_frames[1] != 0) {arr_frames[1]--;}
            else {
                plateauDuJeu = deplacement(plateauDuJeu, 4);
                arr_frames[1] = 50;
            }
        } else {arr_frames[1] = 0;}
        if (keyboard[SDL_SCANCODE_S] or keyboard[SDL_SCANCODE_DOWN]) {
            if (arr_frames[2] != 0) {arr_frames[2]--;}
            else {
                plateauDuJeu = deplacement(plateauDuJeu, 3);
                arr_frames[2] = 50;
            }
        } else {arr_frames[2] = 0;}
        if (keyboard[SDL_SCANCODE_D] or keyboard[SDL_SCANCODE_RIGHT]) {
            if (arr_frames[3] != 0) {arr_frames[3]--;}
            else {
                plateauDuJeu = deplacement(plateauDuJeu, 2);
                arr_frames[3] = 50;
            }
        } else {arr_frames[3] = 0;}
        if (not estTermine(plateauDuJeu)) {
            if (plateauPrecedent != plateauDuJeu) {
                tirage = tireDeuxOuQuatre();
                if (tirage == 4) {quatresNaturels++;}
                plateauDuJeu = ajouteCase(plateauDuJeu, tirage);
            }
        }
        score = scorePlateau(plateauDuJeu, quatresNaturels);
        if (score > max_score) {
            max_score = score;
        }

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frame_length) {
            SDL_Delay(frame_length - frameTime); //on ajoute un temps d'attente pour limiter le jeu à 100fps
        }
        dessineGUI(ren, classic_set, font_small, font_title, plateauDuJeu, score, max_score);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
