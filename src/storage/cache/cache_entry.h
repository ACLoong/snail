//
// Created by WangQing on 11/08/2018.
//

#ifndef SNAIL_CACHE_ENTRY_H
#define SNAIL_CACHE_ENTRY_H

#include "object.h"
#include "hashable_object.h"

namespace snail {
    class CacheEntry {
    public:
    protected:
    private:
        HashableObject key_;
        Object value_;
    };
}

#endif //SNAIL_CACHE_ENTRY_H
