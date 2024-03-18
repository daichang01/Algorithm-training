// #include <iostream>
// #include <map>
// #include <string>

// int main() {
//     std::map<int, std::string> employeeID = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
//     std::cout << "Employee 2 is " << employeeID[2] << ".\n";
// }

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> grades;
    grades["Alice"] = 90;
    grades["Bob"] = 85;

    // 查询Alice的成绩
    cout << "Alice's grade: " << grades["Alice"] << endl;
}
