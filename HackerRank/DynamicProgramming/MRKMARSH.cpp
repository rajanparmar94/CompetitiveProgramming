/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.hackerrank.com/challenges/mr-k-marsh/problem
*
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


char ch[501][501] ;
int main() {

    int m, n, i, j, k, l ;
    long long int sol = 0;
    cin >> n >> m;
    
    for(i = 0; i<n ; i++)
        for(j = 0; j<m; j++)
            cin >> ch[i][j];
    for(i = 0; i < n ; i++){
        for(j = 0; j < m ; j++){
            
            if(ch[i][j]=='x')   continue;
            
            for(k = j+1 ; k < m && ch[i][k]!='x'; k++){
                
                int dist = 1;
                //cout <<i <<" "<< j << " "<< k << ch[i][k] <<"\n";
                while(i+dist < n && ch[i+dist][j]!='x' && ch[i+dist][k]!='x'){
                   // cout << "enter , " << dist << "\n";
                    
                    for(l = j ; l<=k ; l++){
                       // cout <<l <<" " << dist << ch[i+dist][l] << endl;
                    if(ch[i+dist][l]=='x')
                        break;
                    }
                    
                    if(l>k){
                    long long int par;
                    par = 2 * (dist) + 2 * (k - j);
                    sol = max(sol ,par);
                    }
                    dist++;
                }
                
            }
        }
    }
    if(sol)
        cout << sol << endl;
    else
        cout <<"impossible" << endl;
    return 0;
}