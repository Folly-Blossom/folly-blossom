#include "../data-api/Data.hpp"
#include "../data-api/FileData.hpp"

namespace Folly {
    class DataReceive {
    public:
        explicit DataReceive(Data *receive) {
            receive = data;
        }

        ~DataReceive() {
            delete data;
        }


    private:
        Data *data{};

        FileData fileData;
    };
}
