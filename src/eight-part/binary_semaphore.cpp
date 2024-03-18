#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore sem(0); //初始化为0,无信号状态

void worker() {
    std::cout << "woker: waiting for signal..\n";
    sem.acquire(); //等待信号
    std::cout << "worker: received signal, processing\n";
}

int main() {
    std::thread t(worker) ;
    std::cout << "main: sleeping for 2 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); //模拟工作
    
    std::cout << "main: sending signal to worker thread.. \n";
    sem.release(); //发送信号，让worker继续执行

    t.join();
    return 0;
}