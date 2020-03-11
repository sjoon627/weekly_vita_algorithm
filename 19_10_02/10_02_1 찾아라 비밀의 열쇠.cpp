#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int bSearch(vector<int>& seq, int data) {
	int l = 0, r = seq.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (seq[mid] == data)
			return mid;
		else if (seq[mid] < data)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
int main() {
	int n, k, c, num, ans = 0;
	cin >> n >> k >> c;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];

	sort(seq.begin(), seq.end());

	for (int i = 0; i < k; ++i) {
		cin >> num;
		if (~bSearch(seq, num)) ++ans;
	}
	cout << (ans >= c ? "yes" : "no");
}
