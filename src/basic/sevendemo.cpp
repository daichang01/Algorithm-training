# include<iostream>
# include <vector>

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        std::vector<int> nums = std::vector<int>(n, 0);
        int sum = 0;

        for(int i = 0;i < n; i++) {
            std::cin >> nums[i];
            sum += nums[i];
        }
        int avg = sum / n;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] - avg ) > 0) {
                result += (nums[i] - avg);
            }
        }
        std::cout << result << std::endl;
        std::endl;
    }
}