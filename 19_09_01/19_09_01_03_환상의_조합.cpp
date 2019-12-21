#include<iostream>
using namespace std;

int n, s, h, ans;
int seq[22];

int main() {
	cin >> n >> s >> h;
	for (int i = 0; i < n - 1; ++i)
		cin >> seq[i];
	for (int mask = (1 << (n - 1)) - 1; mask >= 0; --mask) {
		int sum = h;
		for (int j = 0; j < n - 1; ++j)
			if (mask & (1 << j))
				sum += seq[j];
		if (sum == s)
			++ans;
	}
	cout << ans;
}

/*#include<iostream>
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
}*/
