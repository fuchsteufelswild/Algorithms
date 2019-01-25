#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m, max = 0, temp;
        long long int acc = 0;
        int x;
        cin >> n >> m >> x;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        vector<int> b(m);
        for(int b_i = 0; b_i < m; b_i++){
           cin >> b[b_i];
        }
        int i, j;
        for(i = 0; i < n; ++i){
            if(acc + a[i] <= x){
                acc += a[i];
            }
            else{
                break;
            }
        }
        //cout << i << acc << endl;
        temp = 0;
        while(1){
            for(j = temp; j < m; ++j){
                if(acc + b[j] <= x){
                    acc += b[j];
                }
                else{
                    break;
                }
            }
            if(i + j > max){
                max = i + j;
            }
            
            --i;
            if(i < 0){
                break;
            }
            acc -= a[i];
            temp = j;
        }
        cout << max << endl;
    }
    return 0;
}
