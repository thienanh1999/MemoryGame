#include <iostream>
#include "Game.h"
#include "GameData.h"
using namespace std;

int main()
{
    Board board;
    board.Width = 4;
    board.Height = 4;
    board.Gen();
    board.InitGame();
    Match match;
    match.Init();
    board.EndGame(true,match);
    match.Show();
    return 0;
}
