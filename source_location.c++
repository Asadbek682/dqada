#include <source_location>
#include <string_view>
#include <print>

void trace(std::string_view msg,
           std::source_location loc = std::source_location::current()) {
    std::print("[{}:{}] {}\n", loc.function_name(), loc.line(), msg);
}

int calculate(int x) {
    trace("entering calculate");
    int result = x * x + 17;
    trace("leaving calculate");
    return result;
}

int main() {
    trace("program start");
    calculate(42);
}
