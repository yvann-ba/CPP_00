#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
template <typename T, typename Func>
void iter(T* array, size_t length, Func f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif