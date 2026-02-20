#include <memory>
#include <iostream>
#include <cstdio>

struct FileCloser {
    void operator()(FILE* f) const {
        if (f) {
            std::cout << "Closing file...\n";
            fclose(f);
        }
    }
};

int main() {
    auto file = std::unique_ptr<FILE, FileCloser>(fopen("test.txt", "w"));
    if (file) {
        fputs("Hello from unique_ptr!\n", file.get());
    }
    // file auto-closed with message when leaving scope
}
