#include "GameData.h"
#include <bits/stdc++.h>

void Match :: Init()
{
    Move = 0;
}

void Match :: Show()
{
    printf("%d",HighScore);
}

void Match :: Update(int score)
{
    HighScore = std::max(HighScore,score);
}
