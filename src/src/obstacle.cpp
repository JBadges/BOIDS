#include <headers/obstacle.h>

Obstacle::Obstacle() {

}

Obstacle::Obstacle(Graphics& graphics, Point pos) :
        Sprite(graphics, "../res/sprites/redCircle.png", 0,0,25,25, pos.getX(), pos.getY()),
        Point(pos){
}
