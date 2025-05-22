/**
* @file Move.hpp
 * @brief Defines the Move class for moving image content.
 */

#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        /**
         * @class Move
         * @brief Command to move image content by specified offsets.
         */

        class Move : public Command {
        public:
            Move(int x, int y);

            ~Move();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y;
        };
    }
}



#endif //PROJECT_MOVE_HPP
