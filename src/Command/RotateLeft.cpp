#include "Command/RotateLeft.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        RotateLeft::RotateLeft() : Command("RotateLeft") {}

        RotateLeft::~RotateLeft() {}

        /**
        * @brief Rotates the image 90 degrees counter-clockwise
        *
        * Creates a new image where the original's columns become rows and rows become columns.
        * Then it assigns each (x, y) pixel to (y, nr. of columns - x), performing the left rotation.
        */
        Image *RotateLeft::apply(Image *img) {

            Image *newImg = new Image(img->height(), img->width());

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    newImg->at(y, img->width() - 1 - x) = img->at(x, y);
                }
            }

            delete img;
            return newImg;
        }

        std::string RotateLeft::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
