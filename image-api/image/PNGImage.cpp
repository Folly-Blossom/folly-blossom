#include "Image.hpp"

namespace Folly {
    class PNGImage : public Image {
    public:
        Image* Encrypt() override {
            return new PNGImage;
        }

        Image* Decrypt() override {
            return new PNGImage;
        }

        void Save() override {

        }

        void Load() override {

        }

        static bool GetTransparency(const PNGImage *PNG) {
            isTransparent = true;

            return PNG -> isTransparent;
        }

    private:
        static bool isTransparent;
    };
}
