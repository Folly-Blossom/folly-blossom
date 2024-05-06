#include "../file-api/File.h"

struct FileData {
    struct File *file;
    unsigned char size_in_bytes[];
};