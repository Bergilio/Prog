/**
* @file Crop.hpp
 * @brief Defines the Crop class for cropping images.
 */

#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class Crop
         * @brief Command to crop an image to specified dimensions.
         */

        class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);

            ~Crop();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y, w, h;
        };
    }
}



#endif //PROJECT_CROP_HPP
