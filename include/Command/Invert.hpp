//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class Invert : public Command {
        public:
            Invert();

            ~Invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}



#endif //PROJECT_INVERT_HPP
