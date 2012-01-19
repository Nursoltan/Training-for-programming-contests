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

string s,p;
int n,m,i,j;
int x[30],a[30];

int main(){
	
	cin>>s>>p;
	
	n=s.size();
	m=p.size();
	
	for(i=0; i<m; i++) x[p[i]-'a']++;
	
	int ret=0;
	for(i=0; i+m-1<n; i++){
	  bool ok=1;
	  
	  if(i==0){
	    for(j=i; j<i+m; j++) if(s[j]!='?') a[s[j]-'a']++;
	  }
	  else{
	    if(s[i-1]!='?') a[s[i-1]-'a']--;
	    if(s[i+m-1]!='?') a[s[i+m-1]-'a']++;  
	  }
	  
	  for(j=0; j<26; j++) if(a[j]>x[j]) ok=0;
	  if(ok) ret++;
	}
	
	cout<<ret<<endl;
	
	return 0;
}
