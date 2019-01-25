#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define forn(i, n) for(int i = 0; i < n; ++i)
#define repeat(i, n) for(int i = 1; i <= n; ++i)
using namespace std;


int main() {
    int t;
    cin >> t;
    
    forn(i, t){
        int n;
        cin >> n;
        int arr[n + 1];
        repeat(j, n)
            cin >> arr[j];
        
        repeat(j, n){
            if(arr[j] == j){
                continue;
            }
            repeat(k, n){
                if(arr[k] == j){
                    while(arr[j] != j){
                        int flag = 0;
                    if(k >= 3){
                        if(arr[k - 1] > arr[k] && arr[k - 2] > arr[k]){
                            flag = 1;
                            int temp = arr[k];
                            arr[k] = arr[k - 2];
                            arr[k - 2] = temp;
                            temp = arr[k];
                            arr[k] = arr[k - 1];
                            arr[k - 1] = temp;
                        }
                        else if(arr[k - 1] > arr[k] && k + 1 <= n){
                            flag = 1;
                            int temp = arr[k];
                            arr[k] = arr[k - 1];
                            arr[k - 1] = temp;
                            temp = arr[k];
                            arr[k] = arr[k + 1];
                            arr[k + 1] = temp;
                        }
                        k -= 2;
                    }
                    else if(k >= 2){
                        if(arr[k - 1] > arr[k] && k + 1 <= n){
                            flag = 1;
                            int temp = arr[k];
                            arr[k] = arr[k - 1];
                            arr[k - 1] = temp;
                            temp = arr[k];
                            arr[k] = arr[k + 1];
                            arr[k + 1] = temp;
                            k -= 1;
                    }
                }
                        if(flag == 0){
                            break;
                        }
                }
                    break;
                }
        }
        
        }
        int flag = 0;
        repeat(j, n){
            if(j == 1){
                continue;
            }
            if(arr[j] < arr[j - 1]){
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
