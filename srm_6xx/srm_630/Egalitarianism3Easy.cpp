// BEGIN CUT HERE
/*
SRM 630 Div2 Medium (500)

PROBLEM STATEMENT
In Treeland there are n cities, numbered 1 through n.
The cities are linked by n-1 bidirectional roads.
Each road connects a pair of cities.
The roads are built in such a way that each city is reachable from each other city by roads.
(In other words, the topology of the road network is a tree.)

You are given the int n and three vector <int>s that describe the road network: a, b, and len.
For each i between 0 and n-2, inclusive, there is a road of length len[i] that connects the cities a[i] and b[i].

The distance between two cities is the sum of lengths of roads on the sequence of roads that connects them. (Note that this sequence of roads is always unique.)

You want to select k cities in such a way that all pairwise distances between the selected cities are the same.
In other words, there must be a distance d such that the distance between every two selected cities is d.
Return the largest possible value of k for which this is possible.


DEFINITION
Class:Egalitarianism3Easy
Method:maxCities
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-a will contain exactly n-1 elements.
-b will contain exactly n-1 elements.
-len will contain exactly n-1 elements.
-Each element in a will be between 1 and n, inclusive.
-Each element in b will be between 1 and n, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.
-The graph described by a and b will be a tree.


EXAMPLES

0)
4
{1,1,1}
{2,3,4}
{1,1,1}

Returns: 3

There are 4 cities and 3 roads, each of length 1.
The roads connect the following pairs of cities: (1,2), (1,3), and (1,4).
The optimal answer is k=3.
We can select three cities in the required way: we select the cities {2, 3, 4}.
The distance between any two of these cities is 2.


1)
6
{1,2,3,2,3}
{2,3,4,5,6}
{2,1,3,2,3}

Returns: 3

Again, the largest possible k is 3.
There are two ways to select three equidistant cities: {1, 4, 6} and {4, 5, 6}.
(In both cases the common distance is 6.)


2)
10
{1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10}
{1000,1000,1000,1000,1000,1000,1000,1000,1000}

Returns: 9


3)
2
{1}
{2}
{3}

Returns: 2


4)
1
{}
{}
{}

Returns: 1

Note that n can be 1.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef set<int> IntSet;

class Egalitarianism3Easy {
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		if (n <= 2) {
			return n;
		}
		int d[50][50];
		memset(d, 0x3f, sizeof(d));
		for (int i = 0; i < (int)a.size(); ++i) {
			d[a[i] - 1][b[i] - 1] = len[i];
			d[b[i] - 1][a[i] - 1] = len[i];
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int ans = 2;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int r = d[i][j];
				if (r < 1e6) {
					IntSet s;
					s.insert(i);
					s.insert(j);
					for (int k = 0; k < n; ++k) {
						if (i != k && j != k) {
							IntSet::const_iterator it;
							for (it = s.begin(); it != s.end(); ++it){
								if (d[k][*it] != r) {
									break;
								}
							}
							if (it == s.end()){
								s.insert(k);
							}
						}
					}
					ans = max(ans, (int)s.size());
				}
			}
		}

		return ans;
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
			int Arg0 = 4;
			int Arr1[] = {1,1,1};
			int Arr2[] = {2,3,4};
			int Arr3[] = {1,1,1};
			int Arg4 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1,2,3,2,3};
			int Arr2[] = {2,3,4,5,6};
			int Arr3[] = {2,1,3,2,3};
			int Arg4 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {1,1,1,1,1,1,1,1,1};
			int Arr2[] = {2,3,4,5,6,7,8,9,10};
			int Arr3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg4 = 9;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1};
			int Arr2[] = {2};
			int Arr3[] = {3};
			int Arg4 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			// int Arr1[] = {};
			// int Arr2[] = {};
			// int Arr3[] = {};
			int Arg4 = 1;

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3;
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Egalitarianism3Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
