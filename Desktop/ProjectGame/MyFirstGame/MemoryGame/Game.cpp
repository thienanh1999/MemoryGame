#include "Game.h"
#include <bits/stdc++.h>
#include "GameData.h"
#include <SDL.h>
#include <SDL_image.h>
bool Board :: Valid()
{
    return (Width > 0) && (Height > 0) && (Width*Height % 2 == 0);
}

void Board :: Gen()
{
    Width = 8;
    Height = 4;
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
    {
        for (int j = 1; j <= Width; j++)
        {
            dem++;
            Map[i][j] = a[dem];
            MapShow[i][j] = 1;
        }
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

void Graph :: CreatGameWindow(int x, int y, int Map[50][50])
{
    Window = NULL;
    Surface = NULL;
    SDL_Surface* background = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG);

    Window = SDL_CreateWindow("Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    //name, vi tri x, vi tri y, width, height, ability
    Surface = SDL_GetWindowSurface(Window);
    //background = SDL_LoadBMP("src/Background/background.bmp");
    background = IMG_Load("src/Background/background.jpg");
    SDL_BlitSurface(background, NULL, Surface, NULL);
    SDL_UpdateWindowSurface(Window);
    SDL_Delay(1000);
    SDL_FreeSurface(background);
   // SDL_DestroyWindow(Window);
   // SDL_Quit();
}

void Graph::CloseWindow()
{
    SDL_DestroyWindow(Window);
   // SLD_Quit();
}

void Graph::InitMap(Board board)
{
    int X = 50;
    int Y = 50;
    for (int i = 1; i <= board.Height; i++)
    {
        Y = 50;
        for (int j = 1; j <= board.Width; j++)
        {
            if (board.MapShow[i][j] == false)
                PutItem(Y,X,0);
            else
                PutItem(Y,X,board.Map[i][j]);
            PosX[i][j] = X;
            PosY[i][j] = Y;
            Y += 60;
        }
        X += 60;
    }
}

void Graph::PutItem(int x, int y, int id)
{
    SDL_Surface* item = NULL;
    SDL_Rect dstrect = { x, y, 0, 0 };
    switch (id)
    {
    case 0:
        {
            item = IMG_Load("src/Pictures/item0.jpg");
            break;
        }
    case 1:
        {
            item = IMG_Load("src/Pictures/item1.jpg");
            break;
        }
    case 2:
        {
            item = IMG_Load("src/Pictures/item2.jpg");
            break;
        }
    case 3:
        {
            item = IMG_Load("src/Pictures/item3.jpg");
            break;
        }
    case 4:
        {
            item = IMG_Load("src/Pictures/item4.jpg");
            break;
        }
    case 5:
        {
            item = IMG_Load("src/Pictures/item5.jpg");
            break;
        }
    case 6:
        {
            item = IMG_Load("src/Pictures/item6.jpg");
            break;
        }
    case 7:
        {
            item = IMG_Load("src/Pictures/item7.jpg");
            break;
        }
    case 8:
        {
            item = IMG_Load("src/Pictures/item8.jpg");
            break;
        }
    case 9:
        {
            item = IMG_Load("src/Pictures/item9.jpg");
            break;
        }
    case 10:
        {
            item = IMG_Load("src/Pictures/item10.jpg");
            break;
        }
    case 11:
        {
            item = IMG_Load("src/Pictures/item11.jpg");
            break;
        }
    case 12:
        {
            item = IMG_Load("src/Pictures/item12.jpg");
            break;
        }
    case 13:
        {
            item = IMG_Load("src/Pictures/item13.jpg");
            break;
        }
    case 14:
        {
            item = IMG_Load("src/Pictures/item14.jpg");
            break;
        }
    case 15:
        {
            item = IMG_Load("src/Pictures/item15.jpg");
            break;
        }
    case 16:
        {
            item = IMG_Load("src/Pictures/item16.jpg");
            break;
        }
    }
    SDL_BlitSurface(item, NULL, Surface, &dstrect);
    SDL_UpdateWindowSurface(Window);
    SDL_FreeSurface(item);
}

void Graph::Mouse()
{
    int X, Y;
    SDL_Event* e;
    if (e -> type == SDL_MOUSEBUTTONDOWN)
        printf("x");
}
