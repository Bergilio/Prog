#ifndef PROJECT_TOGRAYSCALE_HPP
#define PROJECT_TOGRAYSCALE_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale();

            ~ToGrayScale();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //PROJECT_TOGRAYSCALE_HPP
