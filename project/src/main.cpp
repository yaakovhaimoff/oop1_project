#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include "Controller.hpp"

int main() 
{
	srand(17);
    auto run = Controller();
    run.runGame();

    return EXIT_SUCCESS;
}
