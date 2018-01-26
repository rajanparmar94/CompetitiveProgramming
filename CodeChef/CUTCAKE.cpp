/**
*	
*	BY  : 	Rajan Parmar
*	link:	https://www.codechef.com/problems/CAKECUT/
*
**/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>
using namespace std;
 
string in[1505];
int Xor[1505][1505];
bitset<1505> bits[1505];
int n, m;
 
long long ans = 0;
 
int main() {
	int i, j;
    cin >> n >> m;
    
    for(i = 0 ; i < n ; i++)
	cin >> in[i];
	
	Xor[0][0] = in[0][0] - '0';
	for(i = 1 ; i < m ; i++){
	    Xor[0][i] = Xor[0][i-1]^(in[0][i]- '0');
	    //cout << i << ":" << Xor[0][i];
	}
	    
	for(j = 1 ; j < n ; j++)
	    Xor[j][0] = Xor[j-1][0]^(in[j][0] - '0'); 
	  
	for(i = 1 ; i < n ; i++){
	    for(j = 1 ; j < m ; j++){
	        Xor[i][j] = Xor[i-1][j]^Xor[i][j-1]^Xor[i-1][j-1]^(in[i][j]-'0');
	        //bits[i][j] = Xor[i][j];
	    }
	    
	}  
	for(i = 0 ; i < n ; i++){
	    for(j = 0 ; j < m ; j++){
	    bits[i][j] = Xor[i][j];
	    ////cout << Xor[i][j];
	    //cout << endl;
	    }
	}
	long long int sol = 0;
	int z, o;
	for(i = 0 ; i < n ; i++){
	    
	    o = bits[i].count();
	    z = m + 1 - o;
	    sol += (o*(o-1) )/ 2;
	    sol += (z*(z-1) )/ 2;
	    //cout <<"i:"<<i << bits[i] <<" , "<< o << " " << z << endl;
	    for(j = 0 ; j < i ; j++){
	        o = (bits[i]^bits[j]).count();
	        z = m + 1 - o;
	        sol += (o*(o-1)) / 2;
	        sol += (z*(z-1) )/ 2;
	        //cout << o << " " << z << endl;
	    }
	}
	cout << sol << "\n";   
	
	return 0;
} 