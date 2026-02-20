#include <chrono>
#include <iostream>
#include <thread>

struct ScopedTimer {
    using Clock = std::chrono::steady_clock;
    Clock::time_point start = Clock::now();
    const char* label;

    explicit ScopedTimer(const char* name = "scope") : label(name) {}
    ~ScopedTimer() {
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            Clock::now() - start).count();
        std::cout << label << " took " << ms << " ms\n";
    }
};

int main() {
    {
        ScopedTimer t("sleep test");
        std::this_thread::sleep_for(std::chrono::milliseconds(420));
    }
}
