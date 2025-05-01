//
// Created by pedro on 29-04-2025.
//

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
