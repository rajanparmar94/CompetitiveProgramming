/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/dijkstrashortreach/problem
*
**/

#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair{
    int vertex;
    int cost;
    Pair(int a,int b):vertex(a),cost(b){}
    
    bool operator<(const Pair& rhs) const
    {
        return cost > rhs.cost;
    }
};

void Dijkstra(vector<Pair> node[] , int start, int n){
    
    priority_queue < Pair > pq;
    int dist[3001];
    int visited[3001];
    for(int i=1;i<=n;i++){
        visited[i] = 0;
        if(i==start)
            dist[i] = 0;
        else
            dist[i] = INT_MAX;
    }
    pq.push(Pair(start,0));
    visited[start] = 1;
    while(!pq.empty()){
        Pair pr = pq.top();
        visited[pr.vertex] = 1;
        pq.pop();
        for(Pair p:node[pr.vertex]){
            if(dist[p.vertex] > dist[pr.vertex] + p.cost){
                dist[p.vertex] = dist[pr.vertex] + p.cost;
                if(visited[p.vertex]==0)
                    pq.push(Pair(p.vertex ,dist[p.vertex] ));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=start){
            if(!visited[i])
                dist[i]=-1;
                cout<<dist[i]<<" ";
            
        }
            
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,m;
    cin >> t;
    while(t--){
        cin>>n>>m;
        vector <Pair> node[n+2];
        while(m--){
            int x,y,cost;
            cin >> x >> y >>cost;
            node[x].push_back(Pair(y,cost));
            node[y].push_back(Pair(x,cost));
        }
        int start;
        cin >> start;
        Dijkstra(node,start,n);
        cout << endl;
    }
    return 0;
}
