#include <cmath>
#include <memory.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000
typedef long int li;

li ar[N+1], lis[N+1], n;

int find(li beg , li end, li val){
    li mdl;
    while(beg <= end){
        mdl = (beg + end)/2;
        if(lis[mdl] >= val && lis[mdl-1] < val)
            return mdl;
        if(lis[mdl] >= val)
            end = mdl - 1;
        else
            beg = mdl + 1;
    }
    return  0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    li len = 0 , i;
    memset(lis , 0 , sizeof(lis));
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
    cin >> n;
    for(i = 0 ; i < n ; i++)
        cin >> ar[i];
    lis[0] = ar[0];
    len++;
    li lastIndex = 0;
    for(i = 1 ; i < n ; i++){
        if(ar[i] > lis[lastIndex]){
            len++;
            lastIndex++;
            lis[lastIndex] = ar[i];
			//cout << "last idx:" << lastIndex <<":" << lis[lastIndex]<< endl;
        }
        else{
            if(ar[i] < lis[0])
                lis[0] = ar[i];
            else{
                li idx = find(0 , lastIndex, ar[i]);
                lis[idx] = ar[i];
            }
        }
        
    }
    cout << len << "\n";
    return 0;
}
