/*
NAME: Nursoltan
LANG: C++
PROB: nuggets
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
	while(x>0 && y>0){
	  if(x>y) x%=y;
	    else y%=x;  
	}
	return x+y;
}

int a[20];
int N,s[65536+5];

int main(){

    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
	
	int i,j;
	
	cin>>N;
	for(i=0; i<N; i++) cin>>a[i];
	
	int g=a[0];
	for(i=1; i<N; i++) g=gcd(g,a[i]);
	
	if(g!=1){
	  cout<<0<<endl;
	  return 0;
	}
	
	int ret=0;
	s[0]=1;
	for(i=1; i<=65536; i++){
	  for(j=0; j<N; j++) if(i-a[j]>=0) s[i]=(s[i]|s[i-a[j]]);
	  if(!s[i]) ret=max(ret,i);
	}
	
	//for(i=0; i<20; i++) cout<<i<<" "<<s[i]<<endl;
	
	cout<<ret<<endl;
	
    return 0;
}
