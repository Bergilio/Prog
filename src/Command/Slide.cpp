#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Slide::Slide(int x, int y) : Command("Slide"), x(x), y(y) {}

        Slide::~Slide() {}

        /**
        * @brief Slides (wraps) image content by specified (x,y) displacement
        *
        * Creates a new image where pixel content is shifted by (x,y) pixels with wrap-around
        * at image boundaries. This is performed with modular operations maintains the the coordinates
        * when they are inside the boundaries and "wraps around" when they are outside the bound.
        */
        Image *Slide::apply(Image *img) {

            Image *newImg = new Image(img->width(), img->height());

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    newImg->at((j+x) % img->width(), (i+y) % img->height()) = img->at(j, i);
                }
            }

            delete img;
            return newImg;
        }


        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y;
            return ss.str();
        }
    }
}