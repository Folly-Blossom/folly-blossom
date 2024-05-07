#ifndef FOLLY_BLOSSOM_FILEACTIONS_HPP
#define FOLLY_BLOSSOM_FILEACTIONS_HPP

#include "File.hpp"

namespace Folly {
    std::string static OpenFile(File *file) {
        typedef std::fstream FileStream;
        typedef std::string String;
        typedef std::ios_base BaseIOS;

        FileStream fileStream = FileStream(file -> fileName, BaseIOS::in | BaseIOS::trunc);

        String *contents {};

        fileStream.read(reinterpret_cast<char*>(contents), sizeof contents); // NOLINT(*-sizeof-expression)

        fileStream.close();

        return reinterpret_cast<char *>(contents);
    }

    bool static CloseFile(File *file) {
        typedef std::fstream FileStream;
        typedef std::string String;
        typedef std::ios_base BaseIOS;

        FileStream stream = FileStream(file -> fileName, BaseIOS::in | BaseIOS::trunc);

        if (!stream.is_open()) return false;

        stream.close();

        return true;
    }
}

#endif /*FOLLY_BLOSSOM_FILEACTIONS_HPP*/
