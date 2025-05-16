#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);

            ~Resize();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y, w, h;
        };
    }
}



#endif //PROJECT_RESIZE_HPP
