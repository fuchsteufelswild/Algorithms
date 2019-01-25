#include <iostream>

typedef long long ll;
using namespace std;
const int MAXR = 100001;

ll prem[MAXR];
ll premn[MAXR];

void calc(int len, int c, int acc){
    if(!len)
        return;
    if(len == 1){
        cout << len + acc << " ";
        return;
    }
    c -= len - 1;
    if(premn[len - 1] <= c && prem[len - 1] >= c){
        cout << len + acc << " ";
        calc(len - 1, c, acc);
        return;
    }
    int st = 0, end = (len - 1) / 2 + 1;
    while(end > st + 1){
        int pivot = (st + end) / 2;
        if(premn[pivot] + premn[len - 1 - pivot] <= c)
            end = pivot;
        else
            st = pivot;
    }
    cout << end + acc + 1 << " ";
    calc(end, premn[end], acc);
    calc(len - 1 - end, c - premn[end], acc + end + 1);
}

ll pre(int numb){
    if(premn[numb])
        return premn[numb];
    if(numb == 1 || numb == 0)
        return 0;
    if(numb % 2 == 0){
        premn[numb] += pre(numb / 2);
        premn[numb] += numb - 1 + pre((numb - 1) / 2);
    }
    else
        premn[numb] += numb - 1 + 2 * pre(numb / 2);
    return premn[numb];
}

int main(){
    premn[1] = 0, prem[1] = 0;
    for(int i = 2; i < MAXR; ++i){
        pre(i);
        prem[i] = 1ll * i * (i - 1) / 2;
    }
    int q;
    cin >> q;
    while(q--){
        int len, c;
        cin >> len >> c;
        if(c > prem[len] || c < premn[len]){
            cout << - 1 << endl;
            continue;
        }
        calc(len, c, 0);
        cout << endl;
    }
    return 0;
}
