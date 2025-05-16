//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class ScaleUp : public Command {
        public:
            ScaleUp(int x, int y);

            ~ScaleUp();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x, y;
        };
    }
}



#endif //PROJECT_SCALEUP_HPP
