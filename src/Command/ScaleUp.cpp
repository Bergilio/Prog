#include "Command/ScaleUp.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>
#include <sstream>

namespace prog {

    namespace command {

        ScaleUp::ScaleUp(int x, int y) : Command("ScaleUP"), x(x), y(y) {}

        ScaleUp::~ScaleUp() {}

            /**
            * @brief Scales up the image by specified horizontal and vertical factors
            *
            * Creates a new image with dimensions (width*x, height*y) where each original pixel
            * is replicated into a x*y block in the output image. The scaling is performed using
            * two nested loops that will fill each block with the same pixel (j, i)
            */
            Image *ScaleUp::apply(Image *img) {

                Image *newImg = new Image(img->width() * x, img->height() * y);

                for (int i = 0; i < img->height(); i++) {
                    for (int j = 0; j < img->width(); j++) {
                        for (int dy = 0; dy < y; dy++) {
                            for (int dx = 0; dx < x; dx++) {
                                newImg->at(j * x + dx, i * y + dy) = img->at(j, i);
                            }
                        }
                    }
                }

                delete img;
                return newImg;
            }

        std::string ScaleUp::toString() const {
            std::ostringstream ss;
            ss << name() << "x: " << x << " y: " << y;
            return ss.str();
        }
    }
}
