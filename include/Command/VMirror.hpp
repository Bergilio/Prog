/**
* @file VMirror.hpp
 * @brief Defines the VMirror class for vertical mirroring of images.
 */

#ifndef PROJECT_VMIRROR_HPP
#define PROJECT_VMIRROR_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class VMirror
         * @brief Command to vertically mirror an image.
         */

        class VMirror : public Command {
        public:
            VMirror();

            ~VMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //PROJECT_VMIRROR_HPP
