#include <variant>
#include <string>
#include <iostream>

using Value = std::variant<int, double, std::string>;

void print(const Value& v) {
    std::visit([](auto&& arg) {
        std::cout << arg << "\n";
    }, v);
}

int main() {
    Value v1 = 42;
    Value v2 = 3.14;
    Value v3 = std::string("hello");

    print(v1);
    print(v2);
    print(v3);
}
