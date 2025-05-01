//
// Created by pedro on 29-04-2025.
//

#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Replace::Replace(Color& oldColor, Color& newColor) : Command("Replace"), oldColor(oldColor), newColor(newColor) {}

        Replace::~Replace() {}

        Image *Replace::apply(Image *img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    if (c.red() == oldColor.red() && c.green() == oldColor.green() && c.blue() == oldColor.blue()) {
                        c.red() = newColor.red();
                        c.green() = newColor.green();
                        c.blue() = newColor.blue();
                    }
                }
            }
            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " oldColor:" << oldColor << " newColor:" << newColor;
            return ss.str();
        }

    }
}

