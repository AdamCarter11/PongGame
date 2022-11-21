#include "UiManager.h"

using namespace std;
using namespace sf;
#include <iostream>

#include <string>

UiManager::UiManager() {
	if (!textFont.loadFromFile("Assets\\sonoVar.ttf")) {
		//error
		cout << "error" << endl;
	}

	scoreText.setFont(textFont);

	scoreText.setPosition(25, 20);
	scoreText.setString("Player score: 0");
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::Green);

	aiText.setFont(textFont);
	aiText.setPosition(450, 20);
	aiText.setString("Ai score: 0");
	aiText.setCharacterSize(24);
	aiText.setFillColor(sf::Color::Red);
}

void UiManager::setPlayerText(int newScore) {
	scoreText.setString("Player score: " + std::to_string(newScore));
}

void UiManager::setAiText(int newScore) {
	aiText.setString("Ai score: " + std::to_string(newScore));
}

void UiManager::render(RenderWindow& window) {
	window.draw(aiText);
	window.draw(scoreText);
}