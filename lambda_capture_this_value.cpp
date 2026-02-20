#include <iostream>
#include <functional>
#include <vector>

struct Counter {
    int value = 0;

    auto make_incrementer() {
        int local = value;                    // capture by value
        return [local, this]() mutable {
            ++local;
            ++value;
            std::cout << "local: " << local << ", member: " << value << "\n";
        };
    }
};

int main() {
    Counter c;
    auto inc = c.make_incrementer();

    inc(); inc(); inc();
    // local grows independently, member is shared
}
