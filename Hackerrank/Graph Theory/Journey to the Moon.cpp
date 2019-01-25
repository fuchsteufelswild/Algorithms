#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

int main(){
    int n, p, all;
    cin >> n >> p;
    all = n;
    ll result = 0;
    vector<int> vec;
    int arr[n];
    int memo[n];
    rep(i, n){
        arr[i] = - 1;
        memo[i] = - 1;
    }
    while(p--){
        int x, y, count = 0;
        cin >> x >> y;
        int a1 = x, a2 = y;
        int ar[2 * n];
        if(memo[x] >= 0)
            x = memo[x];
        if(memo[y] >= 0)
            y = memo[y];
        while(arr[x] >= 0){
            if(memo[x] >= 0){
                ar[count] = x;
                ++count;
                x = memo[x];
                continue;
            }
            ar[count] = x;
            ++count;
            x = arr[x];
        }
        while(arr[y] >= 0){
            if(memo[y] >= 0){
                ar[count] = y;
                ++count;
                y = memo[y];
                continue;
            }
            ar[count] = y;
            ++count;
            y = arr[y];
        }
        if(x == y)
            continue;
        if(arr[x] <= arr[y]){
            int temp = arr[y];
            arr[y] = x;
            arr[x] += temp;
            for(int i = 0; i < count; ++i)
                memo[ar[i]] = x;
        }
        else{
            int temp = arr[x];
            arr[x] = y;
            arr[y] += temp;
            for(int i = 0; i < count; ++i)
                memo[ar[i]] = y;
        }
    }
    rep(i, n){
        if(arr[i] < 0)
            vec.push_back(- 1 * arr[i]);
    }
    for(auto x:vec){
        all -= x;
        result += (ll)x * (ll)all;
    }
    cout << result << endl;
    return 0;
}
