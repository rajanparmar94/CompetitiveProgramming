/**
*	
*	BY : 	Rajan Parmar
*	link:	https://www.codechef.com/problems/LFSTACK
*/
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;
#pragma warning(disable:4996)
#define fi first
#define pb push_back
#define se second
#define mp make_pair
#define gc getchar_unlocked
#define mod 1000000007
#define N 1000000
 
typedef long long int ll;
typedef pair<ll, ll > pi;
typedef pair<ll, pi > pii;
 
vector < int > th[N + 1];
int order[N + 1];
int used[N + 1];
int th_n;
int n, sol, seen; 
 
int check(int id)  {
    
    if(id < 0 )
        return 1;
    
    
    for(int i = 0 ; i < th_n ; i++) {
        
        if(th[i].back() == order[id]){
            th[i].pop_back();
            if(check(id - 1))
                return 1;
            th[i].push_back(order[id]);
        }
    }
    return 0;
}
 
int main() {
 
    int t, i , j, x, y;
    
    cin >> t;
    
    while(t--)  {
        
        n = 0;
        seen = sol = 0;
        memset(used , 0 , sizeof(used));
        cin >> th_n;
        for(i = 0 ; i < th_n ; i++)
            th[i].clear();
        for(i = 0 ; i < th_n ; i++)
        {
            cin >> x;
            n += x;
            while(x--)  {
                cin >> y;
                th[i].pb(y);
            }
            reverse(th[i].begin() , th[i].end());
        }
        
        for(i = 0 ; i < n ; i++)
        cin >> order[i];
        
        //check(n - 1);
        if(th_n == 1){
            int f = 1;
            //reverse(th[0].begin() , th[0].end());
            for(i = 0 ; i < th[0].size() ; i++){
                if(th[0][i] != order[i]){
                    f = 0;
                    break;
                }
            }
            if(f)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        
        if(check(n - 1))
            cout << "Yes\n";
        else
            cout << "No\n";
            
        
    }