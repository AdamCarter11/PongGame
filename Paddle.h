#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

namespace gm {
    class Paddle : public GameObject
    {

    public:
        Paddle();

        void update(sf::RenderWindow& window);

        void render(sf::RenderWindow& window);

        sf::Vector2f& const getPosition() const;
        void setPosition(const sf::Vector2f& position);

        ~Paddle();
    };
}

#endif