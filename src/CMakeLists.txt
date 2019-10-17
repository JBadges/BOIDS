project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        headers/graphics.h headers/game.h headers/input.h headers/sprite.h headers/globals.h)
set(SOURCE_FILES
        src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp)

# The library contains header and source files.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )