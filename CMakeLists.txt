cmake_minimum_required(VERSION 3.28)
project(Folly_Blossom)

set(CMAKE_CXX_STANDARD 14)



add_executable(
        Folly_Blossom
        image-api/image/Image.h
        image-api/image/JPGImage.cpp
        file-api/File.h
        image-api/image/PNGImage.cpp
        src/Run.cpp
        image-api/image/BMPImage.cpp
        data-api/Data.cpp
        data-api/Data.h
        data-api/image/Image.cpp
        data-api/image/Image.h
        data-api/text/Text.cpp
        data-api/text/Text.h
        data-api/video/Video.cpp
        data-api/video/Video.h
        file-data-receive-api/DataReceive.cpp
        data-api/FileData.h
        loader-api/Loader.cpp
        loader-api/Loader.h
)
