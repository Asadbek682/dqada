#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {4, 7, 2, 7, 9, 2, 4, 11, 7, 3};

    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());

    for (int x : v) std::cout << x << " ";
    std::cout << "\n";  // 2 3 4 7 9 11
}
