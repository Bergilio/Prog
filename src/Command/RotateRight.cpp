#include "Command/RotateRight.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        RotateRight::RotateRight() : Command("RotateRight") {}

        RotateRight::~RotateRight() {}

        /**
        * @brief Rotates the image 90 degrees counter-clockwise
        *
        * Creates a new image where the original's columns become rows and rows become columns.
        * Then it assigns each (x, y) pixel to (nr of rows - y, x), performing the right rotation.
        */
        Image *RotateRight::apply(Image *img) {

            Image *newImg = new Image(img->height(), img->width());

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    newImg->at(img->height() - 1 - y, x) = img->at(x, y);
                }
            }

            delete img;
            return newImg;
        }

        std::string RotateRight::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
