
### 运算符
#### 常见运算符
* 
#### 重点运算符

* [typeid](https://zh.cppreference.com/w/cpp/language/typeid)
* [<<和>>](...)
```C++
typeid(类型);
typeid(表达式);
// windows result: int
const std::type_info& sIntInfo = typeid(int);
std::cout << sIntInfo.name() << std::endl;
```
```C++
// << 和 >>
class CInitclass
{
public:
	friend ostream& operator<<(ostream& os, CInitclass& c);
	friend istream& operator>>(istream& is, CInitclass& c);

public:
	string szDescription;
};

// CInitclass <<
ostream& operator<<(ostream& os, CInitclass& c)
{
	os << "Description: " << c.szDescription;
	return os;
}
istream& operator>>(istream& is, CInitclass& c)
{
	is >> c.szDescription;
	return is;
}
```
