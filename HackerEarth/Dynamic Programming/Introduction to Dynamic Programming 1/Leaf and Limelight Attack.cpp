#include <iostream>
#include <vector>

std::vector<long long> memo(10000001);

const long mod = 1000000009;
int main()
{
    memo[1] = 1;
    memo[2] = 10;
    
    // Precompute
    // There is a pattern memo[i] = memo[i - 2] + 4i^2 - 6i + 6
    for(long i = 3; i < 10000001; ++i)
        memo[i] = (memo[i - 2] + ((static_cast<long long int>((4 * i * i)) - static_cast<long long>((6 * i)) + 6) % mod)) % mod;

    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
        long n;
        std::cin >> n;
        printf("%d\n", memo[n]);
    }
    
}
    
