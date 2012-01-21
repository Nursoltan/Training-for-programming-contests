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

int main(){
	
	freopen("alphabet_soup.txt","r",stdin);
	freopen("alphabet_soup.out","w",stdout);
	
	int T,n,i,cases=1;
	char ch,s[1005],h[8]={'H','A','C','K','E','R','U','P'};
	cin>>T;
	
	ch=getchar();
	while(T--){
	  int a[26];
	  gets(s);
	  
	  n=strlen(s);
	  for(i=0; i<26; i++) a[i]=0;
	  for(i=0; i<n; i++) if(s[i]>='A' && s[i]<='Z') a[s[i]-'A']++;
	  
	  int ans=INT_MAX;
	  for(i=0; i<8; i++) ans=min(ans,a[h[i]-'A']);
	  ans=min(ans,a['C'-'A']/2);
	  
	  cout<<"Case #"<<cases++<<": "<<ans<<endl;
	}
	
	return 0;
}
