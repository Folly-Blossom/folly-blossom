#include "Image.hpp"

namespace Folly {
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
}
