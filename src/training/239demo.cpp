#include <vector>
#include <iostream>
#include <deque>



class Solution {
private:
    class MyQueue {
    public:
        std::deque<int> que;
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front() {
            return que.front();
        }
    };
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        MyQueue que;
        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main() {
    Solution sol;

    // 示例数组和窗口大小
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // 调用函数并接收结果
    std::vector<int> result = sol.maxSlidingWindow(nums, k);

    // 打印结果
    std::cout << "最大滑动窗口的元素为: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

