#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define repeat(i, n) for(int i = 1; i <= n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    repeat(i, n)
        arr[i] = - 1;
    while(q--){
        char op;
        cin >> op;
        if(op == 'M'){
            int i, j;
            cin >> i >> j;
            while(1){
                if(arr[i] < 0)
                    break;
                i = arr[i];
            }
            while(1){
                if(arr[j] < 0)
                    break;
                j = arr[j];
            }
            if(i == j)
                continue;
            if(arr[i] < arr[j]){
                int temp = arr[j];
                arr[j] = i;
                arr[i] += temp;
            }
            else{
                int temp = arr[i];
                arr[i] = j;
                arr[j] += temp;
            }
        }
        else if(op == 'Q'){
            int i;
            cin >> i;
            while(1){
                if(arr[i] < 0){
                    cout << -1 * (arr[i]) << endl;
                    break;
                }
                i = arr[i];
            }
        }
    }
    return 0;
}
