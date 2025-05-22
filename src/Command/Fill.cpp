#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        Fill::Fill(int x, int y, int w, int h, Color& fill) : Command("Fill"), x(x), y(y), w(w), h(h), fill(fill) {}

        Fill::~Fill() {}

        Image *Fill::apply(Image *img) {

            /**
           * @brief Assigns input color (fill) to all the pixels of the orginal image inside
           * the rectangle defined by the top-left corner (x,y), width w, and height h
           */
            for (int i = y; i < y + h && i < img->height(); i++) {
                for (int j = x; j < x + w && j < img->width(); j++) {
                    Color& c = img->at(j, i);
                    c = fill;
                }
            }
            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}