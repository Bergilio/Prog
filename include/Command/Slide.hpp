/**
* @file Slide.hpp
 * @brief Defines the Slide class for sliding image content.
 */

#ifndef PROJECT_SLIDE_HPP
#define PROJECT_SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class Slide
         * @brief Command to slide image content by specified offsets.
         */

        class Slide : public Command {
        public:
            Slide(int x, int y);

            ~Slide();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y;
        };
    }
}



#endif //PROJECT_SLIDE_HPP
