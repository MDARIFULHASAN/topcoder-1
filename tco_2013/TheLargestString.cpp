// BEGIN CUT HERE

/*
TCO 2013 Round 2A Easy (300)

PROBLEM STATEMENT
John has two strings s and t of equal length.
He can choose a set of positions (possibly empty) and erase characters at these positions in both s and t.
Then he writes down the concatenation of what remained of the strings:
first the letters we kept from s, in their original order, then the letters we kept from t, again in their original order.

Return the lexicographically largest string John can get at the end.


DEFINITION
Class:TheLargestString
Method:find
Parameters:string, string
Returns:string
Method signature:string find(string s, string t)


NOTES
-String A is lexicographically smaller than string B if either A is a proper prefix of B,
 or if there is an integer i such that the first i characters of A match the first i characters of B,
 and character i+1 of A is smaller than character i+1 of B.


CONSTRAINTS
-s will contain between 1 and 47 characters, inclusive.
-s and t will contain the same number of characters.
-s will contain only lowercase English characters ('a'-'z').
-t will contain only lowercase English characters ('a'-'z').


EXAMPLES

0)
"ab"
"zy"

Returns: "by"

There are four options here:

Do not erase anything. The resulting string would be "abzy".
Erase both first characters. The resulting string would be "by".
Erase both last characters. The resulting string would be "az".
Erase all characters. The resulting string would be empty.

Among all possible results "by" is the lexicographically largest one.


1)
"abacaba"
"zzzaaaa"

Returns: "cbaaaa"


2)
"x"
"x"

Returns: "xx"


3)
"abbabbabbababaaaabbababab"
"bababbaabbbababbbbababaab"

Returns: "bbbbbbbbbbbbbbbbbbaaab"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct StringPair {
	string first;
	string second;
	StringPair() { }
	StringPair(string f, string s) : first(f), second(s) { }
	bool operator < (const StringPair &s) const {
		return first + second < s.first + s.second;
	}
};

class TheLargestString {

public:
	string find(string s, string t) {
		int sz = (int)s.length();
		StringPair dp[51][51];
		StringPair ans;
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			StringPair x(s.substr(i, 1), t.substr(i, 1));
			dp[1][i] = x;
			for (j = 0; j <= i; ++j) {
				for (k = 0; k < i; ++k) {
					dp[j+1][i] = max(dp[j+1][i], StringPair(dp[j][k].first + x.first, dp[j][k].second + x.second));
				}
				ans = max(ans, dp[j+1][i]);
			}
		}
		return ans.first + ans.second;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ab";
			string Arg1 = "zy";
			string Arg2 = "by";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			string Arg1 = "zzzaaaa";
			string Arg2 = "cbaaaa";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			string Arg1 = "x";
			string Arg2 = "xx";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abbabbabbababaaaabbababab";
			string Arg1 = "bababbaabbbababbbbababaab";
			string Arg2 = "bbbbbbbbbbbbbbbbbbaaab";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


		// test_case 20
		if ((Case == -1) || (Case == n)){
			string Arg0 = "yxyxyxxyxxyxxyyxyxyxyyyxyyxyyxyyyxyxxyyyyyyxxyx";
			string Arg1 = "xxxxxxxxyxyxxxyyxyyxxxxxxyxxyxyyxxxyyyyyxxxyxyx";
			string Arg2 = "yyyyyyyyyyyyyyyyyyyyyyyyyyyxxxxyxyxyxxxxyxyyyxxyyyxxxy";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheLargestString ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
