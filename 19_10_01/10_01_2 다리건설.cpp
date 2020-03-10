#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int d[1010];
int main() {
	int n; cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		d[i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (seq[i] > seq[j])
				d[i] = max(d[j] + 1, d[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, d[i]);
	cout << ans;
}

