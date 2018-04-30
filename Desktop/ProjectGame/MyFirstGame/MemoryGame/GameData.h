#ifndef GAMEDATA_H_INCLUDED
#define GAMEDATA_H_INCLUDED

class Match {
public:
    int Move;
    int HighScore;

    void Update(int);
    void Init();
};

#endif // GAMEDATA_H_INCLUDED
