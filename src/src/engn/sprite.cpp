#include "headers/engn/sprite.h"
#include "headers/engn/graphics.h"

Sprite::Sprite() {

}

Sprite::Sprite(Graphics &graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX,
               float posY) : m_x(posX), m_y(posY) {
    this->m_srcRect.x = sourceX;
    this->m_srcRect.y = sourceY;
    this->m_srcRect.w = width;
    this->m_srcRect.h = height;

    this->m_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

    if(this->m_spriteSheet == nullptr) {
        printf("\n[WARNING] Unable to load sprite.\n");
    }
}

Sprite::~Sprite() {

}

void Sprite::draw(Graphics &graphics, int x, int y, float scale, float angle) {
    SDL_Rect destRect = {x, y, (int) (this->m_srcRect.w * scale), (int) (this->m_srcRect.h * scale)};
    graphics.blitSurface(this->m_spriteSheet, &this->m_srcRect, &destRect, angle);
}

void Sprite::update() {

}

double Sprite::getWidth() {
    return m_srcRect.w;
}

double Sprite::getHeight(){
    return m_srcRect.h;
}
