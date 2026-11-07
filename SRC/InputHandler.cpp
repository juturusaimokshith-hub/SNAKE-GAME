#include "../include/InputHandler.h"

#include <conio.h>
#include <cctype>

char InputHandler::getInput() const {
    if (!_kbhit()) {
        return '\0';
    }

    int key = _getch();

    // Windows arrow keys arrive as a two-part key code.
    if (key == 0 || key == 224) {
        key = _getch();

        if (key == 72) return 'w'; // Up
        if (key == 80) return 's'; // Down
        if (key == 75) return 'a'; // Left
        if (key == 77) return 'd'; // Right

        return '\0';
    }

    return static_cast<char>(std::tolower(static_cast<unsigned char>(key)));
}

void InputHandler::processInput(char key, Snake& snake) const {
    switch (key) {
        case 'w': snake.changeDirection(Direction::UP); break;
        case 's': snake.changeDirection(Direction::DOWN); break;
        case 'a': snake.changeDirection(Direction::LEFT); break;
        case 'd': snake.changeDirection(Direction::RIGHT); break;
        default: break;
    }
}
