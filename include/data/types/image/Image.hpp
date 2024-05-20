#ifndef FOLLY_BLOSSOM_IMAGE_HPP
#define FOLLY_BLOSSOM_IMAGE_HPP

#include <utility>

#include "../../render/Pixel.hpp"
#include "../../../file/File.hpp"
#include <vector>

namespace Folly {
    enum ImageOptions {
        COMPRESSED,
        TRANSPARENT,
        SCALABLE
    };

    class Image {
    private:
        File *file;
        std::vector<ImageOptions> options;

    public:
        Image(File *file, std::vector<ImageOptions> options) {
            this -> file = file;
            this -> options = std::move(options);
        }

        std::vector<ImageOptions> GetImageOptions() {
            return this -> options;
        }

        virtual Image* Encrypt() = 0;

        virtual Image* Decrypt() = 0;

        virtual void Save() = 0;

        virtual void Load() = 0;
    };
}

#endif /*FOLLY_BLOSSOM_IMAGE_HPP*/
