#include <SFML/Graphics.hpp>

#include <iostream>
#include "Controller.hpp"

int main() 
{
    auto run = Controller();
    run.runGame();

    return EXIT_SUCCESS;
}
