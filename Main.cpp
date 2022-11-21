/* My Classes */
#include "Game.h"

/* Namespaces */
using namespace gm;
using namespace sf;

/* Functions */
// Main, our applicaiton entry function
int main()
{
    Game game;

    game.run();

    // The game has exited normally so send a normal exit status integer back
    return 0;
}