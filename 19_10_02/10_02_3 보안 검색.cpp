#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll chk(vector<ll> & seq, ll mid) {
	ll res = 0;
	for (int i = 0; i < seq.size(); ++i)
		res += mid / seq[i];
	return res;
}
int main() {
	int n; ll k; cin >> n >> k;
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	ll l = 0, r = 1e15;
	ll ans = 1e15;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (chk(seq, mid) >= k) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans;
}
