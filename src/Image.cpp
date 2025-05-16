#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) : w(w), h(h), fill_(fill) {
        colors = std::vector<std::vector<Color>>(h, std::vector<Color>(w, fill));
    }

    Image::~Image() {
    }

    int Image::width() const {
        return w;
    }

    int Image::height() const {
        return h;
    }

    int &Image::width() {
        return w;
    }


    int &Image::height() {
        return h;
    }


    Color &Image::at(int x, int y) {
		return colors[y][x];
    }

    const Color &Image::at(int x, int y) const {
        return colors[y][x];
    }

    const Color &Image::fill() const {
        return fill_;
    }

    std::vector<std::vector<Color>> &Image::getColors() {
        return colors;
    }
}
