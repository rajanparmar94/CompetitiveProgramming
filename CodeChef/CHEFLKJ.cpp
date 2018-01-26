/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/problems/CHEFLKJ/
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <set>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100000
 
#define MAX 1000000007
 
struct node{
    ll maxVal;
    unordered_map < ll , int > occur ;
}tree[N*4];
 
ll in[N+1];
vector <int> qry;
void build(int id , int l , int r){
   
    if(l==r){
        
        tree[id].occur.clear();
        tree[id].maxVal = in[l];
        tree[id].occur[in[l]] += 1 ;
     return;
    }
    
    int mid = (l+r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r );
    
    tree[id].occur.clear();
   
    for(auto &it:tree[2 * id ].occur){
       // cout << ".";
        tree[id].occur[it.first] += it.second;
    }
    
    for(auto &it:tree[2 * id + 1].occur){
        tree[id].occur[it.first] += it.second;
    }
    
    int length = r - l + 1 ;
    
    if( tree[id].occur[tree[2 * id].maxVal] > length/2 ){
        tree[id].maxVal = tree[2 * id].maxVal;
    }
    else{
        if( tree[id].occur[tree[2 * id + 1].maxVal] > length/2 ){
            tree[id].maxVal = tree[2 * id + 1].maxVal;
        }
        else
            tree[id].maxVal = -1;
    }
}
 
void update(int idx ,int id, int l, int r , ll val , ll oldVal){
    
    if(idx < l || idx > r)
        return;
    if(l == r){
        tree[id].maxVal = val;
        tree[id].occur.clear();
        tree[id].occur[val] += 1;
        in[l] = val;
        
        return;
    }
    int mid = (l + r) / 2;
    
    if(idx <= mid)
        update(idx , 2*id , l , mid , val , oldVal);
    else
        update(idx , 2*id +1 , mid + 1 , r , val , oldVal);
        
    tree[id].occur[oldVal] -= 1;
    tree[id].occur[val] += 1;
    
    int length = r - l + 1 ;
    
    if( tree[id].occur[tree[2 * id].maxVal] > length/2 ){
        tree[id].maxVal = tree[2 * id].maxVal;
    }
    else{
        if( tree[id].occur[tree[2 * id + 1].maxVal] > length/2 ){
            tree[id].maxVal = tree[2 * id + 1].maxVal;
        }
        else
            tree[id].maxVal = -1;
    }
    //cout <<"update:"<< id << " " << tree[id].occur[val] << "\n";
}
 
void query(int beg , int end , int x , int y , int id){
    
   
    if(y < beg || x > end)
        return;
        
    if(x <= beg && y >= end){
        qry.push_back(id);
        return;
    }
    
    int mid = (beg + end) / 2;
    
    query(beg , mid , x , y , 2*id);
    query(mid + 1 , end , x , y , 2*id + 1);
    
}
 
int main()
{
    int n, q, i, j, ch;
    
    cin >> n >> q;
    for(i = 0; i < n ; i++)
        cin >> in[i];
    
    build(1, 0 , n-1);
    
    while(q--)
    {
        cin >> ch;
        if(ch == 1){
            int x, y;
            cin >> x >> y;
            update(x - 1 ,1, 0, n - 1 , y , in[x-1]);
        }
        else{
            int l, r, f;
            cin >> l >> r;
            query(0 , n - 1 , l-1 , r-1 , 1);
            int len = r - l + 1;
            f = 0;
            for(i = 0 ; i < qry.size() ; i++){
                ll cnt = 0;
                for(j = 0 ; j < qry.size() ; j++){
                    cnt += tree[qry[j]].occur[ tree[qry[i]].maxVal ];
                 //   cout << qry[j] << " " <<tree[qry[j]].occur[ tree[qry[i]].maxVal ];
                }
               // cout << endl;
                if(cnt > len / 2){
                    f = 1;
                    break;
                }
            }
            if(f)
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
            qry.clear();
        }
    }
    return 0;
} 