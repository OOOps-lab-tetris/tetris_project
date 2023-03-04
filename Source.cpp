#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace std;
using namespace sf;

int main() {
//Opening the new window//

	RenderWindow tetris_window(VideoMode(500,800), "Tetris", Style::Default |Style::Close | Style::Resize);

//to add the tiles of tetris
	RectangleShape player(Vector2f(20, 100));
	Texture t;
	player.setPosition(206.0f, 206.0f);
	t.loadFromFile("tiles.png");
	player.setTexture(&t);
	Sprite s(t);

	Event ev;

////window stuff above(just basic window design)////
	/*
		----buffer----
	*/
	
////initial game-loop
	while (tetris_window.isOpen()) {//while window open-->true when new window code true
		
		while (tetris_window.pollEvent(ev)) {

			switch (ev.type) {
			case Event::Closed:
				tetris_window.close();
				break;
			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape) {
					tetris_window.close();
					break;
					//cout << "hello";
				}
			}
		}
	}
//Update


//Render
	tetris_window.clear(Color::Black);
	//ingame
	tetris_window.draw(player);
	/*
	
		.....game....

	*/

	tetris_window.display();//making new frames 

	return 0;
}