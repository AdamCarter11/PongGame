#include "SoundManager.h"
using namespace sf;
using namespace std;
#include <iostream>

SoundManager::SoundManager() {

    //loading paddle hit buffer
    if (!ballPaddleHitBuffer.loadFromFile("Assets/Audio/PaddleHit.wav")) {
        cout << "Error loading paddle hit sfx!" << endl;
    }

    ballPaddleHitSfx.setBuffer(ballPaddleHitBuffer);

    //loading ball bounce sfx
    if (!ballBounceBuffer.loadFromFile("Assets/Audio/Bounce.wav")) {
        cout << "Error loading bounce sfx!" << endl;
    }

    ballBounceSfx.setBuffer(ballBounceBuffer);

    //loading ball score sfx
    if (!ballScoreBuffer.loadFromFile("Assets/Audio/Score.wav")) {
        cout << "Error loading ball score sfx!" << endl;
    }

    ballScoreSfx.setBuffer(ballScoreBuffer);

    //loading win sfx
    if (!winBuffer.loadFromFile("Assets/Audio/Win.wav")) {
        cout << "Error loading win sfx!" << endl;
    }

    winSfx.setBuffer(winBuffer);
}

void SoundManager::playSfx(int whichSound) {
    if (whichSound == 1) {
        ballPaddleHitSfx.play();
    }
    if (whichSound == 2) {
        ballBounceSfx.play();
    }
    if (whichSound == 3) {
        ballScoreSfx.play();
    }
    if (whichSound == 4) {
        winSfx.play();
    }
}