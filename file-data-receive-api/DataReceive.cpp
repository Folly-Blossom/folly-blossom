#include "../data-api/Data.h"
#include "../data-api/FileData.h"

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