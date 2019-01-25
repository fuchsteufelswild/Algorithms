#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, m, n) for(int i = m; i < n; ++i)
#define repb(i, m, n) for(int i = m; i > n; --i)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define pb(x) push_back(x)

template<class T, class U> void setMax(T &a, const U &b) { if(a < b) a = b; }
template<class T, class U> void setMin(T &a, const U &b) { if(a > b) a = b; }
const int MAXN = 100001;
using namespace std;

int maxr[MAXN];
int minr[MAXN];

int maxCount[MAXN];
int minCount[MAXN];

int sought;

string last;

vector<int> adj[MAXN];
vector<int> c;

int traverseMin(int st, vector<int> *te, int last, bool check)
{
    int sum = 0;
    
    (*te).pb(st);
    
    for(auto x : adj[st])
    {
        if(x == last)
            continue;
        
        vector<int> *t = new vector<int>;
        int temp = traverseMin(x, t, st, check);
        if(temp < 0)
        {
            if(check)
                (*te).insert((*te).end(), (*t).begin(), (*t).end());
            sum += temp;
            minCount[st - 1] += minCount[x - 1];
        }
        delete t;
    }
    
    ++minCount[st - 1];
    
    return minr[st - 1] = sum + c[st - 1];
}

int traverseMax(int st, vector<int> *te, int last, bool check)
{
    int sum = 0;
    
    (*te).pb(st);
    
    for(auto x : adj[st])
    {
        if(x == last)
            continue;
        
        vector<int> *t = new vector<int>;
        int temp = traverseMax(x, t, st, check);
        if(temp > 0)
        {
            if(check)
                (*te).insert((*te).end(), (*t).begin(), (*t).end());
            sum += temp;
            maxCount[st - 1] += maxCount[x - 1];
        }
        delete t;
    }
    
    ++maxCount[st - 1];
    
    return maxr[st - 1] = sum + c[st - 1];
}

int main() 
{
    int n, result = 0, count;
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if(temp == 0)
            c.pb(1);
        else
            c.pb(-1);
    }
    
    vector<int> *o = new vector<int>;
    
    vector<int> *p = new vector<int>;
   
    for(int i = 0, x, y; i < n - 1; ++i){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    traverseMax(1, o, 0, false);
    
    (*o).erase((*o).begin(), (*o).end());
    
    traverseMin(1, p, 0, false);
    
    (*p).erase((*p).begin(), (*p).end());
    
    int numb = MAXN, type = MAXN;
    for(int i = 0; i < MAXN; ++i)
    {
        if(result < abs(minr[i]))
        {
            count = minCount[i];
            numb = i + 1;
            type = 1;
        }
        
        setMax(result, abs(minr[i]));
        
        if(result < maxr[i])
        {
            count = maxCount[i];
            numb = i + 1;
            type = 0;
        }
        
        setMax(result, maxr[i]);
    }
    
    cout << result << endl;
    
    cout << count << endl;
    
    if(type == 1)
    {
        vector<int> *l = new vector<int>;
        
        traverseMin(numb, l, 0, true);
        
        for(int i = 0; i < (*l).size(); ++i)
        {
            cout << (*l)[i] << " ";
        }
        
        delete l;
    }
    
    else if(type == 0)
    {
        vector<int> *v = new vector<int>;
        
        traverseMax(numb, v, 0, true);
        
        for(int i = 0; i < (*v).size(); ++i)
        {
            cout << (*v)[i] << " ";
        }
        delete v;
    }
    
    return 0;
}
