#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n, m, result = 0, a, b, max = 0;
    cin >> n >> m;
    long int k;
    long int *arr = new long int[n + 1];
    for(long int i = 0; i <= n; ++i){
        arr[i] = 0;
    }
    for(long int i = 0; i < m; ++i){
        cin >> a >> b >> k;
        arr[a] += k;
        if(b + 1 <= n){
            arr[b + 1] -= k;
        }
    }
    for(long int i = 0; i <= n; ++i){
        result += arr[i];
        if(result > max){
            max = result;
        }
    }
    cout << max << endl;
    return 0;
}
