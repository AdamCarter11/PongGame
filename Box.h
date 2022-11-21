#ifndef BOX_H
#define BOX_H

#include "GameObject.h"

namespace gm {
	class Box : public GameObject
	{
	public:	//THIS SHOULD BE PRIVATE AND A GETTER
		sf::RectangleShape body;
		sf::Vector2f speed;
	public:
		Box(const sf::Vector2f& position, const sf::Vector2f& size);

		void update(sf::RenderWindow& window);

		void render(sf::RenderWindow& window);

		virtual void move(sf::Vector2f& getVelocity);
		void moveUp();
		void moveDown();
		void setSpeed(float ySpeed);
	};
}

#endif