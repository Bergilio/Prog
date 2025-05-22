#include "Command/VMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        VMirror::VMirror() : Command("V_Mirror") {}

        VMirror::~VMirror() {}

        /**
        * @brief Vertically mirrors the image (flips top-to-bottom)
        *
        * Performs an in-place vertical flip of the image by swapping pixels between
        * the top and bottom halves. The operation works by exchanging rows symmetrically
        * about the horizontal center line of the image.
        *
        * 
        */
        Image* VMirror::apply(Image* img) {

            for (int i = 0; i < img->height() / 2; i++) {
                for (int j = 0; j < img->width(); j++) {
                    Color c1 = img->at(j, i);
                    Color c2 = img->at(j, img->height() - i - 1);
                    img->at(j, i) = c2;
                    img->at(j, img->height() - i - 1) = c1;
                }
            }
            return img;
        }

        std::string VMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}