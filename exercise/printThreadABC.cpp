#include <iostream>
#include <thread>
#include <condition_variable>
#include <functional>
#include <vector>
#include <algorithm>

/**
 * @brief 题目
 * 三个线程交替打印 ABC 10 次
 */

std::mutex mtx;
std::condition_variable cv;
char ready = 0;

void print_fun(char chId)
{
    int cnt = 10;
    char ch = chId - 'A';

    for (int i = 0; i < cnt; ++i)
    {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [ch]
                { return ch == ready; });
        std::cout << std::this_thread::get_id() << ": "
                  << (char)(ch + 'A') << std::endl;
        ready = (ch + 1) % 3;
        // lk.unlock();

        cv.notify_all();
    }
}

int main()
{
    std::vector<std::thread> threads;
    threads.push_back(std::thread(print_fun, 'A'));
    threads.push_back(std::thread(print_fun, 'B'));
    threads.push_back(std::thread(print_fun, 'C'));

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return 0;
}
