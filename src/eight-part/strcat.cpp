#include <iostream>

char* strcat(char* dest, const char* src) {
    char* saved = dest;
    while(*dest) {
        dest++ ;
    }
    while(*src) {
        *dest++ = *src++;
    }
    *dest = 0;
    return saved;
}

int main() {
    char dest[20] = "hello,";
    char src[] = "world";
    strcat(dest, src);
    std::cout << dest << std::endl;
    return 0;
}