/*
NAME: Nursoltan
LANG: C++
PROB: heritage
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

string in,pre;
int N,cnt;

void rec(int x, int y){
	int i;
	if(x<=y){
  	  for(i=x; i<=y; i++) if(in[i]==pre[cnt]){
	    cnt++; 
	    rec(x,i-1); // left subtree
	    rec(i+1,y); // right subtree
	    cout<<in[i];
	  }
    }
}

int main(){

    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
	
	cin>>in>>pre;
	N=in.size();
	cnt=0;
	rec(0,N-1);
	cout<<endl;
	
    return 0;
}
