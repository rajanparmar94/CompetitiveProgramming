/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/JULY16/problems/CHEFARC/
*
**/

#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>
#include <vector>
using namespace std;
#define N 100
#define fi first
#define se second
 
int grid[N+1][N+1];
 
void bfs(long int ar[N+1][N+1] , int k , int n, int m , int type){
    int visit[N+1][N+1] ;
    int i, j;
    memset(visit , 0 , sizeof(visit));
    queue < pair < int , int > > q; 
    if(type==1){
        q.push(make_pair(0,0));
        visit[0][0] = 1;
    }
    else{
        q.push(make_pair(0,m-1));
        visit[0][m-1] = 1;
    }
    while(!q.empty()){
        pair < int, int > cur;
        cur = q.front();
        q.pop();
        
        for(i = cur.fi ; cur.fi - i <= k && i >= 0; i-- ){
            for( j = cur.se ; ( cur.fi - i +cur.se - j) <= k && j >= 0; j-- ){
                if(visit[i][j]==0 && grid[i][j] == 0){
                    visit[i][j] = 1;
                    ar[i][j] = ar[cur.fi][cur.se] + 1;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        for(i = cur.fi ; cur.fi - i <= k && i >= 0; i-- ){
            for( j = cur.se ; ( cur.fi - i +j - cur.se) <= k && j < m; j++ ){
                if(visit[i][j]==0 && grid[i][j] == 0){
                    visit[i][j] = 1;
                    ar[i][j] = ar[cur.fi][cur.se] + 1;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        for(i = cur.fi ; i <= cur.fi + k && i < n; i++ ){
            for( j = cur.se ; (i - cur.fi +j - cur.se) <= k && j < m; j++ ){
                if(visit[i][j]==0 && grid[i][j] == 0){
                    visit[i][j] = 1;
                    ar[i][j] = ar[cur.fi][cur.se] + 1;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        for(i = cur.fi ; i - cur.fi <= k && i  < n; i++ ){
            for( j = cur.se ; ( i - cur.fi +cur.se - j) <= k && j >= 0; j-- ){
                if(visit[i][j]==0 && grid[i][j] == 0){
                    visit[i][j] = 1;
                    ar[i][j] = ar[cur.fi][cur.se] + 1;
                    q.push(make_pair(i,j));
                }
            }
        }
    }
}
int main() {
	// your code goes here
	int t, i, j, n, m, k1, k2;
	long int sol = 0;
	long int r1[N+1][N+1] , r2[N+1][N+1];
	cin >> t;
	
	while(t--){
	    sol = 100001;
	    memset(r1 , 0 , sizeof(r1));
	    memset(r2 , 0 , sizeof(r2));
	    
	    cin >> n >> m >> k1 >> k2;
	    
	    for(i = 0 ; i < n ; i++)
	     for(j = 0 ; j < m ; j++)
	        cin >> grid[i][j];
	          
	    bfs(r1, k1, n, m, 1);
	    bfs(r2, k2, n, m, 2);
	    
	    r2[0][m-1] = 1;
	    r1[0][0] = 1;
	    
	    for(i = 0 ; i < n ; i++){
	        for(j = 0 ; j < m ; j++){
	        //    cout << r2[i][j] <<" ";
	            if(r1[i][j]!=0 && r2[i][j]!=0){
	                
	                sol = min(sol , max( r1[i][j] , r2[i][j]));
	            }
	        }
	 //   cout << endl;
	    }
	    if(m==1){
	        cout << "0\n";
	    }
	    else{
	    if(sol==100001)
	        cout << "-1\n";
	    else    
	        cout << sol << "\n";
	    }
	}
	
	return 0;
}    