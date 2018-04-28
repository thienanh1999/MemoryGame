#include <iostream>
#include "Game.h"
#include "GameData.h"
#include <SDL.h>
using namespace std;

int main(int argc, char* args[])
{
    Graph g;
    Board board;
    board.Gen();
    board.Print();
    g.CreatGameWindow(board.Width, board.Height, board.Map);
    g.InitMap(board);
    SDL_Delay(10000);
    return 0;
}
