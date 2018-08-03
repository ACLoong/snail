#include <iostream>

#include "minunint.h"
#include "MockKVStore.hpp"
snail::MockKVStore mock;
MU_TEST(Debug_put) {
	mock.put("123", "qwe");
}
MU_TEST(Debug_get) {
	mock.put("123", "qwe");
	auto &&result = mock.get("123");	
	std::cout << result.getValue() << std::endl;
}
int main()
{
	MU_RUN_SUITE(Debug_put);
	MU_RUN_SUITE(Debug_get);
    MU_REPORT();
	
	return 0;
}