#include <expected>
#include <string>
#include <print>

std::expected<int, std::string> parse(std::string s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::unexpected("Not a number: " + s);
    }
}

int main() {
    auto result = parse("42")
        .and_then([](int x) -> std::expected<int, std::string> {
            return x * 2;
        })
        .transform([](int x) { return x + 10; })
        .or_else([](const std::string& err) {
            std::print("Error: {}\n", err);
            return std::expected<int, std::string>{0};
        });

    std::print("Final value: {}\n", *result);
}
