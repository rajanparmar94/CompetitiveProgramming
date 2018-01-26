/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/problems/RECRECOV
*	tag	:	BiPartite Matching
*
**/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define gc getchar_unlocked
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
int available(int link[][101] , int match[] ,int seen[] , int u, int n ){
    
    for(int i = 1 ; i<=n ; i++ ){
        if(!seen[i] && link[u][i]){
           seen[i]=1; 
        if(match[i]== -1)
        {
            match[i] = u;
            return 1;
        }
        else{
            
            if(available(link , match , seen , match[i], n))
            {
                match[i] = u;
                return 1;
            }
        }
        }
    }
    return 0;
}
int maxPath(int link[][101],int n){
    int match[101],seen[101],sol;
    memset(match , -1 , sizeof(match));
    sol=0;
    for(int i=1 ; i<= n ; i++){
        memset(seen , 0 , sizeof(seen));
        if(available(link,match,seen,i,n))
        sol++;
    }
    return sol;
}
int main(){
    int t,n,m,u,v;
    int link[101][101];
    t = read_int();
    while(t--){
        n = read_int();
        m = read_int();
        memset(link , 0 , sizeof(link));
        while(m--){
            u = read_int();
            v = read_int();
            link[u][v] = 1;
        }
        cout<<n-maxPath(link,n)<<"\n";
    }
    return 0;
} 