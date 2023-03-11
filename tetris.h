#pragma once
#include "Game.h"
class tetris :public Game
{
private:
    const int M = 20;
    const int N = 12;

    int field[20][12] = { 0 };

    struct Point
    {
        int x, y;
    } a[4], b[4];

    int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };
    int dx = 0,colorNum = 1;
    bool rotate = 0;
    float timer = 0, delay = 0.3;
public:
    void tet_event();
    void update_timer(float);
    bool space_check();
    void tet_move();
    void tet_rotate();
    void tet_timer();
    void tet_check();
    void tet_draw();
};

