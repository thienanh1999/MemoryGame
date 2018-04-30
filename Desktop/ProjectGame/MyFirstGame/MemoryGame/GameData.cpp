#include "GameData.h"
#include <bits/stdc++.h>
using namespace std;

void Match :: Init()
{
    freopen("src/GameData/Highscore.txt","r",stdin);
    cin >> HighScore;
    Move = 0;
}

void Match :: Update(int score)
{
    HighScore = min(HighScore,score);
    freopen("src/GameData/Highscore.txt","w",stdout);
    cout << HighScore;
}
