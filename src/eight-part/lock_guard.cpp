#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // 互斥量，用于同步对共享数据的访问

void print_thread_id(int id) {
    std::lock_guard<std::mutex> guard(mtx); // 自动加锁
    // 当离开这个作用域时，lock_guard 的析构函数会被调用，自动解锁
    std::cout << "Thread #" << id << '\n';
    // 注意：此处无需手动调用 mtx.unlock()
}

int main() {
    std::vector<std::thread> threads;

    // 创建并启动 10 个线程
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(print_thread_id, i + 1);
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
