#include <iostream>
#include <future>
#include <thread>

void consumer(std::future<int>& fut) {
    int x = fut.get(); //等待生产者设置值
    std::cout << "recevie value: " << x << std::endl;
}

int main() {
    std::promise<int> prom; //生产者承诺
    std::future<int> fut = prom.get_future(); //从承诺中获得future
    std::thread t(consumer, std::ref(fut)); //创建消费者线程，传递future

    //生产者工作
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    prom.set_value(10); //生产者提供值

    t.join(); 
    return 0;
}