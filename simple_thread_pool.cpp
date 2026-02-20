#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <iostream>

class SimpleThreadPool {
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    bool stop = false;
    std::vector<std::jthread> workers;

public:
    explicit SimpleThreadPool(size_t num = 4) {
        for (size_t i = 0; i < num; ++i) {
            workers.emplace_back([this](std::stop_token st) {
                while (!st.stop_requested()) {
                    std::function<void()> task;
                    {
                        std::lock_guard lk{mtx};
                        if (tasks.empty()) continue;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    void enqueue(std::function<void()> f) {
        std::lock_guard lk{mtx};
        tasks.push(std::move(f));
    }
};

int main() {
    SimpleThreadPool pool(3);

    for (int i = 1; i <= 10; ++i) {
        pool.enqueue([i]{ 
            std::cout << "Task " << i << " on thread " 
                      << std::this_thread::get_id() << "\n"; 
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Done\n";
}
