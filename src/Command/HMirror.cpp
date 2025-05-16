#include "Command/HMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        HMirror::HMirror() : Command("H_Mirror") {}

        HMirror::~HMirror() {}

        Image* HMirror::apply(Image* img) {

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width() / 2; j++) {
                    Color c1 = img->at(j, i);
                    Color c2 = img->at(img->width() - 1 - j, i);
                    img->at(j, i) = c2;
                    img->at(img->width() - 1 - j, i) = c1;
                }
            }
            return img;
        }

        std::string HMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}