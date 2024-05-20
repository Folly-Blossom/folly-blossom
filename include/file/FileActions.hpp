#ifndef FOLLY_BLOSSOM_FILEACTIONS_HPP
#define FOLLY_BLOSSOM_FILEACTIONS_HPP

#include "File.hpp"

namespace Folly {
    typedef std::fstream FileStream;
    typedef std::string String;
    typedef std::ios_base BaseIOS;

    FileStream static GetFileStreamByFileName(const String &fileName) {
        return FileStream(fileName, BaseIOS::in | BaseIOS::trunc);
    }

    std::string static OpenFile(File *file) {
        FileStream fileStream = GetFileStreamByFileName(file -> fileName);

        String *contents{};

        fileStream.read(reinterpret_cast<char*>(contents), sizeof contents); // NOLINT(*-sizeof-expression)

        fileStream.close();

        return reinterpret_cast<char *>(contents);
    }

    std::vector<char*> static ReadFileBuffer(String &fileName, const std::vector<char*>& content) {
        GetFileStreamByFileName(fileName);

        return content;
    }

    bool static CloseFile(File *file) {
        FileStream stream = GetFileStreamByFileName(file -> fileName);

        if (!stream.is_open()) return false;

        stream.close();

        return true;
    }
}

#endif /*FOLLY_BLOSSOM_FILEACTIONS_HPP*/
