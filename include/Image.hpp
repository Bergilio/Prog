#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
    class Image {
    private:
		int w, h;
        Color fill_;
        std::vector<std::vector<Color>> colors;
    
	public:
        Image(int w, int h, const Color &fill = {255, 255, 255});

        ~Image();

        int width() const;

        int height() const;

        int &width();

        int &height();

        Color &at(int x, int y);

        const Color &at(int x, int y) const;

        const Color &fill() const;

        std::vector<std::vector<Color>> &getColors();
    };
}
#endif
