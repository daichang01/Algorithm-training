# include <iostream>
# include <string>

void swap (char &a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    std::cin >> n;
    std::getchar();
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        for (int i = 0; i < s.size(); i += 2) {
            swap(s[i], s[i+1]);
        }
        std::cout << s << std::endl;
    }
}