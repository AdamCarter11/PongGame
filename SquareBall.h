#ifndef SQUAREBALL_H
#define SQUAREBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>


#include "GameObject.h"
#include "SoundManager.h"
#include "UiManager.h"

namespace gm {
	class SquareBall : public GameObject
	{
	private:
		sf::Vector2f velocity;
		sf::Text scoreText;
		sf::Text aiText;
		sf::Font textFont;
		int playerScore;
		int aiScore;
		SoundManager sfxManager;
		bool gameOver;
		UiManager uiDisplay;
	public:
		sf::RectangleShape body;	//make getter/setter for at the end

		SquareBall(const sf::Vector2f& position, const sf::Vector2f& size);

		void update(sf::RenderWindow& window);

		void render(sf::RenderWindow& window);

		//need to do this for paddle as well
		//sf::Vector2f& const getPosition() const;
		//void setPosition(const sf::Vector2f& position);

		sf::Vector2f const getVelocity() const;
		void setVelocity(sf::Vector2f newVel);

		//X1 and Y2 will be the velocity of the ball in a range from -1 to 1. For example velocity could be: (.56, -.74) which would be going right down
		//X2 will be constants that flip based on what side of the field the ball is on and Y2 will be the Y pos of the paddle (WILL NEED NORMAL VALUE)
		//(X1 * X2) + (Y1 * Y2)
		void Bounce(sf::Vector2f normalizedVec);

		virtual void move(sf::Vector2f& getVelocity);

		void setGameOver(bool state);
		bool getGameOver();
	};
}

#endif