#include "../file/File.hpp"

#ifndef FOLLY_BLOSSOM_FILEDATA_H
#define FOLLY_BLOSSOM_FILEDATA_H

#include <vector>
#include <ctime>
#include <string>

namespace Folly {
    struct FileData {
        typedef std::time_t Time;
        typedef std::string String;

        std::vector<unsigned char*> bytes;
        String filePath;
        Time CREATION_DATE;
        Time accessDate;
    };
}

#endif /*FOLLY_BLOSSOM_FILEDATA_H*/