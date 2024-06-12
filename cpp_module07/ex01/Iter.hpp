#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template<typename Func>
void print(Func const &x) {
    std::cout << x << std::endl;
}

template <typename T, typename Func>
void iter(T *arr, size_t len, Func func) {
  for (size_t i = 0; i < len; i++)
    f(arr[i]);
}

#endif
