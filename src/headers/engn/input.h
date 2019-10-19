//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_INPUT_H
#define BOIDS_INPUT_H

#include <SDL2/SDL.h>
#include <headers/bird.h>
#include "map"

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

    void onMousePress(SDL_MouseButtonEvent b, Graphics& graphics, bool shouldPlaceBird, std::vector<std::shared_ptr<Bird>>& birds, std::vector<std::shared_ptr<Obstacle>>& obstacles);
private:
    std::map<SDL_Scancode, bool> m_heldKeys;
    std::map<SDL_Scancode, bool> m_pressedKeys;
    std::map<SDL_Scancode, bool> m_releasedKeys;
};

#endif //BOIDS_INPUT_H
