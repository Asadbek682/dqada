#include <bit>
#include <iostream>

enum class Permission : unsigned {
    None   = 0,
    Read   = 1 << 0,
    Write  = 1 << 1,
    Exec   = 1 << 2,
    All    = Read | Write | Exec
};

constexpr Permission operator|(Permission a, Permission b) {
    return static_cast<Permission>(
        static_cast<unsigned>(a) | static_cast<unsigned>(b));
}

constexpr bool has_flag(Permission flags, Permission flag) {
    return (static_cast<unsigned>(flags) & static_cast<unsigned>(flag)) != 0;
}

int main() {
    Permission user = Permission::Read | Permission::Write;

    std::cout << std::boolalpha;
    std::cout << "Can read:  " << has_flag(user, Permission::Read)  << "\n";
    std::cout << "Can exec:  " << has_flag(user, Permission::Exec)  << "\n";
    std::cout << "Has write: " << has_flag(user, Permission::Write) << "\n";
}
