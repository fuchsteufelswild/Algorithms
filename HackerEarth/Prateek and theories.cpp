#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>

int main()
{
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
        int max = 0;
        
        std::multimap<int, int> arr;
        std::priority_queue<int, std::vector<int>, std::greater<int> > reverse;
        std::vector<int> res = {0};
        
        int n;
        std::cin >> n;
        
        int a, b;
        for(int j = 0; j < n; ++j)
        {
            std::cin >> a >> b;
            arr.insert(std::pair<int, int>(a, b));
        }
        
        for(std::multimap<int, int>::iterator itr = arr.begin(); itr != arr.end(); ++itr)
        {
            int temp = res.back();
            while(!reverse.empty() && reverse.top() <= (*itr).first) // While start time of the new entry
            {                                                        // is greater than old finish times
                --temp;
                reverse.pop();
            }
            
            ++temp;
            reverse.push((*itr).second); // Store finish times
            
            if(temp > max)
                max = temp;
            res.push_back(temp);
        }
        
        std::cout << max << std::endl;
    }
}
