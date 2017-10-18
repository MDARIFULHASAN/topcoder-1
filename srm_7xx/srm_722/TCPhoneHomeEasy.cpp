// BEGIN CUT HERE
/*
SRM 722 Div2 Medium (400)

PROBLEM STATEMENT
Typically, telephone numbers are sequences of digits (0-9) that all have the same length.
However, some prefixes may be reserved for special purposes.
This limits the total number of possible full-length telephone numbers that are available for general use in the system.

As an example, in much of the United States and Canada the local telephone numbers are 7 digits long.
However, dialing 1 starts a special sequence for long distance, dialing 0 connects to the operator, and dialing 911 connects to emergency services.
Thus, there are fewer than the theoretical 10,000,000 possible valid telephone numbers.

You are given the int digits: the length of the standard telephone numbers in the system.
You are also given a vector <string> specialPrefixes.
Each element of specialPrefixes is a string of digits that defines one reserved prefix.
Standard telephone numbers cannot start with any of the reserved prefixes.

Compute and return the number of different standard telephone numbers in the system.


DEFINITION
Class:TCPhoneHomeEasy
Method:validNumbers
Parameters:int, vector <string>
Returns:int
Method signature:int validNumbers(int digits, vector <string> specialPrefixes)


CONSTRAINTS
-digits will be between 1 and 7, inclusive.
-specialPrefixes will contain beteween 0 and 50 elements, inclusive.
-The length of each element of specialPrefixes will be between 1 and digits, inclusive.
-Each character of each element of specialPrefixes will be a digit ('0'...'9').
-No element of specialPrefixes will itself be a prefix of another element.


EXAMPLES

0)
7
{ "0", "1", "911" }

Returns: 7990000

This is the example from the problem statement.


1)
5
{ "0", "1", "911" }

Returns: 79900

Same prefixes, but with shorter phone numbers.


2)
6
{ "1", "2", "3" }

Returns: 700000


3)
6
{ "1", "23", "345" }

Returns: 889000


4)
3
{"411"}

Returns: 999

Sometimes a special "prefix" is actually a full length phone number.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

long long pow10(int digits) {
	long long n = 1;
	for (int i = 0; i < digits; ++i) {
		n *= 10;
	}
	return n;
}

class TCPhoneHomeEasy {
public:
	int validNumbers(int digits, vector <string> specialPrefixes) {
		long long d = pow10(digits);
		for (int i = 0; i < (int)specialPrefixes.size(); ++i) {
			string s = specialPrefixes[i];
			bool valid = true;
			for (int j = 0; j < (int)specialPrefixes.size(); ++j) {
				if (i != j &&
					specialPrefixes[j].length() < s.length() &&
					specialPrefixes[j] == s.substr(0, specialPrefixes[j].length())) {
					valid = false;
				}
			}
			if (valid) {
				d -= pow10(digits - (int)s.length());
			}
		}
		return d;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			string Arr1[] = { "0", "1", "911" };
			int Arg2 = 7990000;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arr1[] = { "0", "1", "911" };
			int Arg2 = 79900;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			string Arr1[] = { "1", "2", "3" };
			int Arg2 = 700000;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			string Arr1[] = { "1", "23", "345" };
			int Arg2 = 889000;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"411"};
			int Arg2 = 999;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TCPhoneHomeEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
