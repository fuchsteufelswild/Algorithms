#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        
        int s[n];
        short memo[m + 1];
        for(int i = 0; i < n; ++i)
            scanf("%d ", s + i);
        
        for(int i = 0; i < m + 1; ++i) // memo[i] = 1 if wins starting player else memo[i] = 0
            memo[i] = 0;
        
        for(int i = 0; i < n; ++i) // s[i] directly wins
            memo[s[i]] = 1;
        
        for(int i = 1; i < m + 1; ++i)
        {
            if(memo[i])
                continue;
            short temp = 0;
            for(int j = 0; j < n; ++j)
            {
                if(s[j] > i)
                    continue;
                
                if(!memo[i - s[j]]) // If next player loses after this move
                {
                    temp = 1;
                    break;
                }
            }
            
            memo[i] = temp;
        }

        if(memo[m])
            printf("Little Deepu\n");
        else
            printf("Kate\n");
        
    }
    
    return 0;
}
