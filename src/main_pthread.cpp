#include <atomic>
#include <cstdio>
#include <thread>

void work(std::atomic<int>& a)
{
    for (int i = 0; i < 1'000; i++) {
        a += 1;
        printf("%d\n", a.load());
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main()
{
    std::atomic<int> a{ 0 };

    std::thread t1{ [&]() { work(a); } };
    std::thread t2{ [&]() { work(a); } };
    std::thread t3{ [&]() { work(a); } };

    t1.join();
    t2.join();
    t3.join();
}