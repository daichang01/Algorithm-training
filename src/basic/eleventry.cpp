# include <iostream>
# include <string>

char changeChar(char &a) {
    if (a >= 'a' && a <= 'z') a -= 32;
    return a;
}

int main () {
    int n;
    std::cin >> n;
    std::string s;
    std::getchar();   
    while (n--) {
        std::getline(std::cin, s);
        std::string result;
        // if (s[0] >= 'a' && s[0] <= 'z') {
        //     result += (s[0] - 32);
        // }
        result += changeChar(s[0]);
        for (int i = 1; i < s.size() - 1; i ++ ) {
            // if (s[i] == ' '  && s[i + 1] >= 'a' && s[i + 1] <= 'z') {
            //     result += (s[i+1] - 32);
            // }
            if (s[i] == ' ' && s[i + 1] != ' ') {
                result += changeChar(s[i + 1]);
            }
        }
        std::cout << result << std::endl;
    }
}