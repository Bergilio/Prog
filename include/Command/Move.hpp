#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

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
