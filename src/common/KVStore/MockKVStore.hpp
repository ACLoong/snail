#ifndef _MOCK_KVSTORE_
#define _MOCK_KVSTORE_

#include <unordered_map>
#include "IKVStore.hpp"

namespace snail{

class MockKVStore : public IKVStore{
public:
	MockKVStore() = default;
	virtual ~MockKVStore() = default;
	MockKVStore_result_type put(const std::string &key, const std::string &value);
	MockKVStore_result_type put(const std::string &&key, const std::string &&value);
	MockKVStore_result_type get(const std::string &key);
	MockKVStore_result_type get(const std::string &&key);
private:
	std::unordered_map<std::string, std::string> hashmap_;
};
}

#endif