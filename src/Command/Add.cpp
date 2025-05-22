#include "Command/Add.hpp"
#include "Command.hpp"
#include "Image.hpp"
#include "PNG.hpp"
#include <string>
#include <sstream>


namespace prog {

    namespace command {

        Add::Add(std::string filename, Color &neutral, int x, int y) : Command("Add"), filename(filename), neutral(neutral), x(x), y(y) {}

        Add::~Add() {};

        /**
         * @brief Loads image from input file and copys each pixel that is not equal to the neutral color, inside the rectangle
         * of the mage starting at (x, y)
         */
        Image *Add::apply(Image *img) {
            Image *filePNG = loadFromPNG(filename);

            for (int a = 0; a < filePNG->height(); a++) {
                if (y + a >= img->height()) continue;

                for (int b = 0; b < filePNG->width(); b++) {
                    if (x + b >= img->width()) continue;

                    const Color &pixel = filePNG->at(b, a);

                    if (!(pixel == neutral)) {
                        img->at(x+b, y+a) = pixel;
                    }
                }
            }
            delete filePNG;
            return img;
        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}