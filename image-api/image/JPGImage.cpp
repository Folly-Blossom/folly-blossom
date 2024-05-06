#include "Image.h"

class JPGImage : public Image {
public:
    Image* Encrypt() override {
        return {};
    }

    Image* Decrypt() override {
        return {};
    }

    void Load() override {

    }

    void Save() override {

    }
};