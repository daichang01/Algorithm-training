#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>

std::counting_semaphore<4> sem(4); //允许同时有4个线程运行

void worker(int id) { //定义工作线程函数，接受一个表示线程ID的整数
    sem.acquire(); //尝试获得信号量。如果信号量计数>0,则计数减1并继续；否则线程阻塞
    std::cout << "worker:" << id << "is working...\n" ;
    std::this_thread::sleep_for(std::chrono::seconds(1)); //模拟工作
    std::cout << "worker" << id << "finished working\n";
    sem.release(); //线程完成工作，释放信号量，信号量计数+1

}

int main() {
    std::vector<std::thread> workers; //定义一个std::thread类型的向量，用于存储线程工作
    for(int i = 0; i < 10; ++i) {
        //c创建10个工作线程
        workers.emplace_back(worker, i);
    }
    for (auto& t: workers) {
        t.join();
    }

    return 0;
}