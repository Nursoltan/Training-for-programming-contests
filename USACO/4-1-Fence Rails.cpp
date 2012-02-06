/*
NAME: Nursoltan
LANG: C++
PROB: fence8
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

int N,M,waste,must,total;
int ind[1050],sum[1050];
int r[1050],b[1050];
int done;

void rec(int x, int k){
	int i;
	if(x==0){
	  for(i=k; i<N; i++) if(b[i]>=r[0]){
	    cout<<done+1<<endl;
	    exit(0);
	  } 
	}
	
	for(i=k; i<N; i++){
	  if(b[i]>=r[x]){
	    int old=waste;
	    b[i]-=r[x];
	    
	    if(b[i]<r[0] && waste+b[i]>must){
		  b[i]+=r[x];
		  continue;
		}
		
		if(b[i]<r[0]) waste+=b[i];
		
		if(r[x-1]==r[x]) rec(x-1,i);
		  else rec(x-1,ind[x-1]);
		
		b[i]+=r[x];
		waste=old;  
	  }
	}
}

int main(){

    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
	
	int i,j;
	cin>>N;
	for(i=0; i<N; i++) cin>>b[i],total+=b[i];
	cin>>M;
	for(i=0; i<M; i++) cin>>r[i];
	
	sort(b,b+N);
	sort(r,r+M);
	
	for(i=0; i<M; i++){
	  for(j=0; j<N && r[i]>b[j]; j++);
	  ind[i]=j;
	}
	
	sum[0]=r[0];
	for(i=1; i<M; i++){
	  sum[i]=sum[i-1]+r[i];
	  if(sum[i]>total){ 
		M=i;  
	    break; 
	  }
    }
    
    if(M==0){ cout<<0<<endl; return 0; }
    
	for(i=M-1; i>=0; i--){
	  done=i;
	  waste=0;
	  must=total-sum[i];
	  rec(i,ind[i]);
	}
	if(i==-1) cout<<0<<endl;
	
    return 0;
}
