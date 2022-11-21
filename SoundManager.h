#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class SoundManager
{
private:
	sf::SoundBuffer ballPaddleHitBuffer;
	sf::Sound ballPaddleHitSfx;
	sf::SoundBuffer ballBounceBuffer;
	sf::Sound ballBounceSfx;
	sf::SoundBuffer ballScoreBuffer;
	sf::Sound ballScoreSfx;
	sf::SoundBuffer winBuffer;
	sf::Sound winSfx;
public:
	SoundManager();
	void playSfx(int whichSound);
};

#endif