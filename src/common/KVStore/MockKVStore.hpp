#ifndef _MOCK_KVSTORE_
#define _MOCK_KVSTORE_

#include <unordered_map>
#include "IKVStore.hpp"

namespace snail{

class MockKVStore : implements IKVStore{
public:
	MockKVStore() = default;
	virtual ~MockKVStore() = default;
	bool put(const std::string &key, const std::string &value);
	bool put(const std::string &&key, const std::string &&value);
	bool get(const std::string &key) const;
	bool get(const std::string &key, std::string &value) const;
	bool get(const std::string &&key) const;
	bool get(const std::string &&key, std::string &value) const;
private:
	std::unordered_map<std::string, std::string> store_;
};
}

#endif

