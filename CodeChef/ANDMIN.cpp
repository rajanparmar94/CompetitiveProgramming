/**
*	
*	BY  :   Rajan Parmar
*	link:	https://www.codechef.com/problems/ANDMIN/
*	Tag:	Segment Tree
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
#define MAX 100000
 
typedef long long int ll;
typedef pair<ll, ll > pi;
typedef pair<ll, pi > pii;
 
struct node {
    
    bool bits[32];
    ll mini;
    
}tree[MAX*5];
 
ll arr[MAX+5];
 
void build(int n, int b, int e)
{
 if (b>e) return;
 else if (b==e)
 {
  tree[n].mini = arr[b];
  for(int i = 0 ; i < 32 ; i++){
      tree[n].bits[i] = arr[b]|(1<<i);
  }
  return;
 }
 
 build ( n*2 , b , (b+e)/2 ); 
 build (n*2+1, (b+e)/2 + 1 , e );
 
 for(int i = 0 ; i < 32 ; i++){
     tree[n].bits[i] = tree[n*2].bits[i] | tree[n*2 + 1].bits[i];
 }
 tree[n].mini = min( tree[n*2].mini , tree[n*2 + 1].mini );
 
}
//b , e is neg and end i.e 1 to N
void update(int n, int b, int e, int l ,int r, int val)
{
 if (b > e ) return;
 if(e < l || b > r) return ; 
 int check = 0;
 for(int i = 0 ; i < 32 ; i++){
    if((val & (1<<i)) == 0 && tree[n].bits[i] == 1) {
       // if(tree[n].bits[i] == 1){
        check = 1;
        break;
       // }
    }
 }
 if(check==0)
 return;
 if (b==e) //at leaf node
 {
    for(int i = 0 ; i < 32 ; i++){
        tree[n].bits[i] &= ((val >> i)&1);
    } 
    
  tree[n].mini &= val;
  return;
 }
 
 update( n*2 , b , (b+e)/2 , l , r, val );
 update( n*2 + 1 , (b+e)/2 + 1 , e , l , r, val );
 
 //now some change might have been made in either of the child nodes.
 
 
 for(int i = 0 ; i < 32 ; i++){
     tree[n].bits[i] = tree[n*2].bits[i] | tree[n*2 + 1].bits[i];
 }
 tree[n].mini = min( tree[n*2].mini , tree[n*2 + 1].mini );
 
}
ll query(int n, int b, int e, int i, int j)
{
 if (b>e || b>j || i > e)
 return mod;
 
 if (b>=i && e<=j)
  return tree[n].mini; //the increment of current node is already added to cmax here (see update function)
 
  
 return min ( query(n*2 , b , (b+e)/2 , i , j) , 
  query(n*2+1 , (b+e)/2 + 1 , e , i , j) );
}
int main() {
 
    ll tt , n, q, i , ch, l , r , x;
    
	cin >> n >> q;
	for(i = 1 ; i <= n ; i++){
	    cin >>arr[i];
	}
	build(1, 1, n);
	
	while(q--){
	    cin >> ch;
	    if(ch==1){
	        cin >> l >> r >> x;
	        update(1, 1, n, l ,r, x);
	    }
	    else{
	        cin >> l >> r;
	        cout <<query(1,1,n, l, r) << "\n";
	    }
	}
	return 0;
}