#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Slide::Slide(int x, int y) : Command("Slide"), x(x), y(y) {}

        Slide::~Slide() {}

        Image *Slide::apply(Image *img) {
            std::vector<std::vector<Color>> newColors(img->height(), std::vector<Color>(img->width(), img->fill()));

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    newColors[(i+y) % img->height()][(j+x) % img->width()] = img->at(j, i);
                }
            }

            img->getColors() = newColors;
            return img;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y;
            return ss.str();
        }
    }
}