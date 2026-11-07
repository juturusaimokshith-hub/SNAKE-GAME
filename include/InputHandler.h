#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Snake.h"

class InputHandler {
public:
    char getInput() const;
    void processInput(char key, Snake& snake) const;
};

#endif
