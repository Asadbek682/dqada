#include <format>
#include <string>
#include <print>

struct RGB {
    uint8_t r, g, b;
};

template<>
struct std::formatter<RGB> {
    constexpr auto parse(auto& ctx) { return ctx.begin(); }
    auto format(const RGB& c, auto& ctx) const {
        return std::format_to(ctx.out(), "#{:02x}{:02x}{:02x}", c.r, c.g, c.b);
    }
};

int main() {
    RGB teal{0, 128, 128};
    std::print("Color: {}\n", teal);  // #008080
}
