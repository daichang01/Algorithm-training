#include <iostream>
#include <vector>

int main () {
    int n,num,epochs;
    std::cin >> n;
    std::vector<int> nums;
    while (n--) {
        std::cin >> num;
        nums.push_back(num);
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    int avg = sum / nums.size();
    int sumMove = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > avg) sumMove +=  nums[i] - avg;
    }
    std::cout << sumMove << std::endl;
    return 0;
}