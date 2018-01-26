/**
*
*	By	:	Rajan Parmar
*	link:	https://www.codechef.com/AUG16/problems/CHAHG/
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <set>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <stack> 
 
using namespace std;
 
#define N 100000
#define MAX 1000000007
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
 
ll h[11], m[11];
ll p1start[11] , p2start[11] , p1end[11], p2end[11];
int main() {
    
    int t, n, i, j;
    ll s1, s2, e1, e2, diff, nd;
    
    cin >> t;
    
    while(t--)  {
        
        cin >> n;
        
        for(i = 0 ; i < n ; i++ )
            cin >> h[i] >> m[i];
            
        int f = 1;
        
        memset(p1start , -1, sizeof(p1start));
        memset(p1end , -1, sizeof(p1end));
        memset(p2start , -1, sizeof(p2start));
        memset(p2start , -1, sizeof(p2start));
        
        
        if(n == 1)
        {
            cout << "1\n";
            cout << "0 Inf\n";
            continue;
        }
        
        
        for( i = 0 ; i < n - 1 ; i++ )  {
            
            if(f)   {
                
                if(h[i] < h[i+1])   {
                    
                    diff = h[i + 1] - h[i];
                    ll p = 0;
                    int foo = 0;
                    while((h[i] + m[i] * p) < (h[i + 1] + m[i + 1] * p))    {
                        p++;
                        nd = (h[i + 1] + m[i + 1] * p) - (h[i] + m[i] * p);
                        
                        if(nd >= diff){
                            foo = 1;
                            break;
                        }
                        diff = nd;
                        
                        break;
                    }
                    
                    if(foo) {
                        
                        p1start[i] = 0;
                        p1end[i] = MAX;
                        p2start[i] = -1;
                        p2end[i] = -1;
                    }
                    else    {
                        
                        p = (ll)ceil(( 1.0 * ( h[i + 1] - h[i] )) / (m[i] - m[i + 1]) );
                        
                        p1start[i] = 0;
                        p1end[i] = max(p - 1, 0LL);
                        p2start[i] = p ;
                        p2end[i] = MAX;
                        
                        if((h[i] + m[i] * p) == (h[i + 1] + m[i + 1] * p))  {
                            //cout << "here p:" << p << "\n";
                            p1start[i] = 0;
                            p1end[i] = max(p - 1, 0LL);
                            p2start[i] = p + 1;
                            p2end[i] = MAX;
                        }
                        
                    }
                    
                }
                else    {
                    
                    if(h[i] > h[i+1])   {
                    
                    diff = h[i] - h[i + 1] ;
                    ll p = 0;
                    int foo = 0;
                    while((h[i] + m[i] * p) > (h[i + 1] + m[i + 1] * p))    {
                        p++;
                        nd = (h[i] + m[i] * p) - (h[i + 1] + m[i + 1] * p) ;
                        
                        if(nd >= diff){
                            foo = 1;
                            break;
                        }
                        diff = nd;
                        break;
                    }
                    
                    if(foo) {
                        
                        p1start[i] = -1;
                        p1end[i] = -1;
                        p2start[i] = 0;
                        p2end[i] = MAX;
                    }
                    else    {
                        
                        p = (ll)ceil(( 1.0 * ( h[i + 1] - h[i] )) / (m[i] - m[i + 1]) );
                        
                        p2start[i] = 0;
                        p2end[i] = max(p - 1, 0LL);
                        p1start[i] = p ;
                        p1end[i] = MAX;
                        
                        if((h[i] + m[i] * p) == (h[i + 1] + m[i + 1] * p))  {
                            
                            p2start[i] = 0;
                            p2end[i] = max(p - 1, 0LL);
                            p1start[i] = p + 1;
                            p1end[i] = MAX;
                        }
                        
                    }
                    
                }
                
                else    {
                    
                        //equal height
                        if(m[i] == m[i+1])  {
                            
                            p2start[i] = -1;
                            p2end[i] = -1;
                            p1start[i] = -1;
                            p1end[i] = -1;
                        }
                        
                        if(m[i] < m[i+1])  {
                            
                            p2start[i] = -1;
                            p2end[i] = -1;
                            p1start[i] = 1;
                            p1end[i] = MAX;
                        }
                        
                        if(m[i] > m[i+1])  {
                            
                            p1start[i] = -1;
                            p1end[i] = -1;
                            p2start[i] = 1;
                            p2end[i] = MAX;
                        }
                        
                        
                }
                    
                }
                
            }// if(f) i.e. xor
            else    {
                
                    if(h[i] < h[i+1])   {
                    
                    diff = h[i + 1] - h[i];
                    ll p = 0;
                    int foo = 0;
                    while((h[i] + m[i] * p) < (h[i + 1] + m[i + 1] * p))    {
                        p++;
                        nd = (h[i + 1] + m[i + 1] * p) - (h[i] + m[i] * p);
                        
                        if(nd >= diff){
                            foo = 1;
                            break;
                        }
                        diff = nd;
                        break;
                    }
                    
                    if(foo) {
                        
                        p2start[i] = 0;
                        p2end[i] = MAX;
                        p1start[i] = -1;
                        p1end[i] = -1;
                    }
                    else    {
                        
                        p = (ll)ceil(( 1.0 * ( h[i + 1] - h[i] )) / (m[i] - m[i + 1]) );
                        
                        p2start[i] = 0;
                        p2end[i] = max(p - 1, 0LL);
                        p1start[i] = p ;
                        p1end[i] = MAX;
                        
                        if((h[i] + m[i] * p) == (h[i + 1] + m[i + 1] * p))  {
                            
                            p2start[i] = 0;
                            p2end[i] = max(p - 1, 0LL);
                            p1start[i] = p + 1;
                            p1end[i] = MAX;
                        }
                        
                    }
                    
                }
                else    {
                    
                    if(h[i] > h[i+1])   {
                    
                    diff = h[i] - h[i + 1] ;
                    ll p = 0;
                    int foo = 0;
                    while((h[i] + m[i] * p) > (h[i + 1] + m[i + 1] * p))    {
                        p++;
                        nd = (h[i] + m[i] * p) - (h[i + 1] + m[i + 1] * p) ;
                        
                        if(nd >= diff){
                            foo = 1;
                            break;
                        }
                        diff = nd;
                        
                        break;
                    }
                    
                    if(foo) {
                        
                        p2start[i] = -1;
                        p2end[i] = -1;
                        p1start[i] = 0;
                        p1end[i] = MAX;
                    }
                    else    {
                        
                        p = (ll)ceil(( 1.0 * ( h[i + 1] - h[i] )) / (m[i] - m[i + 1]) );
                        
                        p1start[i] = 0;
                        p1end[i] = max(p - 1, 0LL);
                        p2start[i] = p ;
                        p2end[i] = MAX;
                        
                        
                        if((h[i] + m[i] * p) == (h[i + 1] + m[i + 1] * p))  {
                            //cout << "S Here P:" << p << "\n";
                            p1start[i] = 0;
                            p1end[i] = max(p - 1, 0LL);
                            p2start[i] = p + 1;
                            p2end[i] = MAX;
                        }
                        
                    }
                    
                }
                
                else    {
                    
                        //equal height
                        if(m[i] == m[i+1])  {
                            
                            p2start[i] = -1;
                            p2end[i] = -1;
                            p1start[i] = -1;
                            p1end[i] = -1;
                        }
                        
                        if(m[i] < m[i+1])  {
                            
                            p1start[i] = -1;
                            p1end[i] = -1;
                            p2start[i] = 1;
                            p2end[i] = MAX;
                        }
                        
                        if(m[i] > m[i+1])  {
                            
                            p2start[i] = -1;
                            p2end[i] = -1;
                            p1start[i] = 1;
                            p1end[i] = MAX;
                        }
                        
                        
                }
                    
                }
                
            } // end of else xor
            
            f ^= 1;
        }
        
        int cnt = 2;
        
        s1 = s2 = -1 ;
        e1 = e2 = MAX + 7;
        
        for(i = 0 ; i < n-1 ; i++)  {
            
            s1 = max(s1, p1start[i]);
            s2 = max(s2, p2start[i]);
            e1 = min(e1, p1end[i]);
            e2 = min(e2, p2end[i]);
            
        }
        
        if(s1 == -1 || e1 == -1 || e1 < s1)
            cnt--;
            
        if(s2 == -1 || e2 == -1 || e2 < s2)
            cnt--;   
            
        //cout << cnt << "\n";
        
        if(cnt == 2)    {
            
            if(s1 < s2){
                
                if(s2 == e1 + 1)
                    cout <<"1\n"<< s1 << " Inf" << "\n";
                else{
                    cout << cnt << "\n";
                    if(e1 == MAX)
                        cout << s1 <<" Inf" << "\n";
                    else
                        cout << s1 <<" " << e1 << "\n";
                        
                    if(e2 == MAX)
                        cout << s2 <<" Inf" << "\n";
                    else
                        cout << s2 <<" " << e2 << "\n";
                    }
            }
            else{
                
                if(s1 == e2 + 1)
                    cout << "1\n" << s2 << " Inf" << "\n";
                else{
                        cout << cnt << "\n";
                        if(e2 == MAX)
                            cout << s2 <<" Inf" << "\n";
                        else
                            cout << s2 <<" " << e2 << "\n";
                            
                        if(e1 == MAX)
                            cout << s1 <<" Inf" << "\n";
                        else
                            cout << s1 <<" " << e1 << "\n";
                }
            }
        }
        else    {
            if( cnt == 1 )  {
                
                cout << cnt << "\n";
                
                if(s1 == -1 || e1 == -1 || e1 < s1){
                    if(e2 == MAX)
                    cout << s2 <<" Inf" << "\n";
                else
                    cout << s2 <<" " << e2 << "\n";
                }
                else{
                    if(e1 == MAX)
                    cout << s1 <<" Inf" << "\n";
                else
                    cout << s1 <<" " << e1 << "\n";
                }
                
            }
            else
                cout << cnt << "\n";
        }
        
    }
	
	return 0;
}