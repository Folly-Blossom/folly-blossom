#ifndef FOLLY_BLOSSOM_LOADER_H
#define FOLLY_BLOSSOM_LOADER_H

#include "../data-api/Data.h"

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

#endif /*FOLLY_BLOSSOM_LOADER_H*/
