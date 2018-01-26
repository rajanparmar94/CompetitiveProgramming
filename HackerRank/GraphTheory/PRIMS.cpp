/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/primsmstsub/problem
*
**/

#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
struct Pair{
    int x;
    int y;
    int cost;
    Pair(int a,int c,int b):x(a),y(c),cost(b){}
    
    bool operator<(const Pair& rhs) const
    {
        return cost < rhs.cost;
    }
};

int isConnected(vector < int > conn[] , int x , int y){
    queue <int> qu;
    qu.push(x);
    int visited[3001];
    memset(visited , 0 , sizeof(visited));
    while(!qu.empty()){
        int curr = qu.front();
        visited[curr] = 1;
        qu.pop();
        for(int n:conn[curr]){
            if(!visited[n])
            qu.push(n);
        }
    }
    return visited[y];
}

void Dijkstra(vector<Pair> edge , int start, int n){
    
  
    int sum = 0;
    int visited[3001];
    memset(visited, 0 , sizeof(visited));
    vector < int > conn[n+2];
    for(int i=0;i<edge.size();i++){
        //if(visited[edge[i].x]==0 || visited[edge[i].y]==0 )
        if(!isConnected(conn ,edge[i].x , edge[i].y ))
        {
            
            sum += edge[i].cost;
            conn[edge[i].x].push_back(edge[i].y);
            conn[edge[i].y].push_back(edge[i].x);
           // visited[edge[i].x] = visited[edge[i].y] = 1;
        }
            
    }
    cout<<sum;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,m;
    
        cin>>n>>m;
        vector <Pair> edge;
        while(m--){
            int x,y,cost;
            cin >> x >> y >>cost;
            edge.push_back(Pair(x,y,cost));
            
        }
        int start;
        cin >> start;
        sort(edge.begin(),edge.end());
        Dijkstra(edge,start,n);
        cout << endl;
    
    return 0;
}

