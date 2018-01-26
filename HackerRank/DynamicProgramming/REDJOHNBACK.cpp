/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/red-john-is-back/problem
*
**/

#include <cmath>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 217286

int prime[N+1];
int countP[N+1];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    long long int i,j;
    
    memset(prime , 0, sizeof(prime));
    prime[1] = 1;
    for(i=2;i<=N;i++){
        if(!prime[i]){
            for(j = i*2; j<=N ; j+=i)
                prime[j] = 1;
        }
    }
    countP[0] = 0;
    for(i=1;i<=N;i++){
        //countP[i] = countP[i-1] + (prime[i]==0)?1:0;
        if(prime[i]==0)
            countP[i] = countP[i-1] + 1;
        else
            countP[i] = countP[i-1] ;
                    
    }
    
    long long int getWay[41];
    getWay[1] = getWay[2] = getWay[3] = 1;
    getWay[4] = 2;
    
    for(int i=5; i<=40; i++){
        getWay[i] = getWay[i-4] + getWay[i-1];
    }
    
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << countP[getWay[n]] << endl;
    }
    
    return 0;
}
