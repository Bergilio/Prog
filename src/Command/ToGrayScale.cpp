#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>


namespace prog {

    namespace command {

        ToGrayScale::ToGrayScale() : Command("ToGrayScale") {}

        ToGrayScale::~ToGrayScale() {}

        /**
         * @brief Converts the image to grayscale using average method
         *
         * Transforms each pixel to grayscale by calculating the average of its RGB components
         * and setting all three channels to this average value.
         */
        Image *ToGrayScale::apply(Image *img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    int avg = (c.red() + c.green() + c.blue()) / 3;
                    c.red() = avg;
                    c.green() = avg;
                    c.blue() = avg;
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
