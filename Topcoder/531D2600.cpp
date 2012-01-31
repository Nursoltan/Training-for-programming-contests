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

class NoRepeatPlaylist {
public:
   int numPlaylists( int N, int M, int P ){
	   int i,j;
	   long long dp[105][105];
	   int mod=1000000007;
	   memset(dp,0,sizeof(dp));
	   
	   dp[0][0]=1;
	   for(i=1; i<=P; i++) for(j=1; j<=N; j++){
	     dp[i][j]=dp[i-1][j-1];
	     if(j-M>0) dp[i][j]=(dp[i-1][j-1]+(dp[i-1][j]*(long long)(j-M))%mod)%mod;
	   }
	   long long ret=dp[P][N];
	   for(i=2; i<=N; i++) ret=(ret*(long long)i)%mod;
	   
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
			int N                     = 1;
			int M                     = 0;
			int P                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1;
			int M                     = 1;
			int P                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int M                     = 0;
			int P                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 4;
			int M                     = 0;
			int P                     = 4;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 2;
			int M                     = 1;
			int P                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 50;
			int M                     = 5;
			int P                     = 100;
			int expected__            = 222288991;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists(N, M, P);
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
