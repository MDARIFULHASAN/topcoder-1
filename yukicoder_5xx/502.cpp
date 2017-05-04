#include <iostream>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	modll ans = 0;
	if (n < MOD) {
		const LL e[] = {1, 682498929,491101308,76479948,723816384,67347853,27368307,625544428,199888908,888050723,927880474,281863274,661224977,623534362,970055531,261384175,195888993,66404266,547665832,109838563,933245637,724691727,368925948,268838846,136026497,112390913,135498044,217544623,419363534,500780548,668123525,128487469,30977140,522049725,309058615,386027524,189239124,148528617,940567523,917084264,429277690,996164327,358655417,568392357,780072518,462639908,275105629,909210595,99199382,703397904,733333339,97830135,608823837,256141983,141827977,696628828,637939935,811575797,848924691,131772368,724464507,272814771,326159309,456152084,903466878,92255682,769795511,373745190,606241871,825871994,957939114,435887178,852304035,663307737,375297772,217598709,624148346,671734977,624500515,748510389,203191898,423951674,629786193,672850561,814362881,823845496,116667533,256473217,627655552,245795606,586445753,172114298,193781724,778983779,83868974,315103615,965785236,492741665,377329025,847549272,698611116};
		LL a = n / 10000000;
		ans = e[a];
		for (LL i = a * 10000000 + 1; i <= n; ++i) {
			ans *= i;
		}
	}
	cout << ans << endl;
	return 0;
}
