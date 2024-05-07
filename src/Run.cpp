#include <iostream>
#include <string>
#include "../loader-api/Loader.hpp"

int main() {
    std::cout << "[*] Please specify a file name.";

    const std::string FILE_NAME, FILE_PATH;

    std::cin >> (std::string&) FILE_NAME;

    std::cout << "[*] Please specify the appropiate file path.";

    std::cin >> (std::string&) FILE_PATH;

    if (FILE_NAME.empty() || FILE_PATH.empty()) {
        std::cout << "[-] Either the given file name or path are null and cannot be used.";
    }

    return 0;
}