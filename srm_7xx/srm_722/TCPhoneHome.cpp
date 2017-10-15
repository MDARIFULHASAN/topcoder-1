// BEGIN CUT HERE
/*
SRM 722 Div1 Easy (250)

問題
-電話番号は、ある桁数の数字からなる
-いくつかの特定の数字からはじまるブリフィックスは、特別な用途に予約されている
-桁数とブリフィックスが与えられるので、普通の番号に使える総数を求めよ

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

class TCPhoneHome {

public:
	long long validNumbers(int digits, vector <string> specialPrefixes) {
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

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			string Arr1[] = {"0", "1", "911"};
			long long Arg2 = 7990000LL;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			string Arr1[] = {"0", "1", "911"};
			long long Arg2 = 7990000000LL;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			string Arr1[] = {"1", "12", "123"};
			long long Arg2 = 90000000LL;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			string Arr1[] = {"12", "13", "14"};
			long long Arg2 = 970000000LL;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"411"};
			long long Arg2 = 999LL;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validNumbers(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TCPhoneHome ___test;
	___test.run_test(-1);
}
// END CUT HERE
