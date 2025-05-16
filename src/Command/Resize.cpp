//
// Created by pedro on 29-04-2025.
//
#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x(x), y(y), w(w), h(h) {}

        Resize::~Resize() {}

        Image *Resize::apply(Image *img) {
            std::vector<std::vector<Color>> newColors(h, std::vector<Color>(w, img->fill()));

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (i+y < img->height() && j+x < img->width()) {
                        newColors[i][j] = img->at(j+x, i+y);
                    }
                }
            }

            img->width() = w;
            img->height() = h;
            img->getColors() = newColors;
            return img;
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
