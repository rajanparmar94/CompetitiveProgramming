#include <iostream>
#include <memory.h>
using namespace std;
typedef long int li;
#define N 1000000
li primes[N+1];

void pgen(){
	li i, j;
	memset(primes , 0 ,sizeof(primes));
	for(i = 2 ; i <= N ; i++){
		if(primes[i]==0){
			for(j = i*2 ; j <= N ; j+=i){
				primes[j] = i;
			}
		}
	}
}

int main()
{
    pgen();
    li n , tn, sol, pf;
    double ans;
    cin >> n;
    tn = n;
    ans = n;
    while ( tn != 1) {
    	if(primes[tn]!=0)
    		pf = primes[tn];
    	else
    		pf = tn;
    	ans *= (1.0 - 1.0/pf);
    	while(tn%pf == 0)
    		tn /= pf;
    }
    sol = ans;
    cout << sol << endl;
    return 0;
}
