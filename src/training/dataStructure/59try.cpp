#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int diffindex = 1;
        int count = 1;
        int loop = n / 2;
        int mid = n / 2;
        int i, j;

        while (loop--)
        {
            i = startx;
            j = starty;

            // for (int j = starty; j < n - diffindex; j++)
            // {
            //     res[startx][j] = count++;
            // }
            // for (int i = startx; i < n - diffindex; i++)
            // {
            //     res[i][j] = count++;
            // }
            // for (; j > starty; j--)
            // {
            //     res[i][j] = count++;
            // }
            // for (; i > startx; i--)
            // {
            //     res[i][j] = count++;
            // }
            for (j = starty; j < n - diffindex; j++)
            {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - diffindex; i++)
            {
                res[i][j] = count++;
            }
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            diffindex += 1;
        }
        if (n % 2)
        {
            res[mid][mid] = count;
        }

        return res;
    }
};

int main()
{
    int n = 3;
    std::vector<std::vector<int>> res;
    Solution sol;
    res = sol.generateMatrix(n);
    // for (int i = 0; i< res.size(); i++) {
    //     for (int j = 0; j < res[i].size(); j++) {
    //         std::cout << res[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    for (const auto &row : res)
    {
        for (int elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}