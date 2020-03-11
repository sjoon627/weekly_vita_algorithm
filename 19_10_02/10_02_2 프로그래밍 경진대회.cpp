#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll chk(vector<int>& seq, int mid) {
	ll sum = 0;
	for (int i = 0; i < seq.size(); ++i)
		sum += min(mid, seq[i]);
	return sum;
}
int main() {
	int n; cin >> n;
	vector<int> seq(n);
	int l = 0, r = 0, s;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		r = max(r, seq[i]);
		sum += seq[i];
	}
	cin >> s;
	if (s >= sum) {	//예외처리: 전체 인원의 합이 K보다 작은 경우
		cout << r; return 0;
	}
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(seq, mid) > s)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
}
