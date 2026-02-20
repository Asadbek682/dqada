#include <vector>
#include <ranges>
#include <algorithm>
#include <print>

int main() {
    std::vector<int> items { 9, 2, 7, 2, 4, 11, 4, 8, 1 };

    // Sort + unique → "flat set" behavior
    std::ranges::sort(items);
    auto [first, last] = std::ranges::unique(items);
    items.erase(first, last);

    std::print("Unique sorted values: ");
    for (int x : items) std::print("{} ", x);
    std::println();
}
