/**
* @file Color.hpp
 * @brief Defines the Color class for representing RGB colors.
 */

#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {
    typedef unsigned char rgb_value;

    /**
     * @class Color
     * @brief Represents a color in RGB format.
     */

    class Color {
    private:
        rgb_value r, g, b;

    public:

        /**
         * @brief Default constructor (initializes to black).
         */
        Color();

        /**
         * @brief Copy constructor.
         * @param c Color to copy.
         */
        Color(const Color &c);

        /**
         * @brief Constructs a new Color with specified RGB values.
         * @param r Red component.
         * @param g Green component.
         * @param b Blue component.
         */
        Color(rgb_value r, rgb_value g, rgb_value b);

        // RGB read-only components accessor
        rgb_value red() const;
        rgb_value green() const;
        rgb_value blue() const;

        // RGB mutable components accessor
        rgb_value &red();
        rgb_value &green();
        rgb_value &blue();

        /**
         * @brief Equality comparison operator.
         * @param c Color to compare with.
         * @return true If colors are equal.
         * @return false If colors are different.
         */
        bool operator==(const Color &c) const;
    };
}

std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
