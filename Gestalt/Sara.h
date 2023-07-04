#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Sara
	{
	public:
		Sara(GameDataRef data);

		void AnimateStanding(float dt);
		void AnimateRunning(float dt);
		void Draw();

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _saraSprite;

		std::vector<sf::Texture> _standingFrames;
		std::vector<sf::Texture> _runningFrames;
		std::vector<sf::Texture> _jumpingFrames;
		std::vector<sf::Texture> _rollingFrames;
		std::vector<sf::Texture> _flippingFrames;
		std::vector<sf::Texture> _crouchingFrames;

		unsigned int _animationIterator;
	};
}