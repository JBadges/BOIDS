//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_SPRITE_H
#define BOIDS_SPRITE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <string>

class Graphics;

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
           float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics& graphics, int x, int y, float scale);

private:
    SDL_Rect m_srcRect;
    SDL_Texture* m_spriteSheet;

    float m_x, m_y;
};

#endif //BOIDS_SPRITE_H
