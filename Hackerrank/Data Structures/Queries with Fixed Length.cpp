#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)
using namespace std;

template<class T> void setMax(T &a, const T &b){ if(a < b) a = b; }

template<class T> void setMin(T &a, const T &b){ if(a > b) a = b; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    repeat(i, n)
        cin >> arr[i];
    int lowest = 1000000;
    repeat(i, n)
        setMin(lowest, arr[i]);
    while(q--){
        int w, min = 1000000, max = 0, pos = 0;
        cin >> w;
        if(w == 1){
            cout << lowest << endl;
            continue;
        }
        repeat(i, w)
            setMax(max, arr[i]);
        setMin(min, max);
        for(int i = w; i < n; ++i){
            if(min == lowest)
                break;
            if(max == arr[pos]){
                max = 0;
                for(int j = pos + 1; j <= i; ++j)
                    setMax(max, arr[j]);
            }
            setMax(max, arr[i]);
            setMin(min, max);
            ++pos;
        }
        cout << min << endl;
    }
    return 0;
}
