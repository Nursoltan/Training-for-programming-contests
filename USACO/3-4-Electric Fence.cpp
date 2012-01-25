/*
NAME: Nursoltan
LANG: C++
PROB: fence9
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

int gcd(int x, int y){
	while(x!=0 && y!=0){
	  if(x>y) x=x%y;
	    else y=y%x;
	}
	return x+y;
}

int __abs(int x){
	return ((x<0)?-x:x);
}

int main(){

    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
	
	int n,m,p;
	int A,I,B; // Pick's theorom : A=I+B/2-1
	
	/*
	 * num of lattice points line segment
	 * (x1,y1)->(x2,y2)
	 * #oflinesegment=gcd(|x1-x2|,|y1-y2|)+1
	 */
	
	cin>>n>>m>>p;
	
	A=m*p/2;
	B=gcd(n,m)+gcd(__abs(p-n),m)+p; 
	I=A-B/2+1;
	
	cout<<I<<endl;
	
    return 0;
}
