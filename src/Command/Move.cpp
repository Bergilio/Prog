#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Move::Move(int x, int y) : Command("Move"), x(x), y(y) {}

        Move::~Move() {}

        /** @brief Creates a new image of the same dimensions as the original, then copies pixels
        * from the source image starting at the specified offset. Areas that would be
        * outside the image bounds after the move are filled with the image's default color.
        */

        Image *Move::apply(Image *img) {

            Image *newImg = new Image(img->width(), img->height(), img->fill());

            for (int i = 0; i < img->height() - y; i++) {
                for (int j = 0; j < img->width() - x; j++) {
                    newImg->at(j+x, i+y) = img->at(j, i);
                }
            }

            delete img;
            return newImg;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y;
            return ss.str();
        }
    }
}