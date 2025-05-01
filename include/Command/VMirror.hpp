//
// Created by pedro on 29-04-2025.
//

#ifndef PROJECT_VMIRROR_HPP
#define PROJECT_VMIRROR_HPP


#include "Command.hpp"
#include "Image.hpp"

namespace prog {

    namespace command {

        class VMirror : public Command {
        public:
            VMirror();

            ~VMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //PROJECT_VMIRROR_HPP
