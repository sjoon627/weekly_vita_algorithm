#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(cin, str);

		string ans;
		for (int j = 0; str[j]; ++j)
			if (string("aeiou").find(str[j] | 32) != string::npos)
				ans.push_back(str[j]);

		if (ans.empty()) ans = "???";
		cout << ans << '\n';
	}

	return 0;
}
