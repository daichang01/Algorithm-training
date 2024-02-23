#include<iostream>
using namespace std;
int main() {
  int n;
  while(cin >> n) {
    if (n == 0) break;
    // 定义一个变量sum, 用于每次累加
       int sum = 0;
    // 定义一个变量a, 用于接收每次输入的数值
    int a;
    // 操作执行n次
    while(n--) {
      // 输入一个数字a
      cin >> a;
      // 将输入的数字a累加到sum上，并赋值给sum
      sum = sum + a;
    }
    // 输入完n个数字之后，输出sum
    cout << sum << endl;
  }
}