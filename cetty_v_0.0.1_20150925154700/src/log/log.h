#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#ifndef CETTY_LOG_
#define CETTY_LOG_
using namespace std;
typedef enum LEVEL{
    INFO = 1,
    DEBUG = -1,
    ERROR = -2
} LEVEL;

void log( LEVEL l,string s);
#endif
