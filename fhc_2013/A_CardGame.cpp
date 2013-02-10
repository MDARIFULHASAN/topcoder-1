
//
// A. Card Game
//

/*

John is playing a game with his friends.
The game's rules are as follows: There is deck of N cards from which each person is dealt a hand of K cards.
Each card has an integer value representing its strength.
A hand's strength is determined by the value of the highest card in the hand.
The person with the strongest hand wins the round.
Bets are placed before each player reveals the strength of their hand.

John needs your help to decide when to bet.
He decides he wants to bet when the strength of his hand is higher than the average hand strength.
Hence John wants to calculate the average strength of ALL possible sets of hands.
John is very good at division, but he needs your help in calculating the sum of the strengths of all possible hands.

Problem
You are given an array a with N ≤ 10 000 different integer numbers and a number, K, where 1 ≤ K ≤ N. For all possible subsets of a of size K find the sum of their maximal elements modulo 1 000 000 007.

Input
The first line contains the number of test cases T.

Each case begins with a line containing integers N and K. The next line contains N space-separated numbers 0 ≤ a [i] ≤ 2 000 000 000, which describe the array a.

Output
For test case i, numbered from 1 to T, output "Case #i: ", followed by a single integer, the sum of maximal elements for all subsets of size K modulo 1 000 000 007.

Example
For a = [3, 6, 2, 8] and N = 4 and K = 3, the maximal numbers among all triples are 6, 8, 8, 8 and the sum is 30.

Example input
5
4 3
3 6 2 8 
5 2
10 20 30 40 50 
6 4
1 1 2 3 5 8 
2 2
1069 1122 
10 5
10386 10257 10432 10087 10381 10035 10167 10206 10347 10088 

Example output
Case #1: 30
Case #2: 400
Case #3: 103
Case #4: 1122
Case #5: 2621483

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define COMBSZ 10001
#define MOD 1000000007LL

typedef long long LL;
typedef vector<int> IntVec;

int main(int argc, char *argv[])
{
	// generate combination table
	static LL C[COMBSZ][COMBSZ];
	memset(C, 0, sizeof(C));
	int i, j;
	for (i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
	}
	for (i = 1; i < COMBSZ; ++i) {
		for (j = 1; j < COMBSZ; ++j) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}

	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		static LL v[10000];
		int N=0, K=0;
		getline(cin, s);
		stringstream sa(s);
		sa >> N >> K;
		getline(cin, s);
		stringstream sb(s);
		int i, j, k;
		for (i = 0; i < N; ++i) {
			sb >> v[i];
		}
		sort(v, v+N);

		LL ans = 0;
		while (N >= K) {
			ans = (ans + v[N-1] * C[N-1][K-1]) % MOD;
			--N;
		}

		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

