//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_INPUT_H
#define BOIDS_INPUT_H

#include <SDL2/SDL.h>
#include "map"

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> m_heldKeys;
    std::map<SDL_Scancode, bool> m_pressedKeys;
    std::map<SDL_Scancode, bool> m_releasedKeys;
};

#endif //BOIDS_INPUT_H
