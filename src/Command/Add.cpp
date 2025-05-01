//
// Created by pedro on 29-04-2025.
//

// TO DO

#include "Command/Add.hpp"
#include "Command.hpp"
#include "Image.hpp"
#include <string>
#include <sstream>


namespace prog {

    namespace command {

        Add::Add(std::string filename, Color &neutral, int x, int y) : Command("Add"), filename(filename), neutral(neutral), x(x), y(y) {}

        Add::~Add() {};

        Image *Add::apply(Image *img) {



            return img;
        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}