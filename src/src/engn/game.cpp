#include <headers/engn/input.h>
#include <headers/engn/globals.h>
#include <vector>
#include <iostream>
#include "SDL2/SDL.h"

#include "headers/engn/game.h"
#include "headers/engn/graphics.h"

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

    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {500, 400}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {450, 410}, 90)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {525, 350}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {510, 370}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {0, 400}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {45, 32}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {17, 443}, 125)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {74, 12}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {30, 400}, 232)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {43, 32}, 274)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {5543, 443}, 270)));
    this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {323, 12}, 270)));

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

        this->update(ELPASED_TIME_MS);

        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    for(std::shared_ptr<Bird>& bird : this->m_birds) {
        bird->draw(graphics, bird->getX(), Globals::kScreenHeight - bird->getY(),
                          Globals::kSpriteScale, 90 - bird->getHeading());
    }

    graphics.flip();
}

void Game::update(float elapsedTime) {
    for(std::shared_ptr<Bird>& bird : this->m_birds) {
        bird->update(elapsedTime, this->m_birds);
    }
}
