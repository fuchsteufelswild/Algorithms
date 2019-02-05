#include <iostream>

const int mod = 1000000007;
int memo[101][10001];
long long sums[101];
long arr[101];

int main()
{
    // Precompute for all K and X
    for(int i = 1; i < 101; ++i) // Calculate sum values for K = 100
    {
        arr[i] = sums[i - 1] + 1;
        sums[i] = sums[i - 1] * 2 + 1;
        sums[i] %= mod;
    }
    
    for(int i = 1; i < 101; ++i)     // Fill every row [1..K] through columns [1..K]
        for(int j = 1; j <= i; ++j)  // with val of arr
            memo[i][j] = arr[j];
            
    for(int i = 1; i < 101; ++i)
    {
        long long int temp = sums[i];
        int l = 1;
        for(int j = i + 1; j < 10001; ++j)  // Substract the val at start and add the last calculated val
        {                                   // to the sum value that is to be assigned to memo[i][j]
            memo[i][j] = temp;
            if(memo[i][l] > temp)    // If temp is smaller than the memo value at the index l
            {                        // ignore the action and add previous K - 1 values to temp
                int a = i - 1;
                int b = 1;
                while(a--)
                {
                    temp += memo[i][j - b];
                    ++b;
                }
            }
            else
                temp += memo[i][j] - memo[i][l];
            temp %= mod;
            ++l;
        }
    }
    //-----------------------------------------------------------//
    
    int t;
    std::cin >> t;
    
    while(t--)
    {
        int x, k;
        scanf("%d %d", &x, &k);
 
        printf("%d\n", memo[k][x]);
    }
}
