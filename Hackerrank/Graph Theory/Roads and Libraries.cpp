#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXR = 100001;
int cntroad = 0;
int cntlib = 0;

void traverse(vector<int> arr[MAXR], int visited[MAXR], int i){
    if(visited[i])
        return;
    visited[i] = 1;
    for(vector<int>::iterator itr = arr[i].begin(); itr != arr[i].end(); ++itr){
        if(visited[*itr])
            continue;
        ++cntroad;
        traverse(arr, visited, *itr);
    } 
}

int main() {
    int q;
    cin >> q;
    while(q--){
        cntroad = 0, cntlib = 0;
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;
        int visited[MAXR];
        vector<int> arr[MAXR];
        for(int i = 1; i <= n; ++i)
            visited[i] = 0;
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            arr[city_1].push_back(city_2);
            arr[city_2].push_back(city_1);
        }
        if(y > x){
            cout << (ll)((ll)n * (ll)x) << endl;
            continue;
        }
        for(int i = 1; i <= n; ++i){
            if(!visited[i])
                ++cntlib;
            traverse(arr, visited, i);
        }
        cout << (ll)((ll)cntroad * (ll)y + (ll)cntlib * (ll)x) << endl;
    }
    return 0;
}
