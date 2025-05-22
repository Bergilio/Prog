/**
 * @file Invert.hpp
* @brief Defines the Invert class for inverting image colors.
*/

#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class Invert
         * @brief Command to invert the colors of an image.
         */

        class Invert : public Command {
        public:
            Invert();

            ~Invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}



#endif //PROJECT_INVERT_HPP
