/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*
**/

#include <iostream>
#include <utility>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

#define N 100000
#define f first 
#define s second 
#define pb push_back

typedef long long int ll;

//vector < pair <int, ll> > graph[N + 1];
ll mn[N + 1];
ll ans ;

class Vec{

public:

	int id;
	
	Vec *next;

	Vec(){
		id = 0;
		
		next = NULL;
	}

	void insert(Vec *head, int id){

		Vec *temp = new Vec();
		temp->id = id;
		
		temp->next = NULL;

		if (head->next == NULL){
			head->next = temp;
		}
		else{
			Vec *ptr;
			ptr = head;
			while (ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = temp;
		}
	}

};
Vec *graph[N + 1];
int vis[N + 1];

void display(int n){

	for (int i = 1; i <= n; i++){
		Vec *temp = graph[i];
		while (temp != NULL){
			cout << temp->id << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void dfs(int x, int &cnt){
	
	if (vis[x])	return;

	vis[x] = 1;
	cnt++;
	Vec *ptr;
	ptr = graph[x];
	while (ptr->next != NULL){
		int id = ptr->next->id;
		
		//cout << "cost:" << cost << "\n";
		dfs(id, cnt);
		ptr = ptr->next;
	}
}

int main()
{
	int n, e;
	int x, y;
	ll w;
	ll ans;
	ans = 0;
	
//	freopen("input.txt", "r", stdin);
//	freopen("Text.txt", "w", stdout);

	memset(mn, -1, sizeof(mn));
	cin >> n >> e;

	for (int i = 0; i < n; i++){
		graph[i] = new Vec();
	}

	while (e--){
		cin >> x >> y;
		
		graph[x]->insert(graph[x] , y);
		graph[y]->insert(graph[y], x);
	}
	//display(n);

	int ar_len = 0;
	ll ar[N + 1], sar[N + 1];
	int size = 0;

	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < n; i++){
		size = 0;
		dfs(i, size);
		if (size == 0)
			continue;
		ar[ar_len] = size;
		ar_len++;
	}
	memset(sar, 0, sizeof(sar));
	sar[0] = ar[0];
	for (int i = 1; i < ar_len; i++){
		sar[i] = sar[i - 1] + ar[i];
	}

	for (int i = 0; i < ar_len; i++){
		ans += ((sar[ar_len - 1] - sar[i] ) * ar[i]);
	}

	cout << ans << "\n";
	//system("pause");
	return 0;
}
