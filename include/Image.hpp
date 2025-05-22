/**
* @file Image.hpp
 * @brief Defines the Image class for representing a 2D image with color pixels.
 */

#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
    /**
  * @class Image
  * @brief Represents a 2D image composed of colored pixels.
  *
  * The Image class provides functionality to create and manipulate images
  * with specified width and height, filled with a default or specified color.
  */

    class Image {
    private:
		int w, h;
        Color fill_;
        std::vector<std::vector<Color>> colors;
    
	public:

        /**
         * @brief Constructs a new Image object with specified dimensions and fill color.
         * @param w Width of the image.
         * @param h Height of the image.
         * @param fill Fill color (default is white).
         */
        Image(int w, int h, const Color &fill = {255, 255, 255});

        ~Image();

        /**
         * @brief Gets the width of the image.
         * @return int The width of the image.
         */
        int width() const;

        /**
         * @brief Gets the height of the image.
         * @return int The height of the image.
         */
        int height() const;

        /**
         * @brief Accesses the color at specified coordinates (non-const version).
         * @param x X-coordinate (column).
         * @param y Y-coordinate (row).
         * @return Color& Reference to the color at (x,y).
         */
        Color &at(int x, int y);

        /**
         * @brief Accesses the color at specified coordinates (const version).
         * @param x X-coordinate (column).
         * @param y Y-coordinate (row).
         * @return const Color& Const reference to the color at (x,y).
         */
        const Color &at(int x, int y) const;

        /**
         * @brief Gets the fill color of the image.
         * @return const Color& The fill color.
         */
        const Color &fill() const;

    };
}
#endif
