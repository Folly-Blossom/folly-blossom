#include "Image.hpp"

namespace Folly {
    class BMPImage : public Image {
    public:
        Image* Encrypt() override {
            return {};
        }

        Image* Decrypt() override {
            return {};
        }

        void Save() override {

        }

        void Load() override {

        }
    };
}
