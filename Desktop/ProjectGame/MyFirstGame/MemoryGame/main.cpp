#include <iostream>
#include "Game.h"
#include "GameData.h"
#include <SDL.h>
using namespace std;

Graph g;
Board board;
Match match;
bool Replay;

void mousePress(SDL_MouseButtonEvent& bt)
{
    int x, y;
    if (bt.button == SDL_BUTTON_LEFT)
    {
        SDL_GetMouseState(&x,&y);
        //cout << x << " " << y << endl;
        if (250 <= x && x <= 350 && 420 <= y && y <= 520)
        {
            Replay = true;
            return;
        }
        g.Click(y,x,board,match);
        if (board.Done == 0)
        {
            g.PutItem(50,50,18);
        }
    }
}

void Play()
{
    board.Gen();
    match.Init();
    //Init map & score

    board.Print();
    //Print key

    g.InitMap(board);
    g.PrintScore(match);
    g.UpdateHighscore(match);
    //Display Game

    while (true) {
            SDL_Event event;
            if (SDL_PollEvent(&event) != 0) {
                if (event.type = SDL_MOUSEBUTTONDOWN)
                    mousePress(event.button);
            }
        }
    Replay = false;
    //Playgame
}

int main(int argc, char* args[])
{
    g.CreatGameWindow();
    g.PutItem(250,420,19);
    //250-350 ; 420-520
    while (true) {
            SDL_Event event;
            if (SDL_PollEvent(&event) != 0) {
                if (event.type = SDL_MOUSEBUTTONDOWN)
                {
                    mousePress(event.button);
                    if (Replay)
                        Play();
                }
            }
        }
    return 0;
}
