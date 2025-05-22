#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "ScrimParser.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

namespace prog {

    namespace command {

        Chain::Chain(std::vector<std::string> filepaths) : Command("Chain"), filepaths(filepaths) {}

        Chain::~Chain() {}

        /**
 		* @brief Helper function for executing a chain of Scrim script files with recursion tracking.
 		*
 		* This function processes a list of file paths associated with a Chain command.
		* It executes the commands within each script file in order, avoiding "open", "save" and "blank",
		* recursively executing nested chain commands while avoiding infinite recursion.
 		*
 		* To detect and avoid infinite recursion, a call stack (`visited`) is maintained, tracking
 		* the current chain of files being processed.
 		*/
        Image* Chain::helper(Image* img, std::vector<std::string>& visited) {
    		ScrimParser parser;

    		for (const std::string& path : filepaths) {

                // Checks if file has been visited inside the nested chain
        		if (std::find(visited.begin(), visited.end(), path) != visited.end()) {
            		continue;
        		}

        		visited.push_back(path); // if it hasn't been visited, add it to the visited stack

        		Scrim* scrim = parser.parseScrim(path); // Parse the scrims in the current file

                // Go over each command parsed in this file
        		for (Command* cmd : scrim->getCommands()) {
            		std::string cmdName = cmd->name();

                    // Do not apply the command if one of this commands are found (requirement for the chain functionality)
            		if (cmdName == "Open" || cmdName == "Save" || cmdName == "Blank") {
                		continue;
            		}
                    // If it is a nested chain command we want to pass the current visited stack, so we call the helper
                    // method directly instead of the apply method, as the second one would create a new visited stack
                    // We cast the command as Chain* because the compiler does not necessarily know wich command is going
                    // to call the helper method, but only the chain command has it, so it would cause a compiler error.
            		else if (cmdName == "Chain") {
                		Chain* chainCmd = dynamic_cast<Chain*>(cmd);
                		img = chainCmd->helper(img, visited);
            		}
            		else {
                		img = cmd->apply(img);
            		}
        		}

        		delete scrim;
        		visited.pop_back(); // After processing this file, we remove it from the visited stack.
									// This allows the same file to be used again in other parts of the chain,
									// as long as it's not part of the current nested call path.
    		}

            return img;
        }

        /**
 		* @brief Entry point for applying a Chain command to an image.
		* It creates the empty visited stack to track infinite recursion.
 		*/
        Image* Chain::apply(Image* img) {
            std::vector<std::string> visited;
            return helper(img, visited);
        }


        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
