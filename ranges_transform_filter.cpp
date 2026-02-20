#include <vector>
#include <ranges>
#include <iostream>

int main() {
    std::vector<int> nums = { -4, 7, 2, -1, 9, 0, 5, -3, 8 };

    auto processed = nums
        | std::views::filter([](int x){ return x >= 0; })
        | std::views::transform([](int x){ return x * x; })
        | std::views::take(5);

    std::cout << "Squares of first 5 non-negative: ";
    for (int x : processed) std::cout << x << " ";
    std::cout << "\n";
}
