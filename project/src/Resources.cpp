#include "Resources.hpp"

//____________________
Resources::Resources()
{
	loadResources();
}
//____________________________
Resources &Resources::instance()
{
	static auto resource = Resources();
	return resource;
}
//_____________________________
void Resources::loadResources()
{
	if (!m_font.loadFromFile(FontName))
		std::cout << "fail to load font";

	for (int i = 0; i < SOUNDS_NAMES.size(); i++)
	{
		sf::SoundBuffer soundBuffer;
		if (!soundBuffer.loadFromFile(SOUNDS_NAMES[i]))
			std::cout << "fail to load " << i << " sound";
		m_soundsBuffer.push_back(soundBuffer);
	}
	for (int i = 0; i < m_soundsBuffer.size(); i++)
	{
		sf::Sound sound;
		sound.setBuffer(m_soundsBuffer[i]);
		m_sounds.push_back(sound);
	}
	for (int i = 0; i < NAMES.size(); i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile(NAMES[i]))
			std::cout << "fail to load " << i << " texture";
		m_texture.push_back(texture);
	}
	for (int i = 0; i < m_texture.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_texture[i]);
		m_sprites.push_back(sprite);
	}
}
//_______________________________________
void Resources::playSound(const int name)
{
	m_sounds[name].play();
	m_sounds[name].setVolume(80);
}
//________________________________________
void Resources::playInLoop(const int name)
{
	m_sounds[name].play();
	m_sounds[name].setVolume(20);
	m_sounds[name].setLoop(true);
}
//________________________________________
void Resources::stopLoop(const int name)
{
	m_sounds[name].stop();
}