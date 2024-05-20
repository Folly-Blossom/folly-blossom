#ifndef FOLLY_BLOSSOM_FILE_HPP
#define FOLLY_BLOSSOM_FILE_HPP

#include <string>
#include <fstream>
#include "../data/FileData.hpp"
#include <vector>

namespace Folly {
    struct File {
        typedef std::string String;

        String fileName;
        String filePath;
        String absoluteFilePath;
        struct FileData fileData;
    };

    enum State {
        ENCRYPTED,
        DECRYPTED,
        UNPROTECTED,
        EMPTY,
        NON_EXISTENT,
        FULL
    };

    namespace {
        #include <vector>

        State IsFileBlankBasedOnBuffer(File *file) {
            typedef std::fstream FileStream;
            typedef std::ios_base BaseIOS;
            typedef std::vector<char> Vector;

            char *contents {};

            Vector returnable;

            FileStream fileStream = FileStream(file -> fileName, BaseIOS::in | BaseIOS::trunc);

            for (int i = 0; i < sizeof contents; i++) {
                #pragma clang diagnostic push

                #pragma ide diagnostic ignored "NullDereference"
                #pragma ide diagnostic ignored "Simplify"

                if (!(isblank(contents[i]) == 0)) {
                    returnable.assign(contents[i], returnable.at(i));
                }

                #pragma clang diagnostic pop
            }

            return returnable.empty() ? State::EMPTY : State::FULL;
        }
    }

    State CheckFileStability(File *file) {
        if (!file) return State::NON_EXISTENT;

        return IsFileBlankBasedOnBuffer(file);
    }
}

#endif /*FOLLY_BLOSSOM_FILE_HPP*/
