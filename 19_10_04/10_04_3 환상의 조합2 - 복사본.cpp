#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll d[1<<20][2];
int main() {
	int n; cin >> n;
	vector<int> seq(n + 1);
	int pref = 0;
	ll ans = 0;
	d[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
		pref ^= seq[i];
		ans += d[pref][i & 1];
		d[pref][i & 1]++;
	}
	cout << ans;
}
