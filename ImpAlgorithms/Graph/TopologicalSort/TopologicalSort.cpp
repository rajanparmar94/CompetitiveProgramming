/**
 * 
 *      By: Rajan Parmar
 *      Topological Sorting
 * 
 **/

#include <bits/stdc++.h>
 
#define N 100
 
using namespace std;
typedef long long int ll;

vector < int > G[N + 1];
bool visit[N + 1];
stack < int > TS;

void TopologicalSort(int id)    {
    
    visit[id] = true;
    
    for(int i = 0; i < G[id].size() ; i++)  {
        
        if(!visit[G[id][i]])    {
            TopologicalSort(G[id][i]);
        }
    }
    
    TS.push(id);
}

void PrintTopologicalSort(int n) {
    
    	
	for(int i = 0 ; i < n; i++)
	    visit[i] = false;
	    
	for(int i = 0 ; i < n ; i++){
	    
	    if(!visit[i])   {
	        TopologicalSort(i);
	    }
	}
	
	while(!TS.empty())  {
	    cout << TS.top() << " ";
	    TS.pop();
	}
}

int main() {
    
    int n, m, x, y, i;
    
    cin >> n;
    cin >> m;
    
    while(m--)  {
        
        cin >> x >> y;
        G[x].push_back(y);
    }
	
	PrintTopologicalSort(n);
	
	return 0;
}
