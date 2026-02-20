#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, int> scores;

    // C++17/20 style - insert or default
    scores.try_emplace("Alice", 0);
    scores["Bob"] += 15;           // auto default-constructs to 0 first
    scores.at("Alice") += 100;

    for (const auto& [name, pts] : scores) {
        std::cout << name << ": " << pts << "\n";
    }
}
