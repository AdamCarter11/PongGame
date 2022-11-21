// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;
#include <iostream>

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), box1(Vector2f(GameWidth - 50,GameHeight/2), Vector2f(25, 100)), box2(Vector2f(50,GameHeight / 2), Vector2f(25, 100)), ball(Vector2f(100, GameHeight / 2), Vector2f(50, 50)), floor(Vector2f(0, GameHeight), Vector2f(GameWidth, 15)), top(Vector2f(0, 0), Vector2f(GameWidth, 15)) {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		/*
		if (box1.collide(Vector2f(Mouse::getPosition(window)))) {
			box1.body.setFillColor(Color::Red);
		}
		else {
			box1.body.setFillColor(Color::White);
		}
		*/

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			box2.setPosition(Vector2f(box2.getPosition().x, box2.getPosition().y - 10));
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			box2.setPosition(Vector2f(box2.getPosition().x, box2.getPosition().y + 10));
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && ball.getGameOver()) {
			ball.setGameOver(false);
			box1.setPosition(Vector2f(GameWidth - 50, GameHeight / 2));
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	/*
	if (box1.collide(box2.getCollider())) {
		box1.body.setFillColor(Color::Green);
	}
	*/
	ball.update(window);
	float dir;
	if (box1.getPosition().y < ball.getPosition().y) {
		dir = .5f;
	}
	if (box1.getPosition().y > ball.getPosition().y) {
		dir = -.5f;
	}
	if (box1.getPosition().y == ball.getPosition().y) {
		dir = .0f;
	}
	box1.setPosition(Vector2f(box1.getPosition().x, box1.getPosition().y + dir * 5));
	box1.update(window);
	box2.update(window);

	if(ball.collide(box1.getCollider())){
		ball.setVelocity(Vector2f(ball.getVelocity().x * 1.1, ball.getVelocity().y * 1.1));
		ball.Bounce(Vector2f(-1,0));
		cout << "bounce" << endl;
	}
	if(ball.collide(box2.getCollider())){ 
		ball.setVelocity(Vector2f(ball.getVelocity().x * 1.1, ball.getVelocity().y * 1.1));
		ball.Bounce(Vector2f(1,0));
	}
	if(ball.collide(top.getCollider())){
		ball.Bounce(Vector2f(0,1));
	}
	if(ball.collide(floor.getCollider())){
		ball.Bounce(Vector2f(0,-1));
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	box1.render(window);
	box2.render(window);
	floor.render(window);
	top.render(window);

	ball.render(window);
	//if ball collides with box1 then call bounce

	/*
	Text aiText;
	Font textFont;
	if (!textFont.loadFromFile("Assets\\sonoVar.ttf")) {
		//error
		//cout << "error" << endl;
	}
	aiText.setFont(textFont);
	aiText.setPosition(500, 20);
	aiText.setString("Ai score: ");
	aiText.setCharacterSize(24);
	aiText.setFillColor(sf::Color::Red);
	window.draw(aiText);
	*/

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}