// src/calc.cpp
#include "lab/calc.hpp"
#include <numeric>

namespace lab {
double clamp(double v, double lo, double hi) {
  if (lo > hi) return v;          // 非法区间：不做处理，原样返回
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

double mean(const std::vector<double>& xs) {
  if (xs.empty()) return 0.0;
  return std::accumulate(xs.begin(), xs.end(), 0.0) / static_cast<double>(xs.size());
}
}