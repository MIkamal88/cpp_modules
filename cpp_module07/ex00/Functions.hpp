#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>

// Swap
template <typename T> void swap(T &a, T &b) {
  T tmp = a;

  a = b;
  b = tmp;
}

// Min
template <typename T> T min(T &a, T &b) { return (a < b ? a : b); }

// Max
template <typename T> T max(T &a, T &b) { return (a > b ? a : b); }

#endif
