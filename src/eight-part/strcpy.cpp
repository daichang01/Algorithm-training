#include <iostream>

char* strcpy(char* dest, const char* src) {
    char* saved = dest;
    while(*src) {
        *dest++ = *src++;
    }
    *dest = 0;
    return saved;
}

int main() {
    const char* src = "hello world";
    char dest[20] ; // 确保有足够空间存放src字符串以及'\0'

    strcpy(dest, src);
    std::cout << "copied string:" << dest << std::endl;
    return 0;
}