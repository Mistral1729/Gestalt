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
		void AnimateJumping(float dt);
		void AnimateCrouching(float dt);
		void AnimateFlipping(float dt);
		void AnimateRolling(float dt);
		void Update(float dt);
		void Draw();

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _saraSprite;
		sf::Vector2f _pos, _vel;
		const float _g = 10.f, _yOffset = 135.f;

		std::vector<sf::Texture> _standingFrames;
		std::vector<sf::Texture> _runningFrames;
		std::vector<sf::Texture> _jumpingFrames;
		std::vector<sf::Texture> _rollingFrames;
		std::vector<sf::Texture> _flippingFrames;
		std::vector<sf::Texture> _crouchingFrames;

		unsigned int _animationIterator;
	};
}