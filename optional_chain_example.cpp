#include <optional>
#include <string>
#include <iostream>

struct User {
    std::optional<std::string> name;
    std::optional<int> age;
};

int main() {
    User u1{ .name = "Anna", .age = 29 };
    User u2{ .name = "Mike" };

    auto get_age_str = [](const User& u) -> std::string {
        return u.age
            .transform([](int a){ return std::to_string(a) + " years"; })
            .value_or("age unknown");
    };

    std::cout << u1.name.value_or("???") << ": " << get_age_str(u1) << "\n";
    std::cout << u2.name.value_or("???") << ": " << get_age_str(u2) << "\n";
}
