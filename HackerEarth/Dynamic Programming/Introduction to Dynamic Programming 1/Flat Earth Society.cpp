#include <iostream>
#include <cmath>

const int maxN = 100002;

int memo[maxN];
int memor[maxN];
int counts[maxN];

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < maxN; ++j)
            counts[j] = memo[j] = memor[j] = 0;
        int n, l, r;
        std::cin >> n >> l >> r;
        
        // Calculate count of every number
        for (int j = 0; j < n; ++j)
        {
            int temp;
            std::cin >> temp;
            ++counts[temp];
        }

        int max = 0;
        int j = 0;
        
        // Calculate maximum points till every index with only left activated
        while (j < l + 1)
        {
            memo[j] = std::max(memo[j - 1], counts[j] * j);
            ++j;
        }
        
        for (; j < maxN; ++j)
            memo[j] = std::max(memo[j - 1], counts[j] * j + memo[j - (l + 1)]);
        //
        
        j = 100000;
        while (j + r >= 100000)
        {
            memor[j] = std::max(memor[j + 1], counts[j] * j);
            --j;
        }

        // Calculate maximum points till every index with only right activated
        // At the same time calculate max outcome for every index:
        // j * count of j
        // + (calculated best at (j - l - 1)th index for left activated)
        // + (calculated best at (j + r + 1)th index for right activated)
        for (; j >= 0; --j)
        {
            int temp = 0;
            if (j >= l + 1)
                temp = memo[j - l - 1];
            temp += memor[j + r + 1] + counts[j] * j;
            max = max > temp ? max : temp;
            memor[j] = std::max(memor[j + 1], counts[j] * j + memor[j + r + 1]);
        }

        printf("%d\n", max);
    }
}
