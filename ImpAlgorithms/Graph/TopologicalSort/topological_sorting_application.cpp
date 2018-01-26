/**
*
*	By : Rajan Parmar
*	Qus: https://www.hackerrank.com/contests/101hack40/challenges/next-topological-sorting
*
**/


#include <bits/stdc++.h>

using namespace std;
#define N 100000
#define MOD 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long int ll;
typedef pair < int, int > pii;
typedef pair < ll , ll > pll;

vector < int > G[N + 1];
set < int > st;

int main() {
    
    int n, m, i, j, x, y, mx, idx;
    int inDeg[N + 1];
    int sol[N + 1];
    
    cin >> n >> m ;
    
    memset(inDeg, 0, sizeof(inDeg));
    
    while(m--)  {
        
        cin >> x >> y;
        G[x].pb(y);
        inDeg[y]++;
    }
    
    for(i = 1 ; i <= n ; i++)   {
        
        cin >> sol[i];
    }
    
    for(i = 1 ; i <= n ; i++)   {
        
        if(inDeg[i] == 0){
            st.insert(i);
        }
    }
    
    mx = 0;
    
    for(i = 1 ; i <= n ; i++)   {
        
        auto it = st.lower_bound(sol[i] + 1);
        if(it != st.end())  {
            mx = i;
        }
        
        x = sol[i];
        
        it = st.find(x);
        if(it != st.end())
            st.erase(it);
            
        for(int g:G[x])    {
            
            inDeg[g]--;
            if(inDeg[g] == 0)
                st.insert(g);
        }
    }
    
    if(mx == 0) {
        cout << "-1\n";
        return 0;
    }
    
    idx = 1;
    st.clear();
    memset(inDeg, 0, sizeof(inDeg));
    
    for(i = 1 ; i <= n ; i++)   {
        
        for(int g:G[i])    
            inDeg[g]++;
    }
    
    for(i = 1 ; i <= n ; i++)   {
        

        if(inDeg[i] == 0){
            st.insert(i);
        }
    }
    
    for(i = 1 ; i <= n ; i++)   {
        
        if(i == mx)  {
            
            auto it = st.lower_bound(sol[i] + 1);
            sol[i] = *it;
            
        }
        if(i > mx)  {
            
            sol[i] = *st.begin();
           
        }
        x = sol[i];
        
        auto it = st.find(x);
        if(it != st.end()){
            st.erase(it);
        }
        
        for(auto g:G[x])    {
            
            inDeg[g]--;
            if(inDeg[g] == 0)
                st.insert(g);
        }
        
    }
    
    for(i = 1 ; i <= n ; i++)
        cout << sol[i] << " ";
    
	return 0;
}
