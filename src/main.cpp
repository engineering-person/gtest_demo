#include <iostream>
#include <vector>
#include <stdint.h>

/*
    错误码返回算法库：应用软件为了方便定位问题，返回错误码；仿真认为性能要求比较高，不返回
*/

enum class ErrorCode : uint32_t {
    SUCCESS = 0,
    VLAUDE_TOO_HIGH,
    PARAM_INVALID
};

struct ErrorInfo
{
    std::vector<ErrorCode> errVec;
#ifdef REAL
    ErrorInfo& operator<<(ErrorCode code) { errVec.push_back(code); return *this; }
#else
    ErrorInfo& operator<<(ErrorCode /*code*/) { return *this; }
#endif

};


/*
    模拟日志打印：应用软件为了方便定位问题，打印日志；仿真认为性能要求比较高，不打印日志
*/

#ifdef REAL
#define LOG_ERR(...) std::cout << __VA_ARGS__ << std::endl;
#else
#define LOG_ERR(...) do {} while(0)
#endif




/*
    模拟算法库的接口
*/

inline void CalInterface(const std::string& input, ErrorInfo& err)
{
    /*
    
    */
    for (int i = 0; i < 100; ++i) {
        err << ErrorCode::SUCCESS;
        err << ErrorCode::VLAUDE_TOO_HIGH;
        err << ErrorCode::PARAM_INVALID;
        LOG_ERR("只有应用软件才会打印日志......i = " << i << ", code = " << uint32_t(ErrorCode::PARAM_INVALID));
    }
}

/*
    mkdir build
    cd build
    每次编译一定要，因为有缓存
    cmake .. -DMY_CMAKE_BUILD_FLAGS=real   /   cmake .. 
    make 
*/

int main()
{
    ErrorInfo err;
    CalInterface("111111", err);
    std::cout << "err::errVec size: " << err.errVec.size() << std::endl;
    return 0;
}
