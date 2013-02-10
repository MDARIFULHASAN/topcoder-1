
//
// B. Security
//

/*

You are designing a new encryption system that works in the following way:

For server-client communication you need a key k, composed of m sections,
each of length l, and the key consists only of lowercase characters in the set {a, b, c, d, e, f}.
The server has a key k1 and the client has a key k2 where:

k1 = f(k). f is a function that receives a key and replace some random letters by ? indicating
that those characters can be any lowercase letter of the set described before.
k2 = f(g(k)). g is a function that takes a key and produces a random permutation of its m sections.
And f is the function defined above.
For example: let m = 3, l = 2

f('abacbc') = '?ba??c'
g('abacbc') = 'acbcab' (each section was moved one place to the left).
Your task is given k1 and k2, find key k. If there are several solutions, print the lexicographically smallest key.
And if there is no solution at all, print "IMPOSSIBLE" (without the quotes).

Input description:
The first line has a single integer T, which corresponds to the number of test cases.
T test cases follows: the first line of the test case corresponds to the integer m,
the second line contains the string k1 and the third line contains the string k2.

Constraints:
T <= 20
0 < |k1| <= 100
0 < m <= 50
|k2| = |k1|
It is guaranteed that m is always a divisor of |k1|
k1 and k2 consist of {a, b, c, d, e, f, ?}
Output description:
For test case i, numbered from 1 to T, output "Case #i: ", followed by the lexicographically smallest key or "IMPOSSIBLE".

Example input
5
2
abcd
c?ab
3
ab?c?c
ac?c??
3
ab?c?c
aabbdd
2
aa
bb
2
abcd
cdab

Example output
Case #1: abcd
Case #2: abacac
Case #3: IMPOSSIBLE
Case #4: IMPOSSIBLE
Case #5: abcd

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef vector<string> StrVec;

IntVec G[200];
int matched[200];
bool used[200];

void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v) {
	used[v] = true;
	int i;
	for (i = 0; i < (int)G[v].size(); ++i) {
		int u = G[v][i];
		int w = matched[u];
		if (w < 0 || !used[w] && dfs(w)) {
			matched[v] = u;
			matched[u] = v;
			return true;
		}
	}
	return false;
}

bool match(StrVec a, StrVec b)
{
	int i, j, k;

	for (i = 0; i < 200; ++i) {
		G[i].clear();
	}
	memset(matched, -1, sizeof(matched));

	int m = (int)a.size();
	int length = (int)a[0].length();
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			for (k = 0; k < length; ++k) {
				char p = a[i][k], q = b[j][k];
				if (p != q && p != '?' && q != '?') {
					break;
				}
			}
			if (k >= length) {
				add_edge(i, 100+j);
			}
		}
	}

	for (i = 0; i < m; ++i) {
		if (matched[i] < 0) {
			memset(used, 0, sizeof(used));
			if (!dfs(i)) {
				return false;
			}
		}
	}

	return true;
}

string solve(StrVec a, StrVec b)
{
	int i, j, k;
	int m = (int)a.size();
	int length = (int)a[0].length();
	for (i = 0; i < m; ++i) {
		for (j = 0; j < length; ++j) {
			if (a[i][j] == '?') {
				bool f;
				for (k = 'a'; k <= 'f'; ++k) {
					a[i][j] = k;
					f = match(a, b);
					if (f) {
						break;
					}
				}
				if (!f) {
					return "";
				}
			}
		}
	}

	if (!match(a, b)) {
		return "";
	}

	string ans;
	for (i = 0; i < m; ++i) {
		ans += a[i];
	}
	return ans;
}

StrVec split(int m, string s)
{
	StrVec v;
	int length = (int)s.length() / m;
	int i;
	for (i = 0; i < m; ++i) {
		v.push_back(s.substr(i * length, length));
	}
	return v;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		int m = atoi(s.c_str());
		string a, b;
		getline(cin, a);
		getline(cin, b);
		string ans = solve(split(m, a), split(m, b));
		if (ans.empty()) {
			ans = "IMPOSSIBLE";
		}
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

