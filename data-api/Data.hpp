#ifndef FOLLY_BLOSSOM_DATA_HPP
#define FOLLY_BLOSSOM_DATA_HPP

#include "../file-api/File.hpp"
#include "../data-api/FileData.hpp"

namespace Folly {
    class Data {
        /**
         * Creates newly allocated FileData that is then assigned to the given file.
         *
         * @param file The file to assign the FileData to
         *
         * @return
         */
        static FileData GetFileData(File *file, const std::string &filePath) {



            return *new FileData;
        }


    };
}

#endif /*FOLLY_BLOSSOM_DATA_HPP*/
