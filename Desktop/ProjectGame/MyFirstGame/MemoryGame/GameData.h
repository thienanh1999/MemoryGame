#ifndef GAMEDATA_H_INCLUDED
#define GAMEDATA_H_INCLUDED

class Match {
public:
    int Win;
    int Lose;

    void Show();
    void Update(bool);
    void Init();
};

#endif // GAMEDATA_H_INCLUDED
