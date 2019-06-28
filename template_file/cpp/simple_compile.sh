#!/bin/bash 
rm *.o *.so 
rm main 
g++ -c -fPIC -g -Wall -std=c++11 libmain.cpp 
g++ -c -fPIC -g -Wall -std=c++11 mylib.cpp 
g++ -shared libmain.o mylib.o -o libmy.so 
g++ -c -g -Wall -std=c++11 main.cpp 
g++ main.o -L. -lmy -o main -Wl,-rpath,'$ORIGIN' 
