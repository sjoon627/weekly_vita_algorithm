#include<iostream>
using namespace std;

int n, s, h, ans;
int seq[22];

void solve(int cur, int sum) {
	if (cur == n - 1) {
		ans += (sum == s);
		return;
	}
	solve(cur + 1, sum);
	solve(cur + 1, sum + seq[cur]);
}
int main() {
	cin >> n >> s >> h;
	for (int i = 0; i < n - 1; ++i)
		cin >> seq[i];
	solve(0, h);
	cout << ans;
}
