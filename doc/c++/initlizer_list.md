```C++

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(int argc, char** argv)
{
	// initlizer_list   auto
	auto c1 = { "aaa", "bbb", "ccc" };
	for (auto& it : c1)
	{
		std::cout << it << std::endl;
	}
	// initlizer_list   for(:)
	for (auto& it : { "aaa", "bbb", "ccc" })
	{
		std::cout << typeid(it).name() << "" << it << std::endl;
	}
	// 
	auto szInitList = { "aaa", "bbb", "ccc" };
	std::cout << typeid(szInitList).name() << std::endl;

	return 0;
}
```
