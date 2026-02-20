#include <iostream>
#include <string>
#include <utility>

class Buffer {
    char* data = nullptr;
    size_t size = 0;

public:
    Buffer(size_t n) : size(n), data(new char[n]) {
        std::cout << "Allocated " << n << " bytes\n";
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Freed " << size << " bytes\n";
    }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other) noexcept
        : data(std::exchange(other.data, nullptr)),
          size(std::exchange(other.size, 0)) {
        std::cout << "Move constructor\n";
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = std::exchange(other.data, nullptr);
            size = std::exchange(other.size, 0);
            std::cout << "Move assignment\n";
        }
        return *this;
    }
};

int main() {
    Buffer b1(1000);
    Buffer b2 = std::move(b1);      // move constructor
    Buffer b3(500);
    b3 = std::move(b2);             // move assignment
}
