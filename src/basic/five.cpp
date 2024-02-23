#include <iostream>
int main()
{
    int N, n, num;
    std::cin >> N;
    std::cout << std::endl;
    while (N--)
    {
        int sum = 0;
        std::cin >> n;
        while (n--)
        {

            std::cin >> num;
            sum += num;
        }
        std::cout << sum << std::endl;
        if (n != 0)
        {
            std::cout << std::endl;
        }
    }
    return 0;
}