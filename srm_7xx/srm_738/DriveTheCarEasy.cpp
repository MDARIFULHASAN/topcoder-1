// BEGIN CUT HERE
/*
SRM 738 Div2 Easy (250)

PROBLEM STATEMENT

You are driving a car along a long straight road.
Initially your car has the speed of 0 meters/second.
You are going to drive for S seconds.
We will number these seconds from 1 to S, inclusive.

You are given N pairs of integers (moments[i], speed_changes[i]).
Each such pair has the following meaning:
Immediately before second number moments[i] you will instantly increase the speed of your car by speed_changes[i] meters/second.

Compute and return the total distance the car will travel during those S seconds.


DEFINITION
Class:DriveTheCarEasy
Method:calculateDistance
Parameters:int, int, vector <int>, vector <int>
Returns:long long
Method signature:long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments)


CONSTRAINTS
-S will be between 1 and 109, inclusive.
-N will be between 1 and 100, inclusive.
-speed_changes and moments will have exactly N elements each.
-Each element of speed_changes will be between 1 and 1000, inclusive.
-Each element of moments will be between 1 and S, inclusive.


EXAMPLES

0)
1000
1
{1000}
{1}

Returns: 1000000

At the beginning (before second number 1) you increase the speed of your car from 0 m/s to 1000 m/s.
The car then moves at this speed for 1000 seconds, so it will travel 1,000,000 meters.


1)
5
5
{1, 2, 3, 4, 5}
{1, 2, 3, 4, 5}

Returns: 35

The speed during each second will be 1, 3, 6, 10 and 15 m/s respectively, so the answer is 1+3+6+10+15 = 35 meters.


2)
100
5
{1, 2, 3, 4, 5}
{100, 100, 100, 100, 100}

Returns: 15


Note that moments may contain the same value multiple times. If it does, each occurrence should be processed separately.

In this example your car stands still for 99 seconds.
Then, immediately before the second #100, five separate speedups occur.
In total, you increase the speed of your car by 1+2+3+4+5 = 15 m/s.
Thus, during second #100 the car will travel 15 meters.


3)
1000000000
3
{1000, 1000, 1000}
{3, 2, 1}

Returns: 2999999997000

Note that the elements of moments do not have to be sorted.
Watch out for integer overflow.


4)
100
10
{522,426,772,447,497,775,982,417,932,728}
{75,45,81,29,2,25,84,56,2,37}

Returns: 367474


5)
1000000000
100
{857,918,679,340,868,940,593,991,355,431,757,934,676,221,
 922,511,467,691,835,965,221,501,325,302,896,489,607,432,
 968,475,84,694,354,409,643,951,420,607,167,438,986,483,
 806,858,553,554,325,279,327,832,200,658,992,467,958,600,
 473,775,770,718,807,898,530,569,384,913,315,334,392,8,
 962,850,61,588,980,890,747,740,469,516,7,299,163,571,455,
 590,427,342,239,875,258,377,428,455,653,768,307,878,368,882}
{189330739,802329211,303238506,492686568,125660016,839296263,
 492601449,191890310,782177068,818008580,160449218,840594328,
 797829355,501899080,545531545,350034067,470338674,533206504,
 31262034,677959980,846045895,346948152,506147731,816248153,
 37119022,215208399,189766466,137831502,47628333,409233792,
 888987010,87027328,421624712,871216480,509928121,14723492,
 569328197,807497925,537560717,889089200,846216104,76823620,
 242790881,792345559,632488502,70422962,26697435,992120464,
 499482549,736386595,940778720,306890639,1849130,672298989,
 331602581,206347466,149811929,316412581,927999455,441504628,
 673419335,198091552,599715811,441414148,80656954,110880114,
 233703686,209550382,214278326,936333553,989214957,989248231,
 954621185,909664305,887357564,988670052,922390943,901347593,
 528977370,817020443,81469525,101430412,801006699,99958976,
 458482217,770179343,91883220,87104584,8454496,269122601,
 483571449,667480040,926138238,897273517,774034433,359911957,
 94576456,741452977,171601999,723473541}

Returns: 29493629905568

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class DriveTheCarEasy {
public:
	long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments) {
		long long ans = 0, speed = 0;
		moments.push_back(S + 1);
		for (int i = 1; i <= N; ++i) {
			speed += speed_changes[i - 1];
			ans += speed * (moments[i] - moments[i - 1]);
		}
		return ans;
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
			int Arg0 = 1000;
			int Arg1 = 1;
			int Arr2[] = {1000};
			int Arr3[] = {1};
			long long Arg4 = 1000000LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {1, 2, 3, 4, 5};
			int Arr3[] = {1, 2, 3, 4, 5};
			long long Arg4 = 35LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 5;
			int Arr2[] = {1, 2, 3, 4, 5};
			int Arr3[] = {100, 100, 100, 100, 100};
			long long Arg4 = 15LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 3;
			int Arr2[] = {1000, 1000, 1000};
			int Arr3[] = {3, 2, 1};
			long long Arg4 = 2999999997000LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 10;
			int Arr2[] = {522,426,772,447,497,775,982,417,932,728};
			int Arr3[] = {75,45,81,29,2,25,84,56,2,37};
			long long Arg4 = 367474LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 100;
			int Arr2[] = {857,918,679,340,868,940,593,991,355,431,757,934,676,221,
 922,511,467,691,835,965,221,501,325,302,896,489,607,432,
 968,475,84,694,354,409,643,951,420,607,167,438,986,483,
 806,858,553,554,325,279,327,832,200,658,992,467,958,600,
 473,775,770,718,807,898,530,569,384,913,315,334,392,8,
 962,850,61,588,980,890,747,740,469,516,7,299,163,571,455,
 590,427,342,239,875,258,377,428,455,653,768,307,878,368,882};
			int Arr3[] = {189330739,802329211,303238506,492686568,125660016,839296263,
 492601449,191890310,782177068,818008580,160449218,840594328,
 797829355,501899080,545531545,350034067,470338674,533206504,
 31262034,677959980,846045895,346948152,506147731,816248153,
 37119022,215208399,189766466,137831502,47628333,409233792,
 888987010,87027328,421624712,871216480,509928121,14723492,
 569328197,807497925,537560717,889089200,846216104,76823620,
 242790881,792345559,632488502,70422962,26697435,992120464,
 499482549,736386595,940778720,306890639,1849130,672298989,
 331602581,206347466,149811929,316412581,927999455,441504628,
 673419335,198091552,599715811,441414148,80656954,110880114,
 233703686,209550382,214278326,936333553,989214957,989248231,
 954621185,909664305,887357564,988670052,922390943,901347593,
 528977370,817020443,81469525,101430412,801006699,99958976,
 458482217,770179343,91883220,87104584,8454496,269122601,
 483571449,667480040,926138238,897273517,774034433,359911957,
 94576456,741452977,171601999,723473541};
			long long Arg4 = 29493629905568LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DriveTheCarEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
