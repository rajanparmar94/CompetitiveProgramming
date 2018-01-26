#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
 
template <typename T>T mod(T a, T b) {return (a < b ? a : a % b);}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T InverseEuler(T a, T m){return (a==1?1:power(a,m-2,m));}
 
typedef long long int ll;
const int MAX   = 100005;
const ll  MOD   = 1000000007LL;
 
ll fact[MAX], invp[MAX];
 
void pre() {
    fact[0] = invp[0] = 1LL;
    for(int i=1; i<MAX; ++i) {
        fact[i] = mod(fact[i-1]*i, MOD);
        invp[i] = InverseEuler(fact[i], MOD);
    }
}
 
ll C(int n, int r) {
    if (r>n || r<0) return 0;
    return mod(fact[n] * mod(invp[n-r]*invp[r], MOD), MOD);
}
 
int main() {
	// your code goes 
	int t, i;
	int n, k, x;
	ll ans;
	ll c = 0;
	cin >> t;
	pre();
//	cout << C(n, k , MD) << endl ;
	while(t--){
	    c = 0;
	    cin >> n >> k ;
	    for(i = 0 ; i < n ; i++){
	        cin >> x;
	        if(x!=0)
	        c++;
	    }
	    if(n!=c)
	        n = c + 1;
	        
	    if(k > n){
	        if((k - n)&1)
	            k = n - 1;
	        else
	            k = n;
	    }
	    
	    ans = 0;
	//    cout << "k:" << k <<"...." << "n:" << n <<"\n";
	    
	    while(k>=0){
	        
	     //   cout << k <<",";
	       // cout << n << " " << k << " " << C(n, k) << "\n";
	        ans  = (ans+C(n, k)) % MOD;
	        k-=2;
	    }
	    cout << ans << endl;
	}
	return 0;
} 