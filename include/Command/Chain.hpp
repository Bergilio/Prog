/**
* @file Chain.hpp
 * @brief Defines the Chain class for applying multiple commands sequentially.
 */

#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include "Image.hpp"
#include <unordered_set>

namespace prog {

    namespace command {

        /**
        * @class Chain
        * @brief Command to apply multiple commands from files sequentially.
        */

        class Chain : public Command {
        public:
            Chain(std::vector<std::string> filepaths);

            ~Chain();

            Image *apply(Image *img) override;

            std::string toString() const override;

            Image *helper(Image *img, std::vector<std::string>& callStack);

        private:
            std::vector<std::string> filepaths;
        };
    }
}



#endif //PROJECT_CHAIN_HPP
