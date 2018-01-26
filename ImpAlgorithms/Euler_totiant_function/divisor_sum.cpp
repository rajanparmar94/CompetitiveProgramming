#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <set>
#include <memory.h>
#include <algorithm>
#include <map>
using namespace std;
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;
#define pb push_back
#define mp make_pair
#define N 1000001

ll sum[N+1];

ll primes[N+1];

void pgen(){
	ll i, j;
	memset(primes , 0 ,sizeof(primes));
	for(i = 2 ; i <= N ; i+=2)
	    primes[i] = 2;
	for(i = 3 ; i <= N ; i+=2){
		if(primes[i]==0){
		    primes[i] = i;
			for(j = i ; j*i <= N ; j+=2){
				primes[j*i] = i;
			}
		}
	}
}
ll dsum(ll n){
    ll tn = n;
    ll mul = 1;
    while(tn!=1){
        ll pf = primes[tn];
        ll sum = 1;
        ll tm = 1;
        while(tn%pf == 0){
            tn/=pf;
            sum += (tm * pf);
            tm = pf*tm;
        }
        
        mul*=sum;
        
    }
    return mul;
}
int main()
{
    ll n , i, j, tn;
    cin >> n;
    pgen();
    
    sum[1] = 1;
    for(i = 2 ; i <= N ; i++){
        
        sum[i] = dsum(i) + sum[i-1];
    }
    
    cout << dsum(n);
    /*
    for(i = 0 ; i < n ; i++){
        cin >> in[i];
        cout << primes[in[i]] << "\n";
    }*/
    return 0;
}