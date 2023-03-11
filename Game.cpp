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
}

Game::~Game()
{
	delete this->window;
}

const bool Game::game_on() const
{
	return this->window->isOpen();
}
