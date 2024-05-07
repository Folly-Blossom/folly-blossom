#include "../file-api/File.hpp"

#ifndef FOLLY_BLOSSOM_FILEDATA_H
#define FOLLY_BLOSSOM_FILEDATA_H

namespace Folly {
    struct FileData {
        struct File *file;
        unsigned char size_in_bytes[];
    };
}

#endif /*FOLLY_BLOSSOM_FILEDATA_H*/