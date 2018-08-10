//
// Created by WangQing on 11/08/2018.
//

#ifndef SNAIL_HASHABLE_H
#define SNAIL_HASHABLE_H

#include "object.h"

namespace snail {

class HashableObject: public Object {
public:
    HashableObject() = default;
    virtual ~HashableObject() = default;
    virtual std::string hashcode() const = 0;

protected:
};

}

#endif //SNAIL_HASHABLE_H
