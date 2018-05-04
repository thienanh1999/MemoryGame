#include <iostream>
#include "Game.h"
#include "GameData.h"
#include <SDL.h>
using namespace std;

Graph g;
Board board;
Match match;
bool Start;
bool quit = false;

void mousePress(SDL_MouseButtonEvent& bt)
{
    int x, y;
    if (bt.button == SDL_BUTTON_LEFT)
    {
        SDL_GetMouseState(&x,&y);
        //cout << x << " " << y << endl;
        if (250 <= x && x <= 350 && 420 <= y && y <= 520)
        {
            Start = true;
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
    Start = false;
    board.Gen();
    match.Init();
    //Init map & score

    board.Print();
    //Print key

    g.DrawBackground();
    g.InitMap(board);
    g.PrintScore(match);
    g.UpdateHighscore(match);
    g.PutItem(250,420,30);
    //Display Game

    while (!quit) {
            SDL_Event event;
            if (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mousePress(event.button);
                    if (Start)
                        return;
                }
                if (event.type == SDL_QUIT)
                    quit = true;
            }
        }
    //Playgame
}

int main(int argc, char* args[])
{
    g.CreatGameWindow();
    g.DrawBackground();
    g.PutItem(250,420,19);
    //250-350 ; 420-520
    while (!quit) {
            SDL_Event event;
            if (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mousePress(event.button);
                    if (Start)
                        Play();
                }
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
        }

    SDL_DestroyWindow(g.Window);
    SDL_Quit();
    return 0;
}
