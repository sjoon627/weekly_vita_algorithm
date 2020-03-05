#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	int k; cin >> n >> k;
	ll box[33];
	for (int i = 0; i < k; ++i)
		cin >> box[i];
	ll ans = 0;
	for (int i = k - 1; i >= 0; --i) {
		ans += (n / box[i]);
		n %= box[i];
	}
	cout << ans;
}
