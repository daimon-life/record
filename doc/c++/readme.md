
### 运算符
#### 常见运算符
* 
#### 重点运算符

* [typeid](https://zh.cppreference.com/w/cpp/language/typeid)
```C++
// result: int .H
const std::type_info& sIntInfo = typeid(int);
std::cout << sIntInfo.name() << " " << sIntInfo.raw_name() << std::endl;
```
