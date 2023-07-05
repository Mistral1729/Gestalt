#include "Sara.h"

namespace Tiger
{
	Sara::Sara(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 1"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 2"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 3"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 4"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 5"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 6"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 7"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 8"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 9"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 10"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 11"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 12"));

		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 1"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 2"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 3"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 4"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 5"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 6"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 7"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 8"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 9"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 10"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 11"));

		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 1"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 2"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 3"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 4"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 5"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 6"));
		_jumpingFrames.push_back(_data->assets.GetTexture("Jump Frame 7"));

		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 1"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 2"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 3"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 4"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 5"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 6"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 7"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 8"));
		_crouchingFrames.push_back(_data->assets.GetTexture("Crouch Frame 9"));

		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 1"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 2"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 3"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 4"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 5"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 6"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 7"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 8"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 9"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 10"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 11"));
		_flippingFrames.push_back(_data->assets.GetTexture("Flip Frame 12"));

		_rollingFrames.push_back(_data->assets.GetTexture("Roll Frame 1"));
		_rollingFrames.push_back(_data->assets.GetTexture("Roll Frame 2"));
		_rollingFrames.push_back(_data->assets.GetTexture("Roll Frame 3"));
		_rollingFrames.push_back(_data->assets.GetTexture("Roll Frame 4"));
		_rollingFrames.push_back(_data->assets.GetTexture("Roll Frame 5"));

		_saraSprite.setTexture(_standingFrames.at(_animationIterator));
		_saraSprite.setPosition(0.2 * SCREEN_WIDTH, SCREEN_HEIGHT - 50);
	}

	void Sara::AnimateStanding(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (STAND_ANIMATION_DURATION / _standingFrames.size()))
		{
			if (_animationIterator < _standingFrames.size() - 1)	_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_standingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateRunning(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (RUN_ANIMATION_DURATION / _runningFrames.size()))
		{
			if (_animationIterator < _runningFrames.size() - 1)		_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_runningFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateJumping(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (JUMP_ANIMATION_DURATION / _jumpingFrames.size()))
		{
			if (_animationIterator < _jumpingFrames.size() - 1)		_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_jumpingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateCrouching(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (CROUCH_ANIMATION_DURATION / _crouchingFrames.size()))
		{
			if (_animationIterator < _crouchingFrames.size() - 1)	_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_crouchingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateFlipping(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (FLIP_ANIMATION_DURATION / _flippingFrames.size()))
		{
			if (_animationIterator < _flippingFrames.size() - 1)	_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_flippingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateRolling(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (ROLL_ANIMATION_DURATION / _rollingFrames.size()))
		{
			if (_animationIterator < _rollingFrames.size() - 1)		_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_rollingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::Draw()
	{
		_data->window.draw(_saraSprite);
	}
}