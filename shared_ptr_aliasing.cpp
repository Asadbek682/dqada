#include <memory>
#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age = 0;
};

int main() {
    auto p = std::make_shared<Person>(Person{"Elena", 28});

    // aliasing constructor — share ownership, but point to member
    std::shared_ptr<std::string> name_ptr(p, &p->name);

    std::cout << "Name: " << *name_ptr << "\n";
    std::cout << "use_count of person: " << p.use_count() << "\n";
    std::cout << "use_count of name:   " << name_ptr.use_count() << "\n";

    // both pointers keep the Person alive
}
