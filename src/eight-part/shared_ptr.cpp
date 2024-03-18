#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

std::shared_ptr<int> sharedData;
std::mutex mtx; // 用于同步对 sharedData 的访问

void threadFunc(int newValue) {
    std::lock_guard<std::mutex> lock(mtx); // 锁定互斥体
    sharedData = std::make_shared<int>(newValue); // 安全更新 sharedData
    // mtx 在 lock_guard 被销毁时自动解锁
}

int main() {
    sharedData = std::make_shared<int>(0); // 初始化 sharedData

    std::thread t1(threadFunc, 10);
    std::thread t2(threadFunc, 20);

    t1.join();
    t2.join();

    std::cout << "Shared data: " << *sharedData << std::endl;

    return 0;
}
