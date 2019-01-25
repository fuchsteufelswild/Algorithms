#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define repeat(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll arr[n];
    int memo[k + 1];
    int count[k];
    if(k == 1){
        cout << 1 << endl;
        return 0;
    }
    repeat(i, k + 1){
        memo[i] = 0;
    }
    repeat(i, n){
        cin >> arr[i];
        ++memo[arr[i] % k];
    }
    if(memo[0] != 0){
        memo[0] = 1;
    }
    if(k % 2 == 0 && memo[k / 2] != 0){
        memo[k / 2] = 1;
    }
    repeat(i, k / 2 + 1){
        count[i] = memo[i] > memo[k - i] ? memo[i] : memo[k - i];
    }
    int max = 0;
    repeat(i, k / 2 + 1){
        max += count[i];
    }
    cout << max << endl;
    return 0;
}
