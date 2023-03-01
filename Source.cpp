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

	RenderWindow tetris_window(VideoMode(500,800), "Tetris", Style::Default |Style::Titlebar| Style::Close | Style::Resize);
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
				}
			}
		}
	}
//Update


//Render
	tetris_window.clear();
	/*
	
		.....game....

	*/

	tetris_window.display();//making new frames 

	return 0;
}