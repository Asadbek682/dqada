#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

std::string trim(std::string_view s) {
    auto start = s.find_first_not_of(" \t\n\r");
    if (start == std::string_view::npos) return {};
    auto end = s.find_last_not_of(" \t\n\r");
    return std::string{s.substr(start, end - start + 1)};
}

std::vector<std::string> split(std::string_view s, char delim = ',') {
    std::vector<std::string> result;
    auto view = s | std::views::split(delim);
    for (auto part : view) {
        result.emplace_back(part.begin(), part.end());
    }
    return result;
}

std::string join(const std::vector<std::string>& vec, std::string_view sep = ", ") {
    if (vec.empty()) return {};
    std::string res = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        res += sep;
        res += vec[i];
    }
    return res;
}

int main() {
    std::string dirty = "  hello   world  \t\n";
    std::cout << "trim: '" << trim(dirty) << "'\n";

    auto parts = split("apple, banana , cherry,date");
    std::cout << "split: " << join(parts, " | ") << "\n";
}
