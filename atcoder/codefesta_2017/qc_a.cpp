// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	bool ans = s.find("AC") != string::npos;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
