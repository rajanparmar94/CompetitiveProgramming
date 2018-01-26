#include <iostream>
#include <cstdio>
using namespace std;

void EE(int a, int b, int& x, int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
    cout<<"a:"<<a<<",b:"<<b<<",X:"<<x<<",Y:"<<y<<"\n";
}
int inverse(int a, int m)
{
    int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

int main() {
	// your code goes here
    cout<<inverse(9,14);
	return 0;
}
