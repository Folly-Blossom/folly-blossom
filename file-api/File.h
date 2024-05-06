#ifndef FOLLY_BLOSSOM_FILE_H
#define FOLLY_BLOSSOM_FILE_H

#include <string>

struct File {
    std::string fileName;
    const std::string FILE_PATH;
    const std::string ABSOLUTE_FILE_PATH;
};

File* GetFileByPath(const std::string &filePath) {
    return nullptr;
}

#endif /*FOLLY_BLOSSOM_FILE_H*/
