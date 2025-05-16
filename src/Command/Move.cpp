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
            std::vector<std::vector<Color>> newColors(img->height(), std::vector<Color>(img->width(), img->fill()));

            for (int i = 0; i < img->height() - y; i++) {
                for (int j = 0; j < img->width() - x; j++) {
                    newColors[i+y][j+x] = img->at(j, i);
                }
            }

            img->getColors() = newColors;
            return img;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y;
            return ss.str();
        }
    }
}