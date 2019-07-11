// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll & r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll & r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll & r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll & r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll & r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

LL n;
LL k;
modll ans;
vector<vector<int>> edges;
vector<int> vis;

void dfs(int node, int cnt) {
	vis[node] = 1;
	ans *= (k - cnt);
	cnt = cnt > 0;
	for (int next : edges[node]) {
		if (!vis[next]) {
			dfs(next, ++cnt);
		}
	}
}

int main(int argc, char *argv[]) {
	cin >> n >> k;
	edges.clear();
	edges.resize(n);
	vis = vector<int>(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	ans = 1;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
