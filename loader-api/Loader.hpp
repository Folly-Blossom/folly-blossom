#ifndef FOLLY_BLOSSOM_LOADER_HPP
#define FOLLY_BLOSSOM_LOADER_HPP

#include "../data-api/Data.hpp"

namespace Folly {
    class LoaderAPI : public Data {
    public:
        LoaderAPI(File *load, FileData data) {
            file = load;

            fileData = data;
        }

    private:
        File *file;

        FileData fileData {};
    };
}

#endif /*FOLLY_BLOSSOM_LOADER_HPP*/