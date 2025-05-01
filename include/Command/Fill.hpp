//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, Color& fill);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y, w, h;
            Color fill;
        };
    }
}



#endif //PROJECT_FILL_HPP
