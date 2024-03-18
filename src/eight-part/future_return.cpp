#include <iostream>
#include <future>
#include <thread>

int produce() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 42; //生成产品
}

int main() {
    //使用std::async启动异步任务
    std::future<int> fut = std::async(std::launch::async, produce);

    //获取异步任务的结果
    int x = fut.get();
    std::cout << "product: " << x << std::endl;
    return 0;
}