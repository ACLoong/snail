#ifndef _IKVSTORE_
#define _IKVSTORE_

namespace snail{
	
class MockKVStore_result_type{
public:
	MockKVStore_result_type(bool b = false) : is_success_(b), value_("") {}
	MockKVStore_result_type(bool b, std::string& value) : is_success_(b), value_(value){ }
	MockKVStore_result_type(bool b, std::string&& value) : is_success_(b), value_(value){ }
	virtual ~MockKVStore_result_type() = default;
	
	bool is_success()const {return is_success_;} 
	std::string getValue()const {return value_;}
private:
	bool is_success_;
	std::string value_;
};

#define interface struct
interface IKVStore{
	virtual MockKVStore_result_type put(const std::string &key, const std::string &value) = 0;
	virtual MockKVStore_result_type put(const std::string &&key, const std::string &&value) = 0;
	virtual MockKVStore_result_type get(const std::string &key) = 0;
	virtual MockKVStore_result_type get(const std::string &&key) = 0;
};
}
#endif