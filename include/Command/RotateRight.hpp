/**
* @file RotateRight.hpp
 * @brief Defines the RotateRight class for 90-degree right rotation of images.
 */

#ifndef PROJECT_ROTATERIGHT_HPP
#define PROJECT_ROTATERIGHT_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class RotateRight
         * @brief Command to rotate an image 90 degrees to the right.
         */

        class RotateRight : public Command {
        public:
            RotateRight();

            ~RotateRight();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}



#endif //PROJECT_ROTATERIGHT_HPP
