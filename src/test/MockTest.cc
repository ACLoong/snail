#include <iostream>
#include "MockKVStore.hpp"
#include "minunint.h"
using std::cout;
using std::endl;

snail::MockKVStore mock;
MU_TEST(Debug_put) {
	bool b = mock.put("123", "qwe");
	cout << "insert \"123\" " << ( b  ? "success" : "failed" ) << endl;
		
	b  = mock.put("123", "qwe");
	cout << "insert \"123\" " << ( b  ? "success" : "failed" ) << endl;
	
	std::string key = "key";
	std::string value = "value";
	b  = mock.put(key, value);
	cout << "insert \"key\" " << ( b  ? "success" : "failed" ) << endl;
}
MU_TEST(Debug_get) {
	bool b;
	std::string key = "123", value;
	
	b = mock.get(key);	
	cout << "get \"123\" " << (b ? "success" : "failed") << endl;	
	
	b = mock.get(key, value);	
	cout << "get \"123\" " << (b ? "success" : "failed") << " value : " << value << endl;
	
	b = mock.get("123");	
	cout << "get \"123\" " << (b ? "success" : "failed") << " value : " << value << endl;
	
	b = mock.get(std::move(key), value);	
	cout << "get \"123\" " << (b ? "success" : "failed") << " value : " << value << endl;
}
int main()
{
	MU_RUN_SUITE(Debug_put);
	MU_RUN_SUITE(Debug_get);
	MU_REPORT();
	
	return 0;
}

