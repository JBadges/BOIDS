#include <headers/engn/globals.h>
#include "headers/engn/input.h"

void Input::beginNewFrame() {
    this->m_pressedKeys.clear();
    this->m_releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event &event) {
    this->m_pressedKeys[event.key.keysym.scancode] = true;
    this->m_heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event) {
    this->m_releasedKeys[event.key.keysym.scancode] = true;
    this->m_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->m_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->m_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return this->m_heldKeys[key];
}

void Input::onMousePress(SDL_MouseButtonEvent b, Graphics& graphics, bool shouldPlaceBird, std::vector<std::shared_ptr<Bird>>& birds, std::vector<std::shared_ptr<Obstacle>>& obstacles) {
    if(shouldPlaceBird) {
        birds.push_back(std::shared_ptr<Bird>(
                new Bird(graphics, {static_cast<float>(b.x), Globals::kScreenHeight - static_cast<float>(b.y)},
                         rand() % 360)));
    } else {
        obstacles.push_back(std::shared_ptr<Obstacle>(
                new Obstacle(graphics, {static_cast<float>(b.x), Globals::kScreenHeight - static_cast<float>(b.y)})));
    }
}
