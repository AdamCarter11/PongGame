#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Paddle.h"

namespace gm {
	class PlayerController : public Paddle
	{

	public:
		PlayerController();

		void HandleInput();

		void update(sf::RenderWindow& window);

		~PlayerController();
	};
}



#endif