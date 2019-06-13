##### std::initlizer_list<T> 代表 {}类型
```C++
#include <iostream>
#include <string>
#include <typeinfo>

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
	// initlizer_list   typeid{}
	auto szInitList = { "aaa", "bbb", "ccc" };
	std::cout << typeid(szInitList).name() << std::endl;
	// initlizer_list   pair
	enum pic_fmt { png = 0, jpg, bmp };
	auto pairInitList = 
	{
		std::make_pair("png", png),
		std::make_pair("jpg", jpg),
		std::make_pair("bmp", bmp)
	};
	for (auto& it : pairInitList)
	{
		if ("bmp" == std::string(it.first))
		{
			std::cout << it.second << std::endl;
		}
	}
	return 0;
}
```
##### std::initlizer_list<T> 主要用途 c++11初始化列表
```C++

#include <iostream>
#include <string>
using namespace std;

class CVar
{
public:
	CVar(const char* sz)
	{
		m_str = sz;
	}
	CVar(string sz)
	{
		m_str = sz;
	}
	CVar(int i)
	{
		m_i = i;
	}
public:
	string m_str;
	int    m_i;
};
//
class CInitclass
{
public:
	friend ostream& operator<<(ostream& os, CInitclass& c);
	friend istream& operator>>(istream& is, CInitclass& c);

public:
	CInitclass(initializer_list<CVar> initlist)
	{
		for (auto& it : initlist)
		{
			if (m_szDescription.empty())
			{
				m_szDescription = it.m_str;
			}
			else
			{
				m_iValue = it.m_i;
			}
		}
	};

	string m_szDescription;

private:
	int    m_iValue;
};

// CInitclass <<
ostream& operator<<(ostream& os, CInitclass& c)
{
	os << "Description: " << c.m_szDescription << " " << c.m_iValue;
	return os;
}
istream& operator>>(istream& is, CInitclass& c)
{
	is >> c.m_szDescription;
	return is;
}

// start execute
int main(int argc, char** argv)
{
	CInitclass c1 = { "first initlizer list class ", 23 };
	std::cout << c1 << std::endl;
	std::cin >> c1;
	std::cout << c1 << std::endl;

	return 0;
}
```
