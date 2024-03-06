#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const std::pair<int, int>&lhs,const std::pair<int, int>&rhs) {
            return lhs.second > rhs.second;
        }
    };
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map; //map<nums[i], times>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        //定义一个小顶堆，大小为k
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, mycomparison> pri_que;
        //用固定大小为k的小顶堆，扫描所有频率的数值
        for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        //找出前k个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        std::vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;

    // 测试数据
    std::vector<int> nums = {1, 1, 1, 2, 2, 3,3,3};
    int k = 2;

    // 调用方法
    std::vector<int> topK = sol.topKFrequent(nums, k);

    // 输出结果
    std::cout << "Top " << k << " frequent elements are: ";
    for (int num : topK) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}