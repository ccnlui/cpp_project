#include <chrono>
#include <cstdio>
#include <thread>

#include "blockingconcurrentqueue.h"

int main()
{
    moodycamel::BlockingConcurrentQueue<int> q;

    std::thread t1{ [&]() {
        for (int n = 0; n < 10; n++) {
            q.enqueue(n);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } };

    std::thread t2{ [&]() {
        while (true) {
            int i;
            q.wait_dequeue(i);
            printf("got: %d\n", i);
            if (i == 10)
                return;
        }
    } };

    t1.join();
    t2.join();
}