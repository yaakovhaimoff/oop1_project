#include "Resources.hpp"


Resources::Resources()
{
	this->loadResources();
}

Resources::~Resources()
{}

Resources& Resources::pToRsc()
{
	static Resources p;
	return p;
}

void Resources::loadResources()
{
	sf::Texture tex;
	sf::SoundBuffer sound;

	if (!m_font.loadFromFile(FontName))
		std::cout << "fail to load font";

	for (int i = 0 ; i < SOUNDS_NAMES.size() ; i++)
	{
		if (!sound.loadFromFile(SOUNDS_NAMES[i]))
			std::cout << "fail to load " << i << " sound";
		m_soundsBuffer.push_back(sound);
	}

	for (int i = 0; i < NAMES.size(); i++)
	{
		if (!tex.loadFromFile(NAMES[i]))
			std::cout << "fail to load " << i << " texture";
		m_texture.push_back(tex);
	}
}