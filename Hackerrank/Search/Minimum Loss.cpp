#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

using namespace std;

template<class T> void setMin(T &a, const T &b){ if(a > b) a = b; }

int main() {
    int n;
    long long min = pow(10, 18);
    cin >> n;
    map<long long, int> mapp;
    vector<long long> arr(n);
    repeat(i, n){
        cin >> arr[i];
        mapp[arr[i]] = i;
    }
    sort(arr.begin(), arr.end(), greater<long long>());
    repeat(i, n - 1){
        if(mapp[arr[i]] < mapp[arr[i + 1]])
            setMin(min, (long long)arr[i] - (long long)arr[i + 1]);
    }
    cout << min << endl;
    return 0;
}
