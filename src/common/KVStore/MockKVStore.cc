#include "MockKVStore.hpp"

namespace snail{
	
	MockKVStore_result_type MockKVStore::put(const std::string &key, const std::string &value){
		auto result = hashmap_.insert(std::make_pair(key, value)).second;
		return MockKVStore_result_type(result);
	}
	MockKVStore_result_type MockKVStore::put(const std::string &&key, const std::string &&value){
		auto result = hashmap_.insert(std::make_pair(key, value)).second;
		return MockKVStore_result_type(result);
	}
	MockKVStore_result_type MockKVStore::get(const std::string &key) {
		auto result = hashmap_.find(key);
		if (result != hashmap_.end()){
			return MockKVStore_result_type(true, result->second);
		}else{
			return MockKVStore_result_type(false);
		}
	}
	MockKVStore_result_type MockKVStore::get(const std::string &&key) {
		auto result = hashmap_.find(key);
		if (result != hashmap_.end()){
			return MockKVStore_result_type(true, result->second);
		}else{
			return MockKVStore_result_type(false);
		}
	}
}