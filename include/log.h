
/*
    模拟日志打印：应用软件为了方便定位问题，打印日志；仿真认为性能要求比较高，不打印日志
*/
#pragma once


#ifdef REAL
#define LOG_ERR(...) std::cout << __VA_ARGS__ << std::endl;
#else
#define LOG_ERR(...) do {} while(0)
#endif
