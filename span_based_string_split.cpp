#include <span>
#include <string_view>
#include <vector>
#include <print>

std::vector<std::string_view> split(std::string_view s, char delim = ' ') {
    std::vector<std::string_view> result;
    std::size_t start = 0;
    while (start < s.size()) {
        auto end = s.find(delim, start);
        if (end == std::string_view::npos) end = s.size();
        result.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    return result;
}

int main() {
    auto parts = split("apple,banana,cherry,date", ',');
    for (auto p : parts) std::print("[{}] ", p);
    std::println();
}
