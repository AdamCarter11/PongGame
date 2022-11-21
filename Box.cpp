#include "Box.h"

using namespace sf;
using namespace gm;

Box::Box(const Vector2f& position, const Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	speed.x = 0;
	speed.y = 0;
}

void Box::update(sf::RenderWindow& window) {
	body.setPosition(this->getPosition());
}

void Box::render(sf::RenderWindow& window) {
	window.draw(body);
}

void Box::move(sf::Vector2f& getVelocity) {
	
}

void Box::moveUp() {
	speed.y = .2f;
}
void Box::moveDown() {
	speed.y = -.2f;
}
void Box::setSpeed(float ySpeed) {
	speed.y = ySpeed;
}