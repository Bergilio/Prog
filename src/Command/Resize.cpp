#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x(x), y(y), w(w), h(h) {}

        Resize::~Resize() {}

        /**
        * @brief Resizes the image to specified dimensions
        *
        * Creates a new image of given size, copying pixels from the source starting
        * at (x,y) position. Areas outside source bounds are filled with default color.
        */
        Image *Resize::apply(Image *img) {

            Image *newImg = new Image(w, h, img->fill());

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (i+y < img->height() && j+x < img->width()) {
                        newImg->at(j, i) = img->at(j+x, i+y);
                    }
                }
            }

            delete img;
            return newImg;
        }

        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }
    }
}//
// Created by pedro on 15-05-2025.
//
