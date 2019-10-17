//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_GRAPHICS_H
#define BOIDS_GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    SDL_Surface* loadImage(const std::string& filePath);

    /**
     * Draws a texture to a certain part of the scene
     * @param source
     * @param sourceRect
     * @param destRect
     */
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect);

    /**
     * Renders everything to the screen
     */
    void flip();

    /**
     * Clears the screen
     */
    void clear();

    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    std::map<std::string, SDL_Surface*> m_spriteSheets;
};

#endif //BOIDS_GRAPHICS_H
