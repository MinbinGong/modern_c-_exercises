#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int g_num;
std::mutex g_num_mutex;

void slow_increment(int id)
{
    for (int i = 0; i < 3; ++i)
    {
        g_num_mutex.lock();
        ++g_num_mutex;
        std::cout << id << " => " << g_num << std::endl;
        g_num_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread t1(slow_increment, 0);
    std::thread t2(slow_increment, 1);
    t1.join();
    t2.join();

    return 0;
}