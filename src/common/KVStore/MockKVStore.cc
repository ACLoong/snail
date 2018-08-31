#include "MockKVStore.hpp"

namespace snail{
	bool MockKVStore::put(const std::string &key, const std::string &value){
		auto result = store_.insert(std::make_pair(key, value)).second;
		return result;
	}
	bool MockKVStore::put(const std::string &&key, const std::string &&value){
		auto result = store_.insert(std::make_pair(key, value)).second;
		return result;
	}
	bool MockKVStore::get(const std::string &key)const {
		auto result = store_.find(key);
		if (result != store_.end()){
			return true;
		}else{
			return false;
		}
	}	
	bool MockKVStore::get(const std::string &key, std::string &value)const {
		auto result = store_.find(key);
		if (result != store_.end()){
			value = result->second;
			return true;
		}else{
			return false;
		}
	}
	bool MockKVStore::get(const std::string &&key)const {
		auto result = store_.find(key);
		if (result != store_.end()){
			return true;
		}else{
			return false;
		}
	}	
	bool MockKVStore::get(const std::string &&key, std::string &value)const {
		auto result = store_.find(key);
		if (result != store_.end()){
			value = result->second;
			return true;
		}else{
			return false;
		}
	}
}

