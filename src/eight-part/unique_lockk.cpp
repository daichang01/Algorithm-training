#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) cv.wait(lck);
    // 当 ready == true 时继续执行
    std::cout << "Thread #" << id << '\n';
}

void go() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all(); // 唤醒所有等待线程
}

int main() {
    std::thread threads[10];
    // 创建多个线程
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);
    std::cout << "10 threads ready to race...\n";
    go(); // 启动所有线程

    for (auto& th : threads) th.join();
    return 0;
}
