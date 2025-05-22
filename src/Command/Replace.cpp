#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Replace::Replace(Color& oldColor, Color& newColor) : Command("Replace"), oldColor(oldColor), newColor(newColor) {}

        Replace::~Replace() {}

        /** @brief Checks if each pixel has the same color as the old color and replaces it with the new color
        */
        Image *Replace::apply(Image *img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    if (c == oldColor) {
                        c = newColor;
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

