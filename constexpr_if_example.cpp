#include <iostream>
#include <type_traits>

template<typename T>
void print_type_info() {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral type, size = " << sizeof(T) << " bytes\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Floating point, size = " << sizeof(T) << " bytes\n";
    } else {
        std::cout << "Other type\n";
    }
}

int main() {
    print_type_info<int>();
    print_type_info<double>();
    print_type_info<std::string>();
}
