#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <numbers>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{

	/**
	*
	*	VARIABLES
	*
	**/

private:

	sf::RenderWindow *window; //config taken from "config\\window.ini"
	sf::Event sfEvent; //SFML events

	std::map<std::string, sf::Keyboard::Key> supportedKeys; //supported keys
	std::map<std::string, sf::Keyboard::Key> keybinds; //keybindings

	sf::Clock dtClock; //delta time clock
	float dt; //delta time

	sf::Texture bgtex; //background texture from "resources\\faded_memories.png"
	sf::Music bgmus; //background music from "resources\\audio\\fm.ogg"
	sf::Sprite bgspr; //background sprite utilising background texture

	/**
	*	
	*	INITIALISATIONS
	*
	**/
	void initWindow(); //initialise window
	void initKeys(); //initialise supported keys
	void initStates(); //initialise states

public:

	/**
	*
	*	CONSTRUCTORS / DESTRUCTORS
	*
	**/

	/**
	*
	*	FUNCTIONS
	*
	**/


};
