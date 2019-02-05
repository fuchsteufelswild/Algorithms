#include <iostream>

bool memo[1000001];

int main()
{
    int max = 0;
    int n;
    std::cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        if(arr[i] > max)
            max = arr[i];
        memo[arr[i]] = true;
    }
    
    memo[0] = true;
    for(int i = 1; i < 1000001; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(arr[j] > i)
                continue;
            if(memo[i - arr[j]])
            {
                memo[i] = true;
                break;
            }
        }
    }
    
    for(int i = max + 1; i < 1000001; ++i)
        if(!memo[i])
        {
            std::cout << i;
            return 0;
        }
    
    std::cout << "Fake Offer!";
}
