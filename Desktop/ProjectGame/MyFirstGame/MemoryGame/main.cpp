#include <iostream>
#include "Game.h"
#include "GameData.h"
#include <SDL.h>
using namespace std;

int main(int argc, char* args[])
{
    Graph g;
    Board board;
    g.CreatGameWindow(board.Width, board.Height, board.Map);
    return 0;
}
