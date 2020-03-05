#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int seq[1010101];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	sort(seq, seq + n);
	ll ans = 0, tmp = 0;
	for (int i = 0; i < n; ++i) {
		ans += seq[i] + tmp;
		tmp += seq[i];
	}
	cout << ans;
}
