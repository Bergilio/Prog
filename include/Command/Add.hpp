//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class Add : public Command {
        public:
            Add(std::string filename, Color &neutral, int x, int y);

            ~Add();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename;
            Color neutral;
            int x, y;
        };
    }
}

#endif  //PROJECT_ADD_HPP