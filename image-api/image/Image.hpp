#ifndef FOLLY_BLOSSOM_IMAGE_HPP
#define FOLLY_BLOSSOM_IMAGE_H

#include <string>

#include "../../file-api/File.hpp"

namespace Folly {
    struct BaseImage {
        static File *file;
    };

    class Image {
    public:
        virtual Image* Encrypt() = 0;

        virtual Image* Decrypt() = 0;

        virtual void Save() = 0;

        virtual void Load() = 0;

        BaseImage image;
    };
}

#endif /*FOLLY_BLOSSOM_IMAGE_HPP*/
