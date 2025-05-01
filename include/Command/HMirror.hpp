//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_HMIRROR_HPP
#define PROJECT_HMIRROR_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class HMirror : public Command {
        public:
            HMirror();

            ~HMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //PROJECT_HMIRROR_HPP
