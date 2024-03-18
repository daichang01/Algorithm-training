
#include <iostream>

size_t strlen(const char* str) {
    const char* s;
    for (s = str; *s; ++s) {}
    return (s - str);
}

int main() {
    char str[] = "hello, world" ;
    std::cout << "len:" << strlen(str) << std::endl;
    return 0;
}