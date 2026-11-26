// include/lab/calc.hpp
#pragma once
#include <vector>

namespace lab {
// 限幅：把 v 夹到 [lo, hi]
double clamp(double v, double lo, double hi);
// 均值；空输入返回 0
double mean(const std::vector<double>& xs);
}