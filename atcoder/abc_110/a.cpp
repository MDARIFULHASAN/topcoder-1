// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int ans = a[0] + a[1] + a[2] * 10;
	cout << ans << endl;
	return 0;
}
