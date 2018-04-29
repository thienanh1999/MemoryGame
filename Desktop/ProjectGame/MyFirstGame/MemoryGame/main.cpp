#include <iostream>
#include "Game.h"
#include "GameData.h"
#include <SDL.h>
using namespace std;

Graph g;
Board board;

void mousePress(SDL_MouseButtonEvent& bt)
{
    int x, y;
    if (bt.button == SDL_BUTTON_LEFT)
    {
        SDL_GetMouseState(&x,&y);
        //cout << x << " " << y << endl;
        g.Click(y,x,board);
    }
}

int main(int argc, char* args[])
{
    board.Gen();
    board.Print();
    g.CreatGameWindow(board.Width, board.Height, board.Map);
    g.InitMap(board);
    bool quit = false;
    while (true) {
            SDL_Event event;
            if (SDL_PollEvent(&event) != 0) {
                if (event.type = SDL_MOUSEBUTTONDOWN)
                    mousePress(event.button);
            }
        }
    return 0;
}
