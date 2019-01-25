#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    int sum = 0;
    int count = 1;
    int index = 0;
    int arr[n];
    for(int i = 0; i < n; ++i){
        int fuel, dis;
        cin >> fuel >> dis;
        arr[i] = fuel - dis;
    }
    for(int i = 0; i < 2 * n; ++i){
        if(count == n){
            break;
        }
        if(i > n - 1){
            sum += arr[i - n];
        }
        else{
            sum += arr[i];
        }
        if(sum >= 0){
            ++count;
        }
        else{
            sum = 0;
            count = 1;
            index = i + 1;
        }
    }
    cout << index << endl;
    return 0;
}
