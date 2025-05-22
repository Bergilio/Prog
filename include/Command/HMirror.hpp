/**
* @file HMirror.hpp
 * @brief Defines the HMirror class for horizontal mirroring of images.
 */

#ifndef PROJECT_HMIRROR_HPP
#define PROJECT_HMIRROR_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class HMirror
         * @brief Command to horizontally mirror an image.
         */

        class HMirror : public Command {
        public:
            HMirror();

            ~HMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //PROJECT_HMIRROR_HPP
