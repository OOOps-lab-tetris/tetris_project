#include "Game.h"

Game::Game(){
	this->init_var();
	this->init_window();

}
void Game::init_var()
{
	this->window = nullptr;
}

void Game::init_window()
{
	vid.height = 800;
	vid.width = 490;
	this->window=new sf::RenderWindow(this->vid, "Tetris");
	t.loadFromFile("images/tiles.png");
	s = sf::Sprite(t);
	//window->setVerticalSyncEnabled(true);
	buffer.loadFromFile("Sound/beep.wav");
	line_com.setBuffer(buffer);
}

Game::~Game()
{
	delete this->window;
}

const bool Game::game_on() const
{
	return this->window->isOpen();
}
