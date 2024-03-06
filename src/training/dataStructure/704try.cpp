#include <iostream>
#include <vector>
int search (std::vector<int>& nums, int target) {
     int i = nums.size() / 2;
     while (nums[i] != target) {
        if (nums[i] < target) {
            if (i == (i + nums.size()) / 2) return -1;
            i = (i + nums.size()) / 2;
        }
        else if (nums[i] > target) {
            if (i == (i/2)) return -1;
            i = i / 2;
        }
     }
     return i;
}


int main () {
    std::vector<int> myVector = {-1, 0, 3, 5, 9, 12};
    int result = search(myVector, 4);
    std::cout << result << std::endl;
}