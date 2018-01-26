/**
*	SPOJ : http://www.spoj.com/problems/KQUERY/
*	SegmentTree
*	BY : Rajan Parmar	
*/


#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N 30000
#define fi first
#define se second
#define mp make_pair
#define gc getchar_unlocked


typedef long long int ll;
typedef pair<ll , ll > pi;
typedef pair<ll , pi > pii;

struct ar{
    int idx;
    int value;
    bool operator < (const ar& a) const
    {
        return (value < a.value);
    }
};

struct qry{
    int idx;
    int i;
    int j;
    int k;
    bool operator < (const qry& a) const
    {
        return (k < a.k);
    }
};

int b[4 * N];
int ans[200002];
ar in[N + 2];
qry qr[200002];

void build(int id , int l, int r){
    if(l==r){
        b[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id , l , mid);
    build(2 * id + 1 , mid + 1 , r);
    b[id] = b[2 * id] + b[2 * id + 1] ;
}

void update(int x, int id, int l, int r){
    if(l == r){
    
        b[id] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    
    if(x <= mid)
        update(x, 2*id, l, mid);
    else
        update(x, 2*id + 1, mid + 1, r);
       
    b[id] = b[2 * id] + b[2 * id + 1] ;
    
}

int query(int id, int x, int y, int l, int r){
    
    if(r < x || y < l)
        return 0;
        
    if(l >= x && r <= y)
        return b[id];
        
    int mid = (l + r) >> 1;
    int a = query(2 * id, x, y, l, mid);
    int b = query(2 * id + 1, x, y, mid+1, r);
    return a+b;
}

int main(){
	
	ll maxTime;
			clock_t tStart = clock();

    freopen("testFile.txt", "r", stdin);
	freopen("testFileOutputKQuery.txt", "w", stdout);
    
    int n, q, i, j;
    int backup_n;
    i=0;
    cin >> n;

    backup_n = n;
    while (n--){

        in[i].idx = i;
        cin >> in[i].value;

	  ++i;
    }
    
    cin >> q;
	int backup_q = q;
    i = 0;
    while(q--){
        qry ob;
       // ob.idx = i++;
	   qr[i].idx = i;
        cin >> qr[i].i;
        cin >> qr[i].j;
        cin >> qr[i].k;
		i++;
    }

    sort(in, in + backup_n);
	sort(qr, qr + backup_q);
    build(1, 0, backup_n-1);
    
    int po=0;
    
    for(i = 0; i<backup_q ; i++){
        
        while(po < backup_n && in[po].value <= qr[i].k){

            update(in[po].idx, 1, 0, backup_n-1);
            po++;
        }
        
        ans[qr[i].idx] = query(1, qr[i].i-1, qr[i].j-1, 0, backup_n-1);

    }
   
    for(i = 0; i < backup_q ; i++)
        cout << ans[i] << endl;
       	printf("Time taken : %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
