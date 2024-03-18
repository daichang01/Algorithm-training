#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 默认为最大堆
    priority_queue<int> tasks;

    // 添加任务的优先级
    tasks.push(10); // 低优先级任务
    tasks.push(50); // 高优先级任务
    tasks.push(20); // 中优先级任务

    // 按优先级处理任务
    while (!tasks.empty()) {
        cout << "处理任务，优先级：" << tasks.top() << endl;
        tasks.pop(); // 完成任务，移除任务
    }
    return 0;
}
