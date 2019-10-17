#include <headers/input.h>
#include <headers/globals.h>
#include "SDL2/SDL.h"

#include "headers/game.h"
#include "headers/graphics.h"

namespace {
    const int FPS = 60;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    this->m_bird = Sprite(graphics, "../res/sprites/roundedArrow.png", 0,0,100,100,25,25);

    int LAST_UPDATE_TIME = SDL_GetTicks();
    while(true) {
        input.beginNewFrame();

        if(SDL_PollEvent(&event)) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            } else if(event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            } else if(event.type == SDL_QUIT) {
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELPASED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELPASED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    this->m_bird.draw(graphics, 25, 25, Globals::kSpriteScale);

    graphics.flip();
}

void Game::update(float elapsedTime) {

}
