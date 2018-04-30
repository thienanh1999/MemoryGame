#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "GameData.h"
#include <SDL.h>
#include <SDL_image.h>

class Board {
public:
    int Width;
    int Height;
    int Fliped;
    int FlipingX;
    int FlipingY;
    int Map[50][50];
    int MapShow[50][50];
    int Done;
    //= 0 unfliped, 1 fliped, 2 done

    bool Valid();
    void Gen();
    void Print();
    void Flip(int, int,Match&);
    void EndGame(int, Match&);
};

class Graph{
public:
    int Width;
    int Height;
    SDL_Window* Window;
    SDL_Surface* Surface;
    int PosX[50][50];
    int PosY[50][50];
    int PreX;
    int PreY;

    void CreatGameWindow(int, int, int[50][50]);
    void InitMap(Board);
    void CloseWindow();
    void PutItem(int, int, int);
    void Click(int,int,Board&,Match&);
    void PrintScore(Match);
    void UpdateHighscore(Match);
};

#endif // GAME_H_INCLUDED
