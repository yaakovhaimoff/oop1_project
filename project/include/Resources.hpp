#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "macros.hpp"

class Resources
{
public:
	static Resources &instance();
	Resources(const Resources &) = delete;
	void operator=(const Resources &) = delete;

	sf::Texture &getTexture(const int name) { return m_texture[name]; }
	sf::Sound &getSound(const int name) { return m_sounds[name]; }
	sf::Font &getFont() { return m_font; }

	void playSound(const int name);
	void playInLoop(const int name);
	void stopLoop(const int name);

private:
	Resources();
	void loadResources();

	std::vector<sf::Texture> m_texture;
	std::vector<sf::SoundBuffer> m_soundsBuffer;
	std::vector<sf::Sound> m_sounds;
	sf::Font m_font;
};