//
// Created by WangQing on 11/08/2018.
//

#include "mock_kvstore.h"
#include "hashable_object.h"

namespace snail {
    Status MockKVStore::get(const HashableObject &key, Object *value) const {
        return store_.at(key.hashcode());
    }

    Status MockKVStore::put(const HashableObject &key, const Object &value) {
        CacheEntry entry(key, value);
        store_.insert(key.hashcode(), entry);

        return Status();
    }

    Status MockKVStore::remove(const HashableObject &key) override {
        auto it = store_.find(key.hashcode());
        store_.erase(it);

        return Status();
    }

    void MockKVStore::clear() {
        store_.clear();
    }
}
