#include <thread>
#include <stop_token>
#include <iostream>
#include <chrono>

void worker(std::stop_token st) {
    int i = 0;
    while (!st.stop_requested()) {
        std::cout << "working... " << ++i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "worker stopped cleanly\n";
}

int main() {
    std::jthread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "main exiting\n";
}
