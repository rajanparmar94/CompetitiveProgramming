/**
*   U_ID        : rajan_parmar
*   Author      : Rajan Parmar
*   Ispired by  : ganeshk2
*	link		: https://www.codechef.com/problems/CYCLRACE
**/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
typedef long long int ll;
typedef pair<ll,ll> pll;
 
ll y_intercept[50001] , slope[50001];
ll indx;
 
// pair ( slope , y_intercept )
vector < pair < ll , ll > > lines;
vector < pair < ll , ll > > valid_lines;
vector < ll > query ;
 
//fast input
ll input(){
    
	int ip=getchar_unlocked(),flag=1;ll ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-')
	{
	    flag=-1;
	    ip=getchar_unlocked();
	    break;
	    
	}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
	ret=ret*10+ip-'0'
	;return flag*ret;
    
}
 
// m1x + c1 = m2x + c2 => x = (c2 - c1)/(m1 - m2)
// if intersection ( here x coordinate ) of a,c is lesser than a,b , remove line b as this will
// not contribute to any maximum distance . See fully dynamic variant of convex hull trick
bool irrelevant(pll a , pll b , pll c){
    
    return (c.se - a.se) /(double) (a.fi - c.fi) < (b.se - a.se) / (double)(a.fi - b.fi) ;
    
}
 
//add only those line that can contribute in finding maximum distance.
void add(pll curr){
    ll valid_size = valid_lines.size();
    if(valid_lines.size() > 1){
        
        while( valid_lines.size() > 1 && irrelevant(valid_lines[valid_size-2] , 
        valid_lines[valid_size-1] , curr))
        {
            valid_lines.pop_back();
            valid_size--;
        }
               
    }
    valid_lines.pb(curr);
}
 
/*
As time is in sorted order he calculated maximum slope at minimum given t say 1 .
Now for the next given time say (tnext) there is no way that lines having slope
less than previously identified slope at t=1 , have max Y . Either it can be line
with greater slope at t = tnext or current line as we identified at t=1 . 
*/
ll findMax(ll tm){
    
    if(indx >= valid_lines.size())
        indx = valid_lines.size() - 1;
    while(indx < valid_lines.size()-1 && ( valid_lines[indx+1].fi * tm + valid_lines[indx+1].se >
    valid_lines[indx].fi * tm + valid_lines[indx].se) )
    indx++;
    return valid_lines[indx].fi * tm + valid_lines[indx].se;
}
 
int main(){
    
    ll n, q, i, j, tm, cid, newSpeed ;
    int ch;
    cin>>n>>q;
    
    memset(y_intercept , 0 , sizeof(y_intercept));
    memset(slope , 0 , sizeof(slope));
    indx = 0;
    
    while(q--){
        
        ch = input();
        
        if(ch==1){
            
            tm          = input();
            cid         = input() ; 
            newSpeed    = input();
            
            // y = mx + c => c = y - mx 
            // suppose m (velocity) of line changes then what will be y intercept of new line?
            // Well , it is y - mx where m = new velocity , x = new time
            // how to calculate y ?
            // y = mx + c (where m is previous velocity , x is previous time)
            // for first time m=0, c=0 ;
            lines.pb(mp(newSpeed , slope[cid]*tm + y_intercept[cid] - newSpeed*tm));
            y_intercept[cid] = slope[cid]*tm + y_intercept[cid] - newSpeed*tm;
            slope[cid] = newSpeed ; 
        }
        else{
            tm = input();
            query.pb(tm);
        }
    }
    
    sort(lines.begin() , lines.end());
    
    for(i = 0 ; i<lines.size() ; i++){
        add(lines[i]);
    }
    for(i = 0 ; i<query.size() ; i++){
        cout << findMax(query[i]) << endl;
    }
    return 0;
} 