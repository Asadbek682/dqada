#include <expected>
#include <string>
#include <print>

std::expected<double, std::string> safe_divide(double a, double b) {
    if (b == 0.0) return std::unexpected("Division by zero");
    return a / b;
}

int main() {
    auto res1 = safe_divide(100, 4);
    auto res2 = safe_divide(100, 0);

    std::print("100 / 4 = {}\n", res1.value_or(-1));
    std::print("100 / 0 → {}\n", res2.error_or("ok"));
}
