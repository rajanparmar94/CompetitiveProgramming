/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/sam-and-substrings/problem
*
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    long long int len,i,sec,total;
    long long int dp[200005];
    cin>>s;
    len = s.length();
    dp[0]=s.at(0) - '0';     
       
    for(i=1;i<len;i++){
        sec = s.at(i) - '0';
        dp[i] = (sec*(i+1) + 10*dp[i-1])%mod;       
       
    }
    total=0;
    for(i=0;i<len;i++){
         total = (total+dp[i])%mod;
    }
   
    
    cout<<total<<"\n";
    return 0;
}