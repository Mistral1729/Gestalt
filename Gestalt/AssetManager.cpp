#include "AssetManager.h"

#define MUSIC_VOLUME 100.f

namespace Tiger
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}

	void AssetManager::LoadSound(std::string name, std::string fileName)
	{
		sf::SoundBuffer buffer;

		if (buffer.loadFromFile(fileName))
		{
			this->_sounds[name].setBuffer(buffer);
		}
	}

	sf::Sound& AssetManager::GetSound(std::string name)
	{
		return this->_sounds.at(name);
	}

	void AssetManager::LoadMusic(std::string fileName)
	{
		if (_music.openFromFile(fileName))
		{
			_music.setVolume(0.6 * MUSIC_VOLUME);
			_music.play();
		}
	}
}