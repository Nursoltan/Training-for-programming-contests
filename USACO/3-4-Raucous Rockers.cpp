/*
NAME: Nursoltan
LANG: C++
PROB: rockers
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

int N,M,T,ret,i,j,k,l;
int dp[25][25][25],a[25];

int main(){

    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
	
	cin>>N>>T>>M;
	for(i=1; i<=N; i++) cin>>a[i];
	
	for(i=0; i<M; i++)
	  for(j=0; j<=T; j++)
	    for(k=0; k<=N; k++){
		  for(l=k+1; l<=N; l++)
		    if(j+a[l]<=T)
		      dp[i][j+a[l]][l]=max(dp[i][j+a[l]][l],dp[i][j][k]+1);
		    else
		      dp[i+1][a[l]][l]=max(dp[i+1][a[l]][l],dp[i][j][k]+1);
		 
		 ret=max(ret,dp[i][j][k]); 
		}
	
	cout<<ret<<endl;
	
    return 0;
}
