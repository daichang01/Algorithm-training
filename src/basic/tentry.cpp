# include <iostream> 
# include <string>
# include <cstdio>


int main() {
  std::string s; // 定义空字符串
  
  while (std::getline(std::cin, s)) {
    int score = 0;
    int count = 0;
    float sum = 0;
    int flag = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            score = 4;
            sum += score;
            count ++;
            continue;
        }
        if (s[i] == 'B') {
            score = 3;
            sum += score;
            count ++;
            continue;

        }
        if (s[i] == 'C') {
            score = 2;
            sum += score;
            count ++;
            continue;

        }
        if (s[i] == 'D') {
            score = 1;
            sum += score;
            count ++;
            continue;

        }
        if (s[i] == 'F') {
            score = 0;
            sum += score;
            count ++;
            continue;

        }
        if (s[i] == ' '){
            continue;
        }
        else {
            flag = 0;
            std::cout << "Unknown" << std::endl;
            break;
        }
        
    }
    if (flag) {
        printf("%.2f\n", sum / count);
    }
   
    // std::cout << s << std::endl;
  }
 
  return 0;
}  