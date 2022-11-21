#include "SquareBall.h"

using namespace sf;
using namespace gm;
using namespace std;
#include <iostream>

#include <string>

#include "Random.h"


#define LO -1.f
#define HI  1.f

int ballSpeed = 5;

SquareBall::SquareBall(const Vector2f& position, const Vector2f& size) : GameObject(position, size) {
	//body.setPosition(Vector2f(80,100));
	
	//body.setSize(Vector2f(50,50));
	gameOver = false;
	body.setPosition(position);
	body.setSize(size);
	this->setPosition(position);
	
	//want to randomize
	velocity = Vector2f(.52f, .21f);
	playerScore = 0;
	aiScore = 0;

	/*
	if (!textFont.loadFromFile("Assets\\sonoVar.ttf")) {
		//error
		cout << "error" << endl;
	}

	scoreText.setFont(textFont);
	
	scoreText.setPosition(25, 20);
	scoreText.setString("Player score: " + std::to_string(playerScore) );
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::Green);

	aiText.setFont(textFont);
	aiText.setPosition(450, 20);
	aiText.setString("Ai score: " + std::to_string(aiScore));
	aiText.setCharacterSize(24);
	aiText.setFillColor(sf::Color::Red);
	*/
}

Vector2f projValHelper(Vector2f& initialVec, Vector2f normalizedVec) {
	Vector2f ans;

	float dotProd = (initialVec.x * normalizedVec.x) + (initialVec.y * normalizedVec.y);
	ans.x = normalizedVec.x * dotProd;
	ans.y = normalizedVec.y * dotProd;

	return ans;
}

void SquareBall::Bounce(Vector2f normalizedVec) {
	// Dot product is just a scaler
	// refer to picture for rest of math
	// (X1 - X2) / abs(X1-X2) to get horizontal normal value
	//	Will need access to the normal of the object hit, X2 (X pos doesn't change unless on different sides, a constant?) and initial velocity
	//if (this->collide()) {

	//}
	if (normalizedVec.x != 0) {
		sfxManager.playSfx(1);
	}
	else {
		sfxManager.playSfx(2);
	}
	Vector2f newBounce, proj;
	proj = projValHelper(velocity, normalizedVec);
	cout << proj.x << endl;
	proj.x *= 2;
	proj.y *= 2;
	newBounce = velocity - proj;
	//newBounce.x *= 1.1;
	//newBounce.y *= 1.1;
	this->setVelocity(newBounce);

}

void SquareBall::update(RenderWindow& window) {
	if (!gameOver)
	{
		this->setPosition(this->getPosition() + (Vector2f(velocity.x * ballSpeed, velocity.y * ballSpeed)));
		body.setPosition(this->getPosition());
		body.setFillColor(Color::Green);
	}
	else {
		this->setPosition(Vector2f(300, 300));
		body.setPosition(this->getPosition());
		body.setFillColor(Color::Red);
	}

	if (this->getPosition().x <= 20) {
		//gameover for player
		this->setPosition(Vector2f(300, 300));
		this->setVelocity(Vector2f(Random::Range(HI, LO, RAND_MAX), Random::Range(HI, LO, RAND_MAX)));
		aiScore++;
		//aiText.setString("Ai score: " + std::to_string(aiScore));
		uiDisplay.setAiText(aiScore);
		sfxManager.playSfx(3);
	}
	if (this->getPosition().x >= 570) {
		//gameover for player
		this->setPosition(Vector2f(300, 300));
		this->setVelocity(Vector2f(Random::Range(HI, LO, RAND_MAX), Random::Range(HI, LO, RAND_MAX)));
		playerScore++;
		//scoreText.setString("Player score: " + std::to_string(playerScore));
		uiDisplay.setPlayerText(playerScore);
		sfxManager.playSfx(3);
	}
	if (playerScore >= 3 || aiScore >= 3) {
		//gameover
		sfxManager.playSfx(4);
		gameOver = true;
		playerScore = 0;
		//scoreText.setString("Player score: " + std::to_string(playerScore));
		uiDisplay.setAiText(0);
		aiScore = 0;
		//aiText.setString("Ai score: " + std::to_string(aiScore));
		uiDisplay.setPlayerText(0);
	}
}

void SquareBall::setVelocity(Vector2f newVel) {
	velocity = newVel;
}
Vector2f const SquareBall::getVelocity() const {
	return velocity;
}

void SquareBall::render(sf::RenderWindow& window) {
	window.draw(body);
	//window.draw(scoreText);
	//window.draw(aiText);
	uiDisplay.render(window);
}

void SquareBall::move(sf::Vector2f& getVelocity) {

}

void SquareBall::setGameOver(bool state) {
	gameOver = state;
}

bool SquareBall::getGameOver() {
	return gameOver;
}