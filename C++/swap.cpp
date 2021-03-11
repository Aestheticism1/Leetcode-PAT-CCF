#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main(){
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
}

