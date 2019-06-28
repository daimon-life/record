#### mylib.h   follow as:
```c++
#include "libmain.h" 
LIB_API void print(); 
```

#### mylib.cpp follow as:
```c++
#include <iostream>
#include "mylib.h"
void print()
{
    std::cout << "print" << __LINE__ << std::endl;
}
```

#### main.cpp follow as:
```c++
#include <iostream>
#include "mylib.h"

int main(int argc, char** argv)
{
    std::cout << "main" << __LINE__ << std::endl;
    print();
    return 0;
}
```
