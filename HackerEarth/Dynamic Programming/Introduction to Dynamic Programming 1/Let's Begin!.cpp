#include <iostream>
#define MIN(x, y) ((x < y) ? x : y)

int memo[1000001];

int main()
{
    memo[0] = memo[1] = -1;
    memo[2] = memo[3] = memo[5] = memo[7] = 1;
    memo[4] = memo[6] = 2;
    memo[8] = 2;
    // Precompute
    for(int i = 9; i < 1000001; ++i) 
        memo[i] = MIN(MIN(MIN(memo[i - 7], memo[i - 5]), memo[i - 3]), memo[i - 2]) + 1;
    
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
        int x;
        std::cin >> x;
        printf("%d\n", memo[x]);
    }
    
    return 0;
}
