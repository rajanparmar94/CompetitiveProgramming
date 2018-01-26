/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/unbounded-knapsack/problem
*
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll dp[2002][2002];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, k, i, j;
    int val[2002];
    
    for(i = 0; i <2002; i++){
        dp[0][i] = dp[i][0] = 0;
    }
        
    cin >> t;
    while(t--){
        cin >> n >> k;
        
        for(i = 1; i <= n; i++) {
            cin >> val[i];
        }
        for(i = 1; i <= k ; i++){
            for(j = 1; j <= n; j++){
                if(val[j] <= i){
                    dp[i][j] = max(dp[i][j-1] , dp[i-val[j]][j] + val[j]);
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        cout << dp[k][n] << endl;
    }
    return 0;
}
