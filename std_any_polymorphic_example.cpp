#include <any>
#include <iostream>
#include <string>
#include <vector>

void print(const std::any& a) {
    if (auto* p = std::any_cast<int>(&a)) {
        std::cout << "int: " << *p << "\n";
    } else if (auto* p = std::any_cast<std::string>(&a)) {
        std::cout << "string: " << *p << "\n";
    } else if (auto* p = std::any_cast<double>(&a)) {
        std::cout << "double: " << *p << "\n";
    } else {
        std::cout << "unknown type\n";
    }
}

int main() {
    std::vector<std::any> items { 42, std::string("hello"), 3.14, 100 };

    for (const auto& item : items) {
        print(item);
    }
}
