#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

#include <headers/engn/graphics.h>
#include <headers/engn/globals.h>


/* Graphics class
 * Holds all information dealing with graphics for the game
 */

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(Globals::kScreenWidth, Globals::kScreenHeight, 0, &this->m_window, &this->m_renderer);
    SDL_SetWindowTitle(this->m_window, "BOIDS Simulator");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->m_window);
    SDL_DestroyRenderer(this->m_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if (this->m_spriteSheets.count(filePath) == 0) {
        this->m_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return m_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRect, SDL_Rect *destRect, float angle) {
    SDL_RenderCopyEx(this->m_renderer, texture, sourceRect, destRect, angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}

void Graphics::flip() {
    SDL_RenderPresent(this->m_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->m_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->m_renderer;
}