#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    priority_queue<int, vector<int>, less<int> > h1;
    priority_queue<int, vector<int>, greater<int> > h2;
    int q;
    cin >> q;
    while(q--){
        int numb;
        cin >> numb;
        if(!h1.size() && !h2.size()){
            h1.push(numb);
            printf("%.1f\n", (float)numb);
            continue;
        }
        if(numb > h1.top()){
            if(h2.size() - h1.size() == 1){
                if(numb < h2.top())
                     h1.push(numb);
                else{
                    int temp = h2.top();
                    h2.pop();
                    h2.push(numb);
                    h1.push(temp);
                }
                
            }
            else
                h2.push(numb);
        }
        else{
            if(h1.size() == h2.size()){
                int temp;
                temp = h1.top();
                h1.pop();
                h1.push(numb);
                h2.push(temp);
            }
            else{
                if(h2.size())
                    h1.push(numb);
                else{
                    int temp = h1.top();
                    h1.pop();
                    h1.push(numb);
                    h2.push(temp);
                }
            }
        }
        if(h1.size() == h2.size()){
            printf("%.1f\n", (float)(h1.top() + h2.top()) / 2);
        }
        else{
            printf("%.1f\n", (float)h2.top());
        }
    }
    return 0;
}
