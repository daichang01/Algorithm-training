#include <vector>
#include <iostream>

int main () {
    std::vector<int> nums;
    int n,num;
    std::cin >> n;
    while (n--) {
        std::cin >> num;
        nums.push_back(num);
    }
    for (int i = nums.size() -1; i >= 0; i--) {
        std::cout << nums[i] ;
        if(i > 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i <= nums.size() - 1; i += 2) {
        std::cout << nums[i];
        if (i < nums.size() ) {
            std::cout << " ";
        }
    }
}