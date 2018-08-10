//
// Created by WangQing on 10/08/2018.
//

#ifndef SNAIL_IKVSTORE_H
#define SNAIL_IKVSTORE_H

#include "object.h"
#include "status.h"

namespace snail {
    /**
     *
     */
    class IKVStore {
    public:
        IKVStore() = default;
        virtual ~IKVStore() = default;

    protected:
        /**
         *
         * @param key
         * @return
         */
        virtual Status get(const HashableObject &key, Object *value) const = 0;

        /**
         *
         * @param key
         * @param value
         * @return
         */
        virtual Status put(const Object &key, const Object &value) = 0;

        /**
         *
         * @param key
         * @return
         */
        virtual Status remove(const HashableObject &key) const ;

        /**
         *
         */
        virtual void clear() = 0;
    };
}

#endif //SNAIL_IKVSTORE_H
