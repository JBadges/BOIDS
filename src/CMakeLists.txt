project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        headers/engn/graphics.h headers/engn/game.h headers/engn/input.h headers/engn/sprite.h headers/engn/globals.h headers/bird.h headers/math/point.h headers/math/util.h)
set(SOURCE_FILES
        src/engn/graphics.cpp src/engn/game.cpp src/engn/input.cpp src/engn/sprite.cpp src/bird.cpp src/math/point.cpp)

# The library contains header and source files.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )