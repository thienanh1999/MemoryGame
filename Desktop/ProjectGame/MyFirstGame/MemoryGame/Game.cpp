#include "Game.h"
#include <bits/stdc++.h>
#include "GameData.h"
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
bool Board :: Valid()
{
    return (Width > 0) && (Height > 0) && (Width*Height % 2 == 0);
}

void Board :: Gen()
{
    Width = 8;
    Height = 4;
    Done = 32;
    srand(time(NULL));
    int numOfPairs = Width*Height/2;
    int a[Width*Height+1];
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
            MapShow[i][j] = 0;
        }
    }
    Fliped = 0;
    FlipingX = 0;
    FlipingY = 0;
}

void Board :: Print()
{
    freopen("src/GameData/Key.txt","w",stdout);
    for (int i = 1; i <= Height; i++)
    {
        for (int j = 1; j <= Width; j++)
            std::cout << Map[i][j] << " ";
        std::cout << '\n';
    }
}

void Board :: Flip(int x, int y,Match& match)
{
    if (MapShow[x][y] == 1 || MapShow[x][y] == 2) return;
    match.Move++;
    Fliped++;
    MapShow[x][y] = 1;
   // printf("%d %d\n",FlipingX,FlipingY);
    if (Fliped == 2)
    {
        if (Map[FlipingX][FlipingY] == Map[x][y])
        {
            MapShow[x][y] = 2;
            MapShow[FlipingX][FlipingY] = 2;
            Done -= 2;
            Fliped = 0;
            FlipingX = 0;
            FlipingY = 0;
            if (Done == 0) EndGame(match.Move,match);
           // printf("matched");
        }
        else
        {
            Fliped = 0;
            MapShow[x][y] = 0;
            MapShow[FlipingX][FlipingY] = 0;
            FlipingX = 0;
            FlipingY = 0;
           // printf("unmatched");
        }
    }
    else
    {
        FlipingX = x;
        FlipingY = y;
    }
}

void Board :: EndGame(int score, Match& match)
{
    match.Update(score);
}

void Graph :: CreatGameWindow()
{
    PreX = 0;
    PreY = 0;
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
    SDL_FreeSurface(background);
   // SDL_DestroyWindow(Window);
   // SDL_Quit();
}

void Graph::CloseWindow()
{
    SDL_DestroyWindow(Window);
//    SLD_Quit();
}

void Graph::InitMap(Board board)
{
    auto start = chrono::steady_clock::now();
    int X = 50;
    int Y = 50;
    for (int i = 1; i <= board.Height; i++)
    {
        Y = 50;
        for (int j = 1; j <= board.Width; j++)
        {
            if (board.MapShow[i][j] == 0) PutItem(Y,X,0);
            if (board.MapShow[i][j] == 1) PutItem(Y,X,board.Map[i][j]);
            if (board.MapShow[i][j] == 2) PutItem(Y,X,17);
            PosX[i][j] = X;
            PosY[i][j] = Y;
            Y += 60;
        }
        X += 60;
    }
    auto end = chrono::steady_clock::now();
   /* cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();*/
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
    case 17:
        {
            item = IMG_Load("src/Pictures/item17.jpg");
            break;
        }
    case 18:
        {
            item = IMG_Load("src/Pictures/win.jpg");
            break;
        }
    case 19:
        {
            item = IMG_Load("src/Pictures/replay.jpg");
            break;
        }
    case 20:
        {
            item = IMG_Load("src/Number/0.jpg");
            break;
        }
    case 21:
        {
            item = IMG_Load("src/Number/1.jpg");
            break;
        }
    case 22:
        {
            item = IMG_Load("src/Number/2.jpg");
            break;
        }
    case 23:
        {
            item = IMG_Load("src/Number/3.jpg");
            break;
        }
    case 24:
        {
            item = IMG_Load("src/Number/4.jpg");
            break;
        }
    case 25:
        {
            item = IMG_Load("src/Number/5.jpg");
            break;
        }
    case 26:
        {
            item = IMG_Load("src/Number/6.jpg");
            break;
        }
    case 27:
        {
            item = IMG_Load("src/Number/7.jpg");
            break;
        }
    case 28:
        {
            item = IMG_Load("src/Number/8.jpg");
            break;
        }
    case 29:
        {
            item = IMG_Load("src/Number/9.jpg");
            break;
        }
    }
    SDL_BlitSurface(item, NULL, Surface, &dstrect);
    SDL_UpdateWindowSurface(Window);
    SDL_FreeSurface(item);
}

void Graph::Click(int x, int y, Board& board,Match& match)
{
    for (int i = 1; i <= board.Height; i++)
        for (int j = 1; j <= board.Width; j++)
            if (PosX[i][j] <= x && x <= PosX[i][j]+50)
                if (PosY[i][j] <= y && y <= PosY[i][j]+50)
                {
                    if (PreX == x && PreY == y) return;
                 //   printf("%d %d\n", i , j);
                    if (board.Fliped == 1 && board.MapShow[i][j] == 0
                        && board.Map[i][j] != board.Map[board.FlipingX][board.FlipingY])
                    {
                        board.MapShow[i][j] = 1;
                        InitMap(board);
                        board.MapShow[i][j] = 0;
                        board.Flip(i,j,match);
                        PrintScore(match);
                    }
                    else
                    {
                    board.Flip(i,j,match);
                    InitMap(board);
                    PrintScore(match);
                    }
                    PreX = x; PreY = y;
                    return;
                }
}

void Graph::PrintScore(Match match)
{
    SDL_Surface* m = NULL;
    SDL_Rect dstrect = { 150, 300, 0, 0 };
    m = IMG_Load("src/Number/move.jpg");
    SDL_BlitSurface(m, NULL, Surface, &dstrect);
    SDL_UpdateWindowSurface(Window);
    SDL_FreeSurface(m);
    //Print move item

    int mo = match.Move;
    int X = 350;
    for (int i = 1; i <= 3; i++)
    {
        PutItem(X,295,(mo%10)+20);
        mo /= 10;
        X-=50;
    }
}

void Graph::UpdateHighscore(Match match)
{
    SDL_Surface* high = NULL;
    SDL_Rect dstrect = { 150, 350, 0, 0 };
    high = IMG_Load("src/Number/Highscore.jpg");
    SDL_BlitSurface(high, NULL, Surface, &dstrect);
    SDL_UpdateWindowSurface(Window);
    SDL_FreeSurface(high);
    //print highscore item

    int highscore = match.HighScore;
    int X = 450;
    for (int i = 1; i <= 3; i++)
    {
        PutItem(X,345,(highscore%10)+20);
        highscore /= 10;
        X-=50;
    }
}
