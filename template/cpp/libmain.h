#pragma once

#ifndef _LIB_MAIN_H_
#define _LIB_MAIN_H_

#if defined(LIB_EXPORTS) 
    #if defined(_MSC_VER) 
        #define LIB_API __declspec(dllexport)
    #else 
        #define LIB_API __attribute__((visibility("default")))
    #endif 
#else 
    #if defined(_MSC_VER) 
        #define LIB_API __declspec(dllimport) 
    #else 
        #define LIB_API  
    #endif 
#endif 

#endif // _LIB_MAIN_H_ 
