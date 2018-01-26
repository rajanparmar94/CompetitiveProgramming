/**
*	
*	BY	:	Rajan Parmar
*	link:	https://www.codechef.com/problems/SQNUMBF/
*/
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;
 
#define N 100
#define fi first
#define se second
#define mp make_pair
#define gc getchar_unlocked
#define mod 1000000007
#define MAX 1000000
 
typedef long long int ll;
typedef pair<ll, ll > pi;
typedef pair<ll, pi > pii;
 
ll ar[N+5];
vector <ll> vec;
ll prod;
int prime[MAX+5];
 
int main() {
 
	int t ; 
	int n, m , k;
	ll i, j,x;
	ll sol;
	prod = 1;
	
	cin >> t;
	

	int f=0;
	while(t--){
	    cin >> n;
	    prod = 1;
	    f = 0;
	    ll rt , beg , end , middle, l;
	    for(i = 0 ; i < n ; i++){
	    cin >> ar[i];
	    //prod*=ar[i];
	    //rt = (ll)sqrt(ar[i]);	    
	    
	    }
	    sol = 0;
	    for(i = 0; i < n ; i++){
	        for(j = i+1 ; j < n ; j++){
	           
	            x = __gcd(ar[i],ar[j]);
	            if(x!=1){
	                
	                sol = x;
	                break;
	                
	            }
	        }
	    }
	    
	    if(sol==0){
	    
	     f= 0;
	    if(f==0){
	   
	    
	    for(i = 0 ; i < n && f==0 ; i++)
	    {
	    for(j = 2 ; j*j*j <= ar[i] ; j++){
	        if(ar[i]%(j*j) ==0){
	            sol = j;
	            f = 1;
	            break;
	        }
	    }
	   }
	    
	   
	   
	   
    for(i = 0 ; i < n && f==0; i++){
	    for(j = 1 ; j*j*j<= ar[i] && j<=MAX ; j++){
	        ll cur;
	        if(ar[i]%j == 0){
	            cur = ar[i]/j;
	            ll rt = (long long)sqrt(cur) + 1E-6;
	            if(rt*rt == cur && rt>1){
	            f = 1;
	            sol = rt;
	            break;
	            }
	                }
	            }
	        }
    
	    }
	   
	        cout << sol << "\n";
	       
	    
	    }
	    else
	    cout << sol << "\n";
	    
	}
	return 0;
}