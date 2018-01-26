/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/array-splitting/problem
*
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define N 16390
typedef long long int ll;

ll sum[N], ar[N];
int n;
int solve(int l , int r , int x){
    if(x > r || l > r || r > n)
        return 0;
    if(sum[x] - sum[l-1] == sum[r] - sum[x])
        return 1 + max(solve(l , x , l) , solve(x+1, r , x+1));
    else
        return solve(l, r, x+1);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, i;
    cin >> t;
    while(t--){
        cin >> n;
        memset(sum , 0 , sizeof(sum));
        for(i = 1 ; i <= n ; i++){
            cin >> ar[i];  
            sum[i] = sum[i-1] + ar[i];
        }
        int sol;
        if(sum[n]==0)
            sol = n-1;
        else sol = solve(1,n,1);
        cout << sol << "\n";
        
    }
    return 0;
}
