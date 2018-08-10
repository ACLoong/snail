//
// Created by WangQing on 11/08/2018.
//

#ifndef SNAIL_MOCK_KVSTORE_H
#define SNAIL_MOCK_KVSTORE_H

#include "ikvstore.h"
#include "object.h"
#include "status.h"
#include "cache_entry.h"

#include <string>
#include <unordered_map>

namespace snail {
    class MockKVStore : public IKVStore{
    public:
        MockKVStore() = default;
        ~MockKVStore() = default;

        Status get(const HashableObject &key, Object *value) const override ;
        Status put(const HashableObject &key, const Object &value) override ;
        Status remove(const HashableObject &key) override ;
        void clear() override ;

    protected:
    private:
        std::unordered_map<std::string, CacheEntry> store_;
    };
}

#endif //SNAIL_MOCK_KVSTORE_H
