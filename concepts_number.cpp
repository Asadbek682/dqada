#include <concepts>
#include <iostream>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<Number T>
T square(T x) { return x * x; }

int main() {
    std::cout << square(7)      << "\n";     // 49
    std::cout << square(2.5)    << "\n";     // 6.25
    // square("hi");  // compile error
}
