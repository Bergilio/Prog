#include "Command/ScaleUp.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        ScaleUp::ScaleUp(int x, int y) : Command("ScaleUP"), x(x), y(y) {}

        ScaleUp::~ScaleUp() {}

        Image *ScaleUp::apply(Image *img) {
            std::vector<std::vector<Color>> newColors(img->height() * y, std::vector<Color>(img->width() * x));

            for (int i = 0; i < img->height(); i++) {
                for (int j = 0; j < img->width(); j++) {
                    for (int dy = 0; dy < y; dy++) {
                        for (int dx = 0; dx < x; dx++) {
                            newColors[i * y + dy][j * x + dx] = img->at(j, i);
                        }
                    }
                }
            }

            img->width() = img->width() * x;
            img->height() = img->height() * y;
            img->getColors() = newColors;
            return img;
        }

        std::string ScaleUp::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
