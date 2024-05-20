#ifndef FOLLY_BLOSSOM_IMAGE_HPP
#define FOLLY_BLOSSOM_IMAGE_HPP

#include <string>
#include <utility>

#include "../../render/Pixel.hpp"
#include "../../../file/File.hpp"
#include "../../FileData.hpp"
#include "ImageOptions.hpp"
#include <vector>

namespace Folly {
    class Image {
    private:
        File *file;
        FileData fileData;
        std::vector<ImageOptions> options;

    public:
        Image(File *file, FileData fileData, std::vector<ImageOptions> options) {
            this -> file = file;
            this -> fileData = std::move(fileData);
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
