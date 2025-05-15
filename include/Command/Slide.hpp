//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_SLIDE_HPP
#define PROJECT_SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

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
