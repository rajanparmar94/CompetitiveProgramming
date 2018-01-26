/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/JAN16/problems/RGAME/
*
**/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define gc getchar_unlocked
#define mod 1000000007
 
 
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
ll mul[100001],count1[100001],in[100001],dp[100001];
int main(){
    int t;
    ll i,j,n,sol;
    cin>>t;
    mul[0]=mul[1]=2;
    
    for(i=2;i<=100000;i++){
        mul[i] = (mul[i-1]*2)%mod;
    }
    while(t--){
        
        cin>>n;
        for(i=0;i<=n;i++){
            cin>>in[i];
        }
        count1[0]=(mul[0]*in[0])%mod;
            
        for(i=1;i<=n;i++){
            count1[i] = (count1[i-1] + mul[i]*in[i])%mod;
           // cout<<count1[i]<<" ";
        }
        sol=0;
        for(i=1;i<=n;i++){
            dp[i] = (count1[i-1]*in[i])%mod;
            sol += (sol+ dp[i])%mod;
        }
        cout<<sol%mod<<"\n";
    }
    return 0;
} 