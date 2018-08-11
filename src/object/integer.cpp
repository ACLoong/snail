#include "integer.h"

namespace snail {
    void Integer::assign_(int num) {
        if (num == 0) {
            return ;
        }

        if (num < 0) {
            isNegative = true;
            num = - num;
        } else {
            isNegative = false;
        }

        while (num) {
            data_->push_back(num % 10);
            num = num / 10;
        }
    }
}
