#include <concepts>
#include <print>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<Number T>
T square(T x) {
    return x * x;
}

int main() {
    std::print("square(7)    = {}\n", square(7));
    std::print("square(3.14) = {:.4f}\n", square(3.14));
    // square("hello");  // compile error – nice!
}
