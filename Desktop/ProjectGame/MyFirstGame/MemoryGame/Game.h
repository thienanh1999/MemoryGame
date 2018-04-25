#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "GameData.h"

class Board {
public:
    int Width;
    int Height;
    int Fliped;
    int FlipingX;
    int FlipingY;
    int Map[500][500];
    int MapShow[500][500];
    //= 0 unfliped, 1 fliped, 2 done

    bool Valid();
    void Gen();
    void Print();
    void Flip(int, int);
    void InitGame();
    void EndGame(bool, Match&);
};

class Graph{
public:
    int Width;
    int Height;

    void CreatGameWindow(int, int, int[500][500]);
};

#endif // GAME_H_INCLUDED
