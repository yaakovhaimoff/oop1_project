#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "macros.hpp"

class Resources {
public:
	Resources();
	~Resources();

	static Resources& pToRsc();

	sf::Texture* getTexture(int name) { return &m_texture[name];}
	sf::SoundBuffer* getSound(int name) { return &m_soundsBuffer[name]; }
	sf::Font* getFont() { return &m_font; }

private:
	void loadResources();
	std::vector<sf::Texture> m_texture;	
	std::vector<sf::SoundBuffer> m_soundsBuffer;
	sf::Font m_font;
};