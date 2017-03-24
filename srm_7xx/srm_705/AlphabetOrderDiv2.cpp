// BEGIN CUT HERE
/*
SRM 705 Div2 Medium (500)

PROBLEM STATEMENT
The ancient civilization of Nlogonia used the same 26 letters as modern English: 'a'-'z'.
However, we do not know the order in which these letters appeared in the Nlogonian alphabet.

One particular custom in Nlogonia was that in a good word the letters appear in non-decreasing order.
For example, in English the word "ciel" is not a good word because in the alphabet 'i' is after 'e'.
The word "ceil" is a good word because 'c' <= 'e' <= 'i' <= 'l'.

You are given the vector <string> words.
Each element of words is a nonempty string of lowercase English letters.
Return "Possible" if it is possible that all elements of words were good words in Nlogonian, and "Impossible" otherwise.

In other words, return "Possible" if and only if there is at least one possible Nlogonian alphabet such that the letters of each word in words are in non-decreasing alphabetical order.


DEFINITION
Class:AlphabetOrderDiv2
Method:isOrdered
Parameters:vector <string>
Returns:string
Method signature:string isOrdered(vector <string> words)


CONSTRAINTS
-words has between 2 and 100 elements inclusive.
-The size of each element of words will be between 1 and 100 inclusive.
-Elements of words contains only English lowercase letters from 'a' to 'z'.


EXAMPLES

0)
{"single","round","match"}

Returns: "Possible"

One possible Nlogonian alphabet is "bfjkmapqrositchundglevwxyz".


1)
{"topcoder","topcoder"}

Returns: "Impossible"

The word "topcoder" can never be a good word.
The character 'o' cannot be both before 'p' and after 'p' in the alphabet.


2)
{"algorithm", "contest"}

Returns: "Impossible"


3)
{"pink","floyd"}

Returns: "Possible"


4)
{"gimnasia","y","esgrima","la","plata"}

Returns: "Impossible"


5)
{"hello","hello"}

Returns: "Possible"

This is a good word for any alphabet in which the letters 'h', 'e', 'l', and 'o' appear in this order.


6)
{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}

Returns: "Possible"

In this case the English alphabet is one of the valid permutations.


7)
{"abc","bca"}

Returns: "Impossible"

'a' must come before 'c' (because of the first name) and after 'c' (because of the second name) and that is a contradiction. Thus, there is no valid solution.


8)
{"aaaaa","eeeee","iiiii","ooooo","uuuuu"} 

Returns: "Possible"

Any order is valid in this case


9)
{"ab","bc","ca"}

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AlphabetOrderDiv2 {
public:
	string isOrdered(vector <string> words) {
		int d[26][26] = {};
		for (int i = 0; i != words.size(); ++i) {
			for (int j = 1; j != words[i].length(); ++j) {
				if (words[i][j - 1] != words[i][j]) {
					d[words[i][j - 1] - 'a'][words[i][j] - 'a'] = 1;
				}
			}
		}
		for (int k = 0; k < 26; ++k) {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < 26; ++j) {
					if (d[i][k] && d[k][j]) {
						d[i][j] = 1;
					}
				}
			}
		}
		for (int i = 0; i < 26; ++i) {
			if (d[i][i]) {
				return "Impossible";
			}
		}
		return "Possible";
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
			string Arr0[] = {"single","round","match"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder","topcoder"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"algorithm", "contest"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"pink","floyd"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"gimnasia","y","esgrima","la","plata"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"hello","hello"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abc","bca"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaaaa","eeeee","iiiii","ooooo","uuuuu"} ;
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_9
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab","bc","ca"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlphabetOrderDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE