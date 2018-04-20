#include "Game.h"
#include <bits/stdc++.h>
#include "GameData.h"
bool Board :: Valid()
{
    return (Width > 0) && (Height > 0) && (Width*Height % 2 == 0);
}

void Board :: Gen()
{
    srand(time(NULL));
    int numOfPairs = Width*Height/2;
    int a[Width*Height];
    for (int i = 1; i <= Width*Height; i++)
        a[i] = (i+1)/2;

    int random = rand() % (Width * Height)*10;
    for (int i = 1; i <= random; i++)
    {
        int first = rand() % (Width * Height) + 1;
        int second = rand() % (Width * Height) + 1;
        int temp;
        temp = a[first];
        a[first] = a[second];
        a[second] = temp;
    }
    int dem = 0;
    for (int i = 1; i <= Height; i++)
        for (int j = 1; j <= Width; j++)
        {
            dem++;
            Map[i][j] = a[dem];
            MapShow[i][j] = 0;
        }
    Fliped = 0;
}

void Board :: Print()
{
    for (int i = 1; i <= Height; i++)
    {
        for (int j = 1; j <= Width; j++)
            printf("%d ",Map[i][j]);
        printf("\n");
    }
}

void Board :: Flip(int x, int y)
{
    Fliped++;
    MapShow[x][y] = 1;
    if (Fliped == 2)
    {
        if (Map[FlipingX][FlipingY] == Map[x][y])
            printf("matched");
        else
        {
            Fliped = 0;
            MapShow[x][y] = 0;
            MapShow[FlipingX][FlipingY] = 0;
            printf("unmatched");
        }
    }
    else
    {
        FlipingX = x;
        FlipingY = y;
    }
}

void Board :: InitGame()
{
    for (int i = 1; i <= Height; i++)
    {
        for (int j = 1; j <= Width; j++)
            printf("%d ",0);
        printf("\n");
    }
}

void Board :: EndGame(bool IsWin, Match& match)
{
    match.Update(IsWin);
}
