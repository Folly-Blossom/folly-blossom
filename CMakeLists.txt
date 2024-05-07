cmake_minimum_required(VERSION 3.28)
project(Folly_Blossom)

set(CMAKE_CXX_STANDARD 14)



add_executable(
        Folly_Blossom
        image-api/image/Image.hpp
        image-api/image/JPGImage.cpp
        file-api/File.hpp
        image-api/image/PNGImage.cpp
        src/Run.cpp
        image-api/image/BMPImage.cpp
        data-api/Data.cpp
        data-api/Data.hpp
        data-api/image/Image.cpp
        data-api/image/Image.hpp
        data-api/text/Text.cpp
        data-api/text/Text.hpp
        data-api/video/Video.cpp
        data-api/video/Video.hpp
        file-data-receive-api/DataReceive.cpp
        data-api/FileData.hpp
        loader-api/Loader.cpp
        loader-api/Loader.hpp
        file-api/FileActions.hpp
)
