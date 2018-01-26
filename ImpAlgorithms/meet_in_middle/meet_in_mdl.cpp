/*
*Meet in the middle algo : http://www.geeksforgeeks.org/meet-in-the-middle/
*/

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
#define N 40

ll ar[N+1];
ll a[1<<(N/2)] , b[1<<(N/2)];

void split(ll ta[] ,ll tg[] , int beg , int end , int c) {
    ll lim = (1<<(end - beg + 1));
    ll i , j;
    for( i = 0 ; i < lim ; i++){
        ll sm = 0;
        for( j = 0 ; j < end - beg + 1 ; j++){
            if( i & (1<<j))
                sm += ta[c + j];
        }
        tg[i] = sm;
    }
    
}

int main()
{
    ll n , ans, i, j, sol , sum;
    cin >> n;
    ans = 0;
    for(i = 0 ; i <n ; i++){
        cin >> ar[i];
    }
    cin >> sum;
    split(ar, a, 0, n/2 - 1, 0 );
    split(ar, b, n/2, n-1, n/2 );
    
    ll sz_b = ( 1 << (n - n/2)) ;
    ll sz_a = ( 1 << (n/2)) ;
    sort(b , b + sz_b );
    
    sol = 0;
    for(i = 0 ; i < sz_a ; i++){
        
        ll idx;
        if(a[i] <= sum){
            idx = lower_bound(b, b+sz_b, sum - a[i]) - b;
            if (idx == sz_b || b[idx] != (sum-a[i]))
                idx--;
            sol = max( sol , a[i] + b[idx]);
        }
    }
    
    cout << sol << "\n";
    
    return 0;
}