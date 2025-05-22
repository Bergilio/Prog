/**
* @file Add.hpp
 * @brief Defines the Add class
 */

#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {
        /**
         * @class Add
         * @brief Command to copy all pixels from an image stored in PNG file filename, except pixels in that image with “neutral” color (r,g,b),
         * to the rectangle of the current image with top-left corner (x,y) of the current image
         */
        class Add : public Command {
        public:
            Add(std::string filename, Color &neutral, int x, int y);

            ~Add();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename;
            Color neutral;
            int x, y;
        };
    }
}

#endif  //PROJECT_ADD_HPP