#include "GameObject.h"

using namespace sf;
using namespace gm;

// Default constructor
GameObject::GameObject() {}

// Overloaded constructor that takes a position
// NOTE that we set the position using the initialization list
GameObject::GameObject(const Vector2f& position, const Vector2f& size) : position(position), collider(position, size) {}


// Our position getter, NOTE the const reference return and marking the method itself const
const Vector2f& GameObject::getPosition() const {
	return position;
}

// Our position setter, takes a Vector2f by const reference
void GameObject::setPosition(const Vector2f& position) {
	this->position = position;
	collider.left = position.x;
	collider.top = position.y;
}

const FloatRect& GameObject::getCollider() const {
	return collider;
}

bool GameObject::collide(const sf::Vector2f& point) const {
	return collider.contains(point);
}

bool GameObject::collide(const sf::FloatRect& rect) const {
	// Dot product is just a scaler
	// refer to picture for rest of math
	// (X1 - X2) / abs(X1-X2) to get horizontal normal value
	return collider.intersects(rect);

	//the normalized vector it returns should be (-1, 0) if the ball hits the right paddle, and (0,1) if it hits the roof 
}