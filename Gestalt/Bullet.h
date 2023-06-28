#pragma once
#include "Game.h"

class Bullet 
{
private:
	sf::Sprite spr;
	sf::Vector2f vel;
public:
	Bullet(sf::Texture* tex, sf::Vector2f vel, sf::Vector2f pos, sf::IntRect rect) 
	{
		this->vel = vel;
		spr.setTexture(*tex);
		spr.setTextureRect(rect);
		spr.setPosition(pos);
	}

	// Update the position of the bullet
	void update(double timeElapsed) 
	{
		spr.setPosition(spr.getPosition().x + timeElapsed * vel.x, spr.getPosition().y + timeElapsed * vel.y);
	}

	sf::Sprite* getSprite() 
	{
		return &spr;
	}
};