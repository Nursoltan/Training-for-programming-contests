#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

#define MAX 10000005

long long com[1005][1005];
int mem[MAX+5];

int main(){
	
	freopen("1.out","w",stdout);
	
	int T,i,j,cases=1;
	cin>>T;
	
	for(i=0; i<MAX; i++) mem[i]=i;
	for(i=0; i<1000; i++) com[i][0]=com[0][i]=1;
	for(i=1; i<1000; i++) for(j=1; j<1000; j++){
	  com[i][j]=com[i-1][j]+com[i][j-1];
	  if(com[i][j]>0 && com[i][j]<10000000) mem[com[i][j]]=min(mem[com[i][j]],i+j);
	}
	
	//for(i=0; i<100; i++){
	//  cout<<i<<" "<<mem[i]<<endl;
	//}
	
	while(T--){
	  int N,ret;
	  cin>>N;
	  ret=N+1;
	  
	  for(i=1; i*i<=N; i++) if(N%i==0){
	    j=N/i;
	    ret=min(ret,mem[i]+mem[j]);
	  }
	  
	  cout<<"Case #"<<cases++<<": "<<ret<<endl;
	}
	
	return 0;
}
