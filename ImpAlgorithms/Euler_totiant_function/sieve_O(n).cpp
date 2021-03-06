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
//#define N 1000001

const int N = 10000000;
ll sum[N+1];

ll primes[N+1];


int lp[N + 1];
int phi[N + 1];
vector<int> pr;

// calculate smallest prime in O(n)
void calc_sieve()
{
    
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
/*
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
}*/
ll dsum(ll n){
    ll tn = n;
    ll mul = 1;
    while(tn!=1){
        ll pf = lp[tn];
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
    calc_sieve();
    //cout << dsum(n) << "\n";
    //pgen();
    
    sum[1] = 1;
    for(i = 2 ; i <= N ; i++){
        if(i==lp[i])
            sum[i] = sum[i-1] + i + 1;
        else
            sum[i] = dsum(i) + sum[i-1];
        
    }
    
    cout << sum[n] << "\n";
    /*cout << dsum(n);
    
    for(i = 0 ; i < n ; i++){
        cin >> in[i];
        cout << primes[in[i]] << "\n";
    }*/
    return 0;
}