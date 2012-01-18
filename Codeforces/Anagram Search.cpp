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

int main(){
	
	string s,p;
	int n,m,i,j;
	int x[30]={0};
	
	cin>>s>>p;
	
	n=s.size();
	m=p.size();
	
	for(i=0; i<m; i++) x[p[i]-'a']++;
	
	int ret=0;
	for(i=0; i+m-1<n; i++){
	  bool ok=1;
	  int a[30]={0};
	  for(j=i; j<i+m; j++) if(s[j]!='?') a[s[j]-'a']++;
	  
	  for(j=0; j<26; j++) if(a[j]>x[j]) ok=0;
	  if(ok) ret++;
	}
	
	cout<<ret<<endl;
	
	return 0;
}
