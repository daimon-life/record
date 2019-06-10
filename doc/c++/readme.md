
### 运算符
#### 常见运算符
* 
#### 重点运算符

* [typeid](https://zh.cppreference.com/w/cpp/language/typeid)
```C++
typeid(类型);
typeid(表达式);
// windows result: int
const std::type_info& sIntInfo = typeid(int);
std::cout << sIntInfo.name() << std::endl;
```
