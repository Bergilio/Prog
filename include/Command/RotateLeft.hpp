#ifndef PROJECT_ROTATELEFT_HPP
#define PROJECT_ROTATELEFT_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

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
