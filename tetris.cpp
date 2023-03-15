#include "tetris.h"
#include<iostream>

void tetris::tet_event()
{
    sf::Event ev;
    while (Game::window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            window->close();

        if (ev.type == sf::Event::KeyPressed)
            if (ev.key.code == sf::Keyboard::Up) rotate = true;
            else if (ev.key.code ==sf:: Keyboard::Left) dx = -1;
            else if (ev.key.code ==sf:: Keyboard::Right) dx = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) delay = 0.05;
}

void tetris::update_timer(float time)
{
	this->timer += time;
}

bool tetris::space_check()
{
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;

    return 1;
}

void tetris::tet_move()
{
    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
    if (!space_check()) for (int i = 0; i < 4; i++) a[i] = b[i];


}

void tetris::tet_rotate()
{
    if (rotate) {
        Point p = a[1]; //center of rotation
        for (int i = 0; i < 4; i++)
        {
            int x = a[i].y - p.y;
            int y = a[i].x - p.x;
            a[i].x = p.x - x;
            a[i].y = p.y + y;
        }
        if (!space_check()) for (int i = 0; i < 4; i++) a[i] = b[i];
    }
}

void tetris::tet_timer()
{
    if (timer > delay)
    {
        for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

        if (!space_check())
        {
            for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
            colorNum = 1 + rand() % 7;
            int n = rand() % 7;
            for (int i = 0; i < 4; i++)
            {
                a[i].x = figures[n][i] % 2;
                a[i].y = figures[n][i]/2;
            }
        }

        timer = 0;
    }
}

void tetris::tet_check()
{
    int k = M - 1;
    for (int i = M - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (field[i][j]) count++;
            field[k][j] = field[i][j];
        }
        if (count < N) {
            k--;
        }
        if (count == N) {
            score++;
        }
    }
    for (int j = 0; j < N; j++)
        {
            if (field[0][j])  std::cout<<"game over";
    
        }
   
    dx = 0; rotate = 0; delay = 0.3;
}

void tetris::tet_draw()
{
    Game::window->clear(sf::Color::White);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
        {
            if (field[i][j] == 0) continue;
            s.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
            s.setScale(sf::Vector2f(2, 2));
            s.setPosition(j * 36, i * 36);
            s.move(28, 30); //offset
            window->draw(s);
        }
    }
    int t = 4;
    for (int i = 0; i < 4; i++)
    {
        s.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
        //s.setPosition((a[i].x * 18, a[i].y * 18);
       // a[i].x+=6;
        /*if (a[i]) {
            a[i].x += t;
            t++;
        }
        else {
            t = 1;
        }*/
        s.setScale(sf::Vector2f(2, 2));
        s.setPosition((a[i].x)* 36, (a[i].y) * 36);
        s.move(28, 30); //offset
        window->draw(s);
    }
    sf::Font font;
    font.loadFromFile("fonts/Ariel.ttf");
    sf::Text text;
    text.setFont(font);
    std::string scoreString = std::to_string(score);
    text.setString("score ::" + scoreString);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window->draw(text);
    window->display();
}
