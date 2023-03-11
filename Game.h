#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<time.h>

class Game
{
protected:
	sf::RenderWindow* window;
	sf::Texture t;
	sf::Sprite s;
	sf::VideoMode vid;
	//sf::Event ev;
	void init_var();
	void init_window();
public:
	Game();
	virtual ~Game();
	const bool game_on() const;
	//Functions
};

