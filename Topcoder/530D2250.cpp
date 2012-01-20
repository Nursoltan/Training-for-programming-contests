#include <algorithm>
#include <climits>
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
 
class GogoXBallsAndBinsEasy {
public:
   int solve( vector <int> T ){
     int N=T.size(),ret=0,i;
     vector<int> S=T;
 
     do{
       vector<int> x=T;
       for(i=0; i<N; i++) x[i]=abs(T[i]-S[i]);
       int sum=0;
       sort(x.begin(),x.end());
       for(i=0; i<N; i++) sum+=x[i];
       ret=max(ret,sum/2);
     }while(next_permutation(S.begin(),S.end()));
     
     return ret;
   }
};
