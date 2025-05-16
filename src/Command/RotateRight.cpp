#include "Command/RotateRight.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        RotateRight::RotateRight() : Command("RotateRight") {}

        RotateRight::~RotateRight() {}

        Image *RotateRight::apply(Image *img) {
            int oldWidth = img->width();
            int oldHeight = img->height();

            std::vector<std::vector<Color>> newColors(oldWidth, std::vector<Color>(oldHeight));

            for (int y = 0; y < oldHeight; ++y) {
                for (int x = 0; x < oldWidth; ++x) {
                    newColors[x][oldHeight - 1 - y] = img->at(x, y);
                }
            }

            img->width() = oldHeight;
            img->height() = oldWidth;
            img->getColors() = newColors;

            return img;
        }

        std::string RotateRight::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
