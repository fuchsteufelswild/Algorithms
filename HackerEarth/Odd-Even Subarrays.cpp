#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<int, long long> memo;
    int n;
    std::cin >> n;
    long long res = 0;
    
    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        int temp;
        std::cin >> temp;
        if(temp % 2)  // If odd assign 1
            vec[i] = 1;
        else          // If even assign -1
            vec[i] = -1;
    }
    memo.insert(std::pair<int, long long>(0, 1));
    
    for(int i = 0; i < n; ++i) // Find number of subarrays s.t sum = 0
    {
        if(i != 0)
            vec[i] += vec[i - 1]; // Sum till ith index
        if(memo.find(vec[i]) == memo.end()) // If that sum is not seen before
            memo.insert(std::pair<int, long long>(vec[i], 1));
        else // If same sum is seen again that means number of intervals between these indices have sum of 0.
        {
            res += memo[vec[i]];
            ++memo[vec[i]];
            
        }
    }
    
    std::cout << res << std::endl;
    
    return 0;
}
