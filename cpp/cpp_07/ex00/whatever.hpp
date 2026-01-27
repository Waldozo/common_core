#pragma once
#include <iostream>

template <typename T> void swap(T& a, T& b){
    T temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename U> const U& min(const U& a, const U& b){
    if (a < b)
        return a;
    return b;
}

template <typename V> const V& max(const V& a, const V& b){
    if(a > b)
        return a;
    return b;
}