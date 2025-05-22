/**
* @file Fill.hpp
 * @brief Defines the Fill class for filling rectangular areas with a color.
 */

#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class Fill
         * @brief Command to fill a rectangular area with a specified color.
         */

        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, Color& fill);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y, w, h;
            Color fill;
        };
    }
}



#endif //PROJECT_FILL_HPP
