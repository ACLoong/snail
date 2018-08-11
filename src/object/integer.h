#ifndef SNAIL_INTEGER_H
#define SNAIL_INTEGER_H

#include "hashable_object.h"
#include "object.h"
#include "def.h"

#include <vector>
#include <memory>

namespace snail {
    class Integer: public HashableObject {
    public:
        Integer(int num = 0)
                : data_(std::make_shared<std::vector<byte>>(Constants::Init_Size)) {
            assign_(num);
        }

        Integer(const std::vector<byte> &bytes)
                :data_(std::make_shared<std::vector<byte>>(bytes)) {}

        Integer(const Integer &num);
        Integer &operator= (const Integer &num);
        byte &operator[] (size_t index);

    private:
        void assign_(int num) ;

    private:
        std::shared_ptr<std::vector<byte>> data_ = nullptr;
        bool isNegative = false;
    };
}

#endif //SNAIL_INTEGER_H
