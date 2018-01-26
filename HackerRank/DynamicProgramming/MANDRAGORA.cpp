/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/mandragora/problem
*
**/

#include <cmath>
#include <memory.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long int li;
#define N 100001

li sum[N+1];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    li t, n , i, j, p, s;
    cin >> t;
    while(t--){
        cin >> n;
        vector <li> vec(n);
        p = 0;
        s = 1;
        memset(sum , 0 , sizeof(sum));
        for( i = 0 ; i < n ; i++ ) {
            scanf("%ld",&vec[i]);
        }
        
        sort(vec.begin() , vec.end());
        sum[-1] = 0;
        for( i = 0 ; i < n ; i++ ) {
            sum[i] = sum[i-1] + vec[i];
        }
        if(n==1){
            p = vec[0];
        }
        else{
            for(i = 0 ; i < n - 1 ; i++){
                s++;
                p = max(p , (sum[n-1] - sum[i]) * s);
            }
        }
        cout << p << "\n";
        
    }
    return 0;
}
