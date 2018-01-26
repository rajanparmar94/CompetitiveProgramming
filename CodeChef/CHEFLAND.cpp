/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/problems/CHEFLAND/
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;
#define pb push_back
#define mp make_pair
#define N 500500
int n;
vector<vector<int> > graph(N);
vector<int> low(N), desc(N);
int timer = 0;
vector<char> used(N);
 
set<pii> bridge;
 
void dfs(int v, int p)
{
    used[v] = true;
    low[v] = timer++;
    desc[v] = low[v];
    int pp = 0;
    for (int to : graph[v]) {
        if (to == p) {
            ++pp;
            continue;
        }
        if (used[to]) {
            desc[v] = min(desc[v], low[to]);
        } else {
            dfs(to, v);
            desc[v] = min(desc[v], desc[to]);
            if (desc[to] > low[v]) {
                bridge.insert(mp(min(v, to), max(v, to)));
            }
        }
    }
    if (pp >= 2) {
        desc[v] = min(desc[v], desc[p]);
    }
}
 
vector<vector<int> > valid(N);
vector<int> path(N);
int cnt = 0;
 
void dfs1(int v)
{
    path[v] = cnt;
    for(int to:valid[v]){
        if(path[to] == -1)
        dfs1(to);
    }
}
 
vector<vector<int> > flow(N);
 
int main()
{
 
    
    int m;
    cin >> n >> m;
   
 
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
 
    low.resize(n), desc.resize(n);
    used.assign(n, false);
    dfs(0, -1);
 
    valid.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int to : graph[i]) {
            if (!bridge.count(mp(min(i, to), max(i, to)))) {
                valid[i].pb(to);
            }
        }
    }
    
    path.assign(N, -1);
    for (int i = 0; i < n ; i++) {
        if(path[i]==-1){
            dfs1(i);
        }
        ++cnt;
    }
    
    flow.resize(cnt);
    for( auto &it:bridge ) {
        int u = it.first;
        int v = it.second;
        flow[path[u]].pb(path[v]);
        flow[path[v]].pb(path[u]);
    }
    
    for(int i = 0 ; i < cnt ; i++){
        if(flow[i].size() > 2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
 
} 