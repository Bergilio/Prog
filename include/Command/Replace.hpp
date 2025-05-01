//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class Replace : public Command {
        public:
            Replace(Color& oldColor, Color& newColor);

            ~Replace();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            Color oldColor;
            Color newColor;
        };
    }
}


#endif //PROJECT_REPLACE_HPP
