#include "GameData.h"
#include <bits/stdc++.h>

void Match :: Init()
{
    Win = 0;
    Lose = 0;
}

void Match :: Show()
{
    printf("%d %d",Win,Lose);
}

void Match :: Update(bool IsWin)
{
    if (IsWin) Win++;
    else Lose++;
}
