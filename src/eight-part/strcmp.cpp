#include <iostream>
int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1 ++ ;
        str2 ++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int main() {
    char str1[] = "hello" ;
    char str2[] = "world";
    char str3[] = "hello";

    std::cout << strcmp(str1, str2) << std::endl;
    std::cout << strcmp(str2, str3) << std::endl;
    std::cout << strcmp(str1, str3) << std::endl;
    return 0;

}