#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Crop::Crop(int x, int y, int w, int h) : Command("Crop"), x(x), y(y), w(w), h(h) {}

        Crop::~Crop() {}

        Image *Crop::apply(Image *img) {
            std::vector<std::vector<Color>> newColors(h, std::vector<Color>(w));

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    newColors[i][j] = img->at(j+x, i+y);
                }
            }
            img->getColors() = newColors;
            img->width() = w;
            img->height() = h;
            return img;
        }

        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }
    }
}