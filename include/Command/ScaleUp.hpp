/**
* @file ScaleUp.hpp
 * @brief Defines the ScaleUp class for scaling up images.
 */

#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class ScaleUp
         * @brief Command to scale up an image by specified factors.
         */

        class ScaleUp : public Command {
        public:
            ScaleUp(int x, int y);

            ~ScaleUp();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x, y;
        };
    }
}



#endif //PROJECT_SCALEUP_HPP
