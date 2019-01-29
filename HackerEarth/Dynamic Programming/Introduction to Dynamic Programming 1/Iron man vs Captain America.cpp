#include <iostream>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;
    
    while(t--)
    {
        int n;
        std::cin >> n;
        
        int ft[n];
        int st[n];
        
        for(int i = 0; i < n; ++i)
            scanf("%d ", ft + i);
        for(int i = 0; i < n; ++i)
            scanf("%d ", st + i);
            
        int fts[n - 1];
        int stf[n - 1];
        
        for(int i = 0; i < n - 1; ++i)
            scanf("%d ", fts + i);
        for(int i = 0; i < n - 1; ++i)
            scanf("%d ", stf + i);
            
        int memof[n];
        int memos[n];
        
        for(int i = 0; i < n; ++i)
            memof[i] = memos[i] = 100000000;
            
        memof[n - 1] = ft[n - 1];
        memos[n - 1] = st[n - 1];
        
        for(int j = n - 2; j >= 0; --j) // Either go through same path or jump to other path and continue
        {
            memof[j] = std::min(memof[j + 1], memos[j + 1] + fts[j]) + ft[j];
            memos[j] = std::min(memof[j + 1] + stf[j], memos[j + 1]) + st[j];
        }
        
        printf("%d\n", std::min(memof[0], memos[0]));
    }
    
    return 0;
}

    
