#include "InputManager.h"

#define MOUSE_POS_WINDOW sf::Mouse::getPosition(window)

namespace Tiger
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		return sf::Mouse::isButtonPressed(button) && object.getGlobalBounds().contains(MOUSE_POS_WINDOW.x, MOUSE_POS_WINDOW.y);
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return MOUSE_POS_WINDOW;
	}
}