/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/coin-change/problem
*
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll ar[251],n,m,ans;
ll dp[51][251];
void solve(){
    
    memset(dp,0,sizeof(dp));
    for(ll i = 0 ; i<=m ; i++)
        dp[i][0] = 1;
    
    for(ll i = 1 ; i<=m ; i++){
        for(ll j = 1 ; j<=n ; j++){
            if(ar[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-ar[i-1]];
        }
    }
    cout<<dp[m][n]<<"\n";
}
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    ans = 0;
    for(ll i =0 ; i<m ; i++){
        cin>>ar[i];
    }
    solve();
   
    return 0;
}
