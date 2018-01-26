/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/problems/FRJUMP
*	tag	:	modular inverse,
*
**/

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<memory.h>
#include<cstring>
using namespace std;
 
#define mod 1000000007
 
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e9;
 
int mod_inv(int x) {
  return x == 1 ? 1 : 1LL * (MOD - MOD / x) * mod_inv(MOD % x) % MOD;
}
 
int prod[N];
 
long double lg[N] , slog[N]; 
vector <int> rIndex[N];
long long int city[N];
int main() {
    
    long long int n, i, r, q, ch, j, k;
    int sqroot = sqrt(N);
    scanf("%lld", &n);
   // cout << sqroot << "\n";
    for(i = 0 ; i < n ; i++){
          scanf("%lld", &city[i]);
          lg[i] = log10l((long double)city[i]);
    }
    
    // for each R store corresponding products and log sum
    for(r = 1 ; r <= 316 ; r++ ){
        prod[r] = 1;
        for(i = 0 ; i < n ; i+=r ){
            rIndex[i].push_back(r);
            prod[r] = 1LL * prod[r] * city[i] % MOD ;
            /*if(r<5)
                cout << r << " " << prod[r] << "\n";*/
            slog[r] += lg[i] ;
        }
    }
    
    scanf("%lld", &q);
    
    while(q--){
        scanf("%lld %lld", &ch, &r);
        if(ch==1){
            int idx, nv;
            int rToBeUpdate;
            idx = r;
            scanf("%d", &nv);
            long double nlv = log10l((long double)nv);
            
            //if(idx <= sqroot + 20){
            int inv = mod_inv(city[idx-1]);
            for(i = 0 ; i < rIndex[idx - 1].size() ; i++){
                rToBeUpdate = rIndex[idx-1][i];
                prod[rToBeUpdate] = 1LL* prod[rToBeUpdate] * inv % MOD * nv % MOD ;
                slog[rToBeUpdate] += nlv - lg[idx-1];
            }
            //}
            city[idx - 1] = nv;
            lg[idx - 1] = nlv;
        }
        else{
            if(r <= 316){
            long double digit = powl(10.0, slog[r] - floorl(slog[r]) + 1e-11);
            while (digit >= 10.0) {
            digit /= 10.0;
            }
            while (digit < 1.0) {
            digit *= 10.0;
            }
                printf("%d %d\n", (int)digit, prod[r]);
            }
            else{
                double first = 0.0;
                long long int sol = 1;
            for(j = 0 ; j < n ; j+=r){
                first += (double)log10(city[j]);
                sol = (sol * city[j] )% mod ;
            }
          //  cout << "s:" << first <<"\n";
            long long int des = first;
            first = (double)first - des;
           // cout << "frac:" << first <<"\n";
            long long int ans;
            ans = pow(10,first+0.0000001);
            cout << ans << " "<< sol % mod << "\n";
            }
        }
    }
    
    return 0;
}