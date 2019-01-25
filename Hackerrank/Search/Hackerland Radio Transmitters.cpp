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
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

template<class T> void setMax(T &a, const T &b) { if(a < b) a = b; }

template<class T> void setMin(T &a, const T &b) { if(a > b) a = b; }

using namespace std;

int main(){
    int n, k, far = 0, count = 0, max = 100001;
    int near = max, arr[max];
    repeat(i, max)
        arr[i] = 0;
    cin >> n >> k;
    repeat(i, n){
        int temp;
        cin >> temp;
        setMin(near, temp);
        setMax(far, temp);
        arr[temp] = 1;
    }
    int j;
    for(int i = near; i <= far; ++i){
        if(arr[i] == 1){
            ++count;
            j = i;
            if(i + k <= far){
                for(j = i + k; j >= i; --j){
                    if(arr[j] == 1)
                        break;
                }
            }
            i = j + k; 
        }
    }
    cout << count << endl;
    return 0;
}
