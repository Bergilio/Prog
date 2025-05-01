//
// Created by pedro on 29-04-2025.
//

// TO DO

#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Move::Move(int x, int y) : Command("Move"), x(x), y(y) {}

        Move::~Move() {}

        Image *Move::apply(Image *img) {

        }
    }
}