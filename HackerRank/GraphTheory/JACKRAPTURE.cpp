/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem
*
**/

#include <iostream>
#include <utility>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

#define N 50000
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
	ll weight;
	Vec *next;

	Vec(){
		id = 0;
		weight = 0;
		next = NULL;
	}

	void insert(Vec *head, int id, ll weight){

		Vec *temp = new Vec();
		temp->id = id;
		temp->weight = weight;
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


void dfs(int x, int range){
	
	if (vis[x])	return;

	//cout << x << " ";

	vis[x] = 1;

	Vec *ptr;
	ptr = graph[x];
	while (ptr->next != NULL){
		int id = ptr->next->id;
		ll cost = ptr->next->weight;
		//cout << "cost:" << cost << "\n";
		if (cost <= range){
			dfs(id, range);
		}
		ptr = ptr->next;
	}
}

int main()
{
	int n, e;
	int x, y;
	ll w;
	ll low, high, mid;
	ans = -1;
	low = 1;
	high = 0;
	//freopen("input.txt", "r", stdin);
	//freopen("Text.txt", "w", stdout);

	memset(mn, -1, sizeof(mn));
	cin >> n >> e;

	for (int i = 1; i <= n; i++){
		graph[i] = new Vec();
	}

	while (e--){
		cin >> x >> y >> w;
		high = (w > high) ? w : high;
		graph[x]->insert(graph[x] , y, w);
		graph[y]->insert(graph[y], x, w);
	}
	//display(n);
	while (low <= high){
		mid = (low + high) / 2;
		//cout << "mid:" << mid << "\n";
		memset(vis, 0, sizeof(vis));
		dfs(1, mid);
		if (vis[n]){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	//find_min(1, n, -1, 0);
	if (ans == -1)
		cout << "NO PATH EXISTS\n";
	else
		cout << ans << "\n";
	
	//system("pause");
	return 0;
}

