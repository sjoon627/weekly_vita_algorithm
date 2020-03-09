#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n /= 2;
	}
	return res;
}
ll solve(int n, ll k, ll t) {
	ll res = ((n * ((pow(k, t) - 1 + mod) % mod) % mod) * pow(k - 1, mod - 2)) % mod;
	return res;
}
int main() {
	ll n, k, t; cin >> n >> k >> t;
	cout << solve(n, k, t);
	return 0;
}
