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

#define pb push_back
#define mp make_pair
#define px first
#define py second

int parent[100];
int rank[100];

int Find(int x){
	if(parent[x]==x) return x;
	  else{
	    parent[x]=Find(parent[x]);
	    return parent[x];
	  }
}

void Union(int x, int y){
	if(rank[x]>rank[y]){
	  parent[y]=x;
	  rank[x]+=rank[y];
	}
	else{
	  parent[x]=parent[y];
	  rank[y]+=rank[x];
	}
}

int func(char ch){
	if(ch>='A' && ch<='Z') return ch-'A';
	  else return ch-'a'+26;
}

class KingdomReorganization {
public:
   int getCost( vector <string> a, vector <string> b, vector <string> c ){
	   int N,ret=0;
	   memset(parent,0,sizeof(parent));
	   memset(rank,0,sizeof(rank));
	   N=a.size();
	   
	   vector<pair<int,pair<int,int> > > edge;
	   
	   int i,j;
	   for(i=0; i<N; i++) for(j=i+1; j<N; j++){
	     if(a[i][j]=='1'){
	       edge.pb(mp(-func(c[i][j]),mp(i,j)));
	     }
	     else{
		   edge.pb(mp(func(b[i][j]),mp(i,j)));	 
		 }
	   }
	   sort(edge.begin(),edge.end());
	   int E=edge.size();
	   
	   for(i=0; i<100; i++) parent[i]=i,rank[i]=0;
	   
	   int cnt=0;
	   for(i=0; i<E && cnt<N; i++){
	     int p1,p2;
	     p1=Find(edge[i].py.px);
	     p2=Find(edge[i].py.py);
	     
	     if(p1!=p2){
		   Union(p1,p2);
		   cnt++;
		   ret+=max(0,edge[i].px);
		 }
		 else ret+=-min(0,edge[i].px);
	   }
	   
	   return ret;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string kingdom[]          = {"000","000","000"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string kingdom[]          = {"011","101","110"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string kingdom[]          = {"011000","101000","110000","000011","000101","000110"};
			string build[]            = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			string destroy[]          = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string kingdom[]          = {"0"};
			string build[]            = {"A"};
			string destroy[]          = {"A"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string kingdom[]          = {"0001","0001","0001","1110"};
			string build[]            = {"AfOj","fAcC","OcAP","jCPA"};
			string destroy[]          = {"AWFH","WAxU","FxAV","HUVA"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string kingdom[]          = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
			string build[]            = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
			string destroy[]          = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
    return 0;	
}

// END CUT HERE
