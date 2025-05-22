/**
* @file RotateLeft.hpp
 * @brief Defines the RotateLeft class for 90-degree left rotation of images.
 */

#ifndef PROJECT_ROTATELEFT_HPP
#define PROJECT_ROTATELEFT_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class RotateLeft
         * @brief Command to rotate an image 90 degrees to the left.
         */

        class RotateLeft : public Command {
        public:
            RotateLeft();

            ~RotateLeft();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}



#endif //PROJECT_ROTATELEFT_HPP
