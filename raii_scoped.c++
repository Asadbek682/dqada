#include <chrono>
#include <print>
#include <thread>

struct ScopedTimer {
    using clk = std::chrono::steady_clock;
    clk::time_point start = clk::now();
    const char* name;

    explicit ScopedTimer(const char* n = "Block") : name(n) {}
    ~ScopedTimer() {
        auto dur = clk::now() - start;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::print("{} took {} ms\n", name, ms.count());
    }
};

int main() {
    {
        ScopedTimer t("Heavy computation");
        std::this_thread::sleep_for(std::chrono::milliseconds(480));
    }
}
