#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>


namespace prog {

    namespace command {

        ToGrayScale::ToGrayScale() : Command("ToGrayScale") {}

        ToGrayScale::~ToGrayScale() {}

        Image *ToGrayScale::apply(Image *img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    int v = (c.red() + c.green() + c.blue()) / 3;
                    c.red() = v;
                    c.green() = v;
                    c.blue() = v;
                }
            }
            return img;
        }

        std::string ToGrayScale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
