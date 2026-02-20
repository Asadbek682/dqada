#include <string_view>
#include <iostream>

enum class Color { Red, Green, Blue, Yellow };

constexpr std::string_view to_string(Color c) {
    switch (c) {
        case Color::Red:    return "Red";
        case Color::Green:  return "Green";
        case Color::Blue:   return "Blue";
        case Color::Yellow: return "Yellow";
        default:            return "???";
    }
}

int main() {
    Color c = Color::Green;
    std::cout << "Color: " << to_string(c) << "\n";
}
