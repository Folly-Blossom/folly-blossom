#ifndef FOLLY_BLOSSOM_DATA_H
#define FOLLY_BLOSSOM_DATA_H

#include "../file-api/File.h"
#include "../data-api/FileData.h"

class Data {
    static FileData GetFileData() {
        return *new FileData;
    }


};

#endif /*FOLLY_BLOSSOM_DATA_H*/
