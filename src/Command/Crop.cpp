#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Crop::Crop(int x, int y, int w, int h) : Command("Crop"), x(x), y(y), w(w), h(h) {}

        Crop::~Crop() {}

        /**
         * @brief Creates new image with desired dimension and copys all the pixels inside the rectangle
         * of the original image with top-left corner (x, y)
         */
        Image *Crop::apply(Image *img) {
            Image *newImg = new Image(w, h);

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    newImg->at(j, i) = img->at(j+x, i+y);
                }
            }

            delete img;
            return newImg;
        }

        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() <<" x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }
    }
}