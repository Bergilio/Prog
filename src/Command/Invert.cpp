#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>


namespace prog {

    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    c.red() = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue() = 255 - c.blue();
                }
            }
            return img;
        }

        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
