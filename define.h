//
// Created by xfc on 2019/4/6.
//

#ifndef ST_APP_DEFINE_H
#define ST_APP_DEFINE_H
#include <iostream>

#define ERROR_EXIT(arg) do { \
    std::cerr << __FUNCTION__ << " " << arg; \
    exit(0); \
} while(0)

#endif //ST_APP_DEFINE_H
