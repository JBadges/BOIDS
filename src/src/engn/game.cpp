#include <headers/engn/input.h>
#include <headers/engn/globals.h>
#include <vector>
#include <iostream>
#include "SDL2/SDL.h"
#include "cmath"

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
    srand(time(0));
    Graphics graphics;
    Input input;
    SDL_Event event;

    int birdAmount = 100;
    for(int i = 0; i < birdAmount; i++) {
        this->m_birds.push_back(std::shared_ptr<Bird>(new Bird(graphics, {static_cast<float>(rand() % (Globals::kScreenWidth - 80)) + 40, static_cast<float>(rand() % (Globals::kScreenHeight - 89)) + 40}, rand() % 360)));
    }


    int amount = 40;
    for(int i = 0; i < amount; i++) {
        this->m_obsticals.push_back(std::shared_ptr<Obstacle>(new Obstacle(graphics, {static_cast<float>(Globals::kScreenWidth / amount * i), 10})));
        this->m_obsticals.push_back(std::shared_ptr<Obstacle>(new Obstacle(graphics, {static_cast<float>(Globals::kScreenWidth / amount * i), Globals::kScreenHeight - 10})));
    }

//    for(int i = 0; i < amount; i++) {
//        this->m_obsticals.push_back(std::shared_ptr<Obstacle>(new Obstacle(graphics, { 10, static_cast<float>(Globals::kScreenHeight / amount * i)})));
//        this->m_obsticals.push_back(std::shared_ptr<Obstacle>(new Obstacle(graphics, {Globals::kScreenWidth - 10, static_cast<float>(Globals::kScreenHeight / amount * i)})));
//    }


    int LAST_UPDATE_TIME = SDL_GetTicks();
    while(true) {
        input.beginNewFrame();

        if(SDL_PollEvent(&event)) {
            switch (event.type){
                case SDL_KEYDOWN:
                    if(event.key.repeat == 0) {
                        input.keyDownEvent(event);
                    }
                    break;
                case SDL_KEYUP:
                    input.keyUpEvent(event);
                    break;
                case SDL_QUIT:
                    return;
                case SDL_MOUSEBUTTONDOWN:
                    input.onMousePress(event.button, graphics, this->shouldPlaceBird, this->m_birds, this->m_obsticals);
                    break;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }
        if(input.wasKeyPressed(SDL_SCANCODE_Q)) {
            std::cout << "Pressed Q" << std::endl;
            this->shouldPlaceBird = !this->shouldPlaceBird;
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
        const double scale = Globals::kSpriteScale;
        const double angle = 90 - bird->getHeading();
        bird->draw(graphics, bird->getX() - bird->getWidth()/2 * scale * std::cos((90 - bird->getHeading()) * M_PI/180.0), Globals::kScreenHeight - bird->getY() - bird->getWidth()/2 * scale * std::sin((90 - bird->getHeading()) * M_PI/180.0),
                          Globals::kSpriteScale, angle);
    }
    for(std::shared_ptr<Obstacle>& obstical : this->m_obsticals) {
        const double scale = 0.5;
        obstical->draw(graphics, obstical->getX() - obstical->getWidth()/2 * scale,Globals::kScreenHeight - obstical->getY() - obstical->getHeight()/2 * scale,
                       scale, 0);
    }
    graphics.flip();
}

void Game::update(float elapsedTime) {
    for(std::shared_ptr<Bird>& bird : this->m_birds) {
        bird->update(elapsedTime, this->m_birds, this->m_obsticals);
    }
}
