#include <coroutine>
#include <optional>
#include <print>

struct IntGenerator {
    struct promise_type {
        std::optional<int> value;
        auto get_return_object() { return IntGenerator{*this}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        std::suspend_always yield_value(int v) { value = v; return {}; }
    };

    std::coroutine_handle<promise_type> h;
    explicit IntGenerator(promise_type& p) : h(std::coroutine_handle<promise_type>::from_promise(p)) {}
    ~IntGenerator() { if (h) h.destroy(); }

    bool advance() { if (h) h.resume(); return h && !h.done(); }
    int get() const { return *h.promise().value; }
};

IntGenerator countdown(int from) {
    while (from >= 0) {
        co_yield from--;
    }
}

int main() {
    auto gen = countdown(8);
    while (gen.advance()) {
        std::print("{} ", gen.get());
    }
    std::println();
}
