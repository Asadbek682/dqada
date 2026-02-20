#include <thread>
#include <stop_token>
#include <print>
#include <chrono>

void background_work(std::stop_token st) {
    int counter = 0;
    while (!st.stop_requested()) {
        std::print("→ {}\n", ++counter);
        std::this_thread::sleep_for(std::chrono::milliseconds(350));
    }
    std::println("Background task stopped cleanly");
}

int main() {
    std::jthread worker(background_work);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::println("Main is done → worker will stop");
}
