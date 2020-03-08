#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		if (gcd(abs(a), abs(b)) == 1)
			++ans;
	}
	cout << ans;
}
