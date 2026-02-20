#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path dir = ".";
    try {
        for (const auto& entry : fs::directory_iterator(dir)) {
            if (entry.is_regular_file()) {
                std::cout << entry.path().filename() << "  ("
                          << entry.file_size() << " bytes)\n";
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
