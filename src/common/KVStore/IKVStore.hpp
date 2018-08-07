#ifndef _IKVSTORE_
#define _IKVSTORE_

#include "def.hpp"

namespace snail{
	
interface IKVStore{
	virtual bool put(const std::string &key, const std::string &value) = 0;
	virtual bool put(const std::string &&key, const std::string &&value) = 0;
	virtual bool get(const std::string &key) const = 0;
	virtual bool get(const std::string &key, std::string &value) const = 0;
	virtual bool get(const std::string &&key) const = 0;
	virtual bool get(const std::string &&key, std::string &value) const = 0;
};
}
#endif
